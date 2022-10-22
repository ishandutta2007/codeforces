#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

struct Lin {
  ll a, b;

  ll operator() (ll x) {
    return a * x + b;
  }
};

struct PolyLin {
  int len;
  map<int, Lin> segs;

  PolyLin (int _len) : len(_len) {
    segs[0] = Lin {.a = 0, .b = 0};
  }
  
  void insert (int l, int r, Lin lin) {
    vector<int> to_del;
    Lin after;
    bool need_after = true;
    if (r == len) {
      need_after = false;
    }
    if (segs.lower_bound(r) != segs.end() && segs.lower_bound(r)->first == r) {
      need_after = false;
    }

    for (auto it = segs.lower_bound(l); it->first < r && it != segs.end(); it++) {
      if (next(it) == segs.end()) {
        if (r != len) {
          after = it->second;
        }
      } else if (next(it)->first == r) {
        need_after = false;
      } else if (next(it)->first > r) {
        after = it->second;
      }

      to_del.push_back(it->first);
    }

    if (to_del.empty()) {
      after = prev(segs.lower_bound(l))->second;
    }

    for (auto x : to_del) {
      segs.erase(x);
    }

    segs[l] = lin;
    if (need_after) {
      segs[r] = after;
    }
  }

  ll operator() (ll x) {
    return prev(segs.upper_bound(x))->second(x);
  }

  ll glomin () {
    ll ans = 1e18;
    for (auto it = segs.begin(); it != segs.end(); it++) {
      int l = it->first;
      int r = next(it) == segs.end() ? len - 1 : next(it)->first - 1;

      ans = min(ans, it->second(l));
      ans = min(ans, it->second(r));
    }
    return ans;
  }
};

const int MAX_N = 2e5 + 5;

ll ds [MAX_N];
ll sta [MAX_N], fin [MAX_N]; // starts and ends being red

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, T;
  cin >> n >> T;

  for (int i = 0; i < n; i++) {
    int g, c;
    cin >> g >> c;

    sta[i] = g - c;
    fin[i] = T - c;
  }

  for (int i = 1; i < n; i++) {
    cin >> ds[i];
    ds[i] += ds[i - 1];
  }

  for (int i = 0; i < n; i++) {
    sta[i] -= ds[i];
    fin[i] -= ds[i];

    sta[i] %= T;
    if (sta[i] < 0) sta[i] += T;
    fin[i] %= T;
    if (fin[i] < 0) fin[i] += T;
  }

  PolyLin poly (T);
  for (int i = n - 1; i >= 0; i--) {
    ll aft = poly(fin[i]);
    if (fin[i] < sta[i]) {
      if (fin[i] != 0) poly.insert(0, fin[i], Lin {.a = -1, .b = aft + fin[i]});
      poly.insert(sta[i], T, Lin {.a = -1, .b = T + aft + fin[i]});
    } else {
      poly.insert(sta[i], fin[i], Lin {.a = -1, .b = aft + fin[i]});
    }
  }
  
  cout << poly.glomin() + ds[n - 1] << '\n';
}