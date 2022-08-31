#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll MAX_K = 4e5 + 5;

class Fenwick {
  ull tree [MAX_K];

public:
  Fenwick () {
    for (int i = 0; i < MAX_K; i++) {
      tree[i] = 0;
    }
  }
  
  void add (ll idx, ull val) {
    for (ll i = idx; i < MAX_K; i += i & -i) {
      tree[i] ^= val;
    }
  }

  ull get (ll idx) {
    ull ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans ^= tree[i];
    }
    return ans;
  }

  ull range (ll l, ll r) {
    return get(r) ^ get(l);
  }
};

const int MAX_N = 1e5 + 5;

ll l [2][MAX_N], r [2][MAX_N];
ull hsh [MAX_N];
ull nhsh [2][MAX_N];

int main () {
  ios::sync_with_stdio(false);

  mt19937_64 rng (chrono::steady_clock::now().time_since_epoch().count());

  map<ll, int> compr;
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[0][i] >> r[0][i] >> l[1][i] >> r[1][i];
    hsh[i] = rng();

    for (int k = 0; k < 2; k++) {
      l[k][i] *= 2;
      r[k][i] *= 2;
      r[k][i]++;
    
      l[k][i] *= n;
      l[k][i] += i;
    
      r[k][i] *= n;
      r[k][i] += i;

      compr[l[k][i]] = 0;
      compr[r[k][i]] = 0;
    }
  }

  int cur = 1;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = cur;
    cur++;
  }

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < 2; k++) {
      l[k][i] = compr[l[k][i]];
      r[k][i] = compr[r[k][i]];
      // cout << l[k][i] << " " << r[k][i] << " ";
    }
    // cout << hsh[i] << endl;
  }

  for (int k = 0; k < 2; k++) {
    if (1) {
      ull chsh = 0;
      vector<pair<ll, int>> events;
      for (int i = 0; i < n; i++) {
        events.push_back({l[k][i], i});
        events.push_back({r[k][i], i});
      }

      sort(events.begin(), events.end());

      for (pair<ll, int> e : events) {
        int id = e.second;
        chsh ^= hsh[id];
        nhsh[k][id] ^= chsh;
      }
    }
    
    if (1) {
      vector<pair<ll, int>> events;
      for (int i = 0; i < n; i++) {
        events.push_back({l[k][i], i});
      }

      sort(events.begin(), events.end());

      Fenwick fenwick;
      for (pair<ll, int> e : events) {
        int id = e.second;
        nhsh[k][id] ^= fenwick.range(r[k][id], MAX_K - 1);
        fenwick.add(r[k][id], hsh[id]);
      }
    }

    if (1) {
      vector<pair<ll, int>> events;
      for (int i = 0; i < n; i++) {
        events.push_back({r[k][i], i});
      }

      sort(events.begin(), events.end());

      Fenwick fenwick;
      for (pair<ll, int> e : events) {
        int id = e.second;
        nhsh[k][id] ^= fenwick.range(l[k][id], MAX_K - 1);
        fenwick.add(l[k][id], hsh[id]);
      }
    }

    /*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (max(l[k][i], l[k][j]) <= min(r[k][i], r[k][j])) {
          nhsh[k][i] ^= hsh[j];
        }
      }

    }
  */
  }

  for (int i = 0; i < n; i++) {
    // cerr << nhsh[0][i] << " " << nhsh[1][i] << endl;
    if (nhsh[0][i] != nhsh[1][i]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}