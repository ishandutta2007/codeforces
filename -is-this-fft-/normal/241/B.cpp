#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_LG = 30;
const int MAX_N = 4e5 + 5;
const int MOD = 1e9 + 7;

int length;
int arr [MAX_N];

ll n_pref (int prefix, int sufflen) {
  map<int, int> cnt;
  for (int i = 0; i < length; i++) {
    int curp = arr[i] >> sufflen;
    if (cnt.find(curp) == cnt.end()) {
      cnt[curp] = 0;
    }
    cnt[curp]++;
  }

  ll ans = 0;
  for (auto it = cnt.begin(); it != cnt.end(); it++) {
    int curp = it->first;
    int comp = curp ^ prefix;
    if (cnt.find(comp) != cnt.end()) {
      ans += (ll) cnt[comp] * (ll) it->second;
    }
  }
  
  if (prefix == 0) {
    ans -= length;
  }
  return ans / 2;
}

ll sum_pref (int prefix, int sufflen) {
  map<int, int> compr;
  for (int i = 0; i < length; i++) {
    int curp = arr[i] >> sufflen;
    compr[curp] = 0;
    compr[curp ^ prefix] = 0;
  }

  vector<int> bigs;
  for (auto it = compr.begin(); it != compr.end(); it++) {
    it->second = (int) bigs.size();
    bigs.push_back(it->first);
  }

  vector<vector<int>> inst ((int) bigs.size(), vector<int> (0));
  for (int i = 0; i < length; i++) {
    inst[compr[arr[i] >> sufflen]].push_back(arr[i]);
  }

  ll ans = 0;
  for (int a : bigs) {
    int b = a ^ prefix;
    int aid = compr[a];
    int bid = compr[b];

    if (a > b) continue;

    vector<ll> cnta (MAX_LG, 0);
    for (int u : inst[aid]) {
      for (int k = 0; k < MAX_LG; k++) {
        if (u & 1 << k) {
          cnta[k]++;
        }
      }
    }

    vector<ll> cntb (MAX_LG, 0);
    for (int u : inst[bid]) {
      for (int k = 0; k < MAX_LG; k++) {
        if (u & 1 << k) {
          cntb[k]++;
        }
      }
    }

    ll add = 0;
    for (int k = 0; k < MAX_LG; k++) {
      add += cnta[k] * ((ll) inst[bid].size() - cntb[k]) * (1LL << k);
      add += cntb[k] * ((ll) inst[aid].size() - cnta[k]) * (1LL << k);
    }

    if (a == b) {
      add /= 2;
    }

    ans += add;
  }

  return ans;
}

int main () {
  ios::sync_with_stdio(false);

  ll target;
  cin >> length >> target;

  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }

  int cur_pref = 0;
  ll ans = 0;
  for (int k = MAX_LG - 1; k >= 0; k--) {
    cur_pref *= 2;
    ll cb = n_pref(cur_pref + 1, k);
    if (k == 0) {
      if (target - cb >= 0) {
        target -= cb;
        ans += sum_pref(cur_pref + 1, k);
        ans += target * (ll) cur_pref;
      } else {
        ans += target * (ll) (cur_pref + 1);
      }
    } else {
      if (target - cb >= 0) {
        target -= cb;
        ans += sum_pref(cur_pref + 1, k);
      } else {
        cur_pref++;
      }
    }
  }

  cout << ans % MOD << endl;
}