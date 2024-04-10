#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i;
  cin >> n >> i;
  map <int, int> cnt;
  int rz = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    rz++;
  }
  vector <int> guys;
  for (auto c : cnt) {
    guys.push_back(c.second);
  }
  set <pair <int, int> > q;
  int flex = 0;
  vector <int> suf(guys.size() + 1);
  for (int i = (int) guys.size() - 1; i >= -1; i--) {
    suf[(int) guys.size() - 1 - i] = flex;
    if (i != -1)
      flex += guys[i];
  }
  for (int k = 20; k >= 0; k--) {
    if (k * (ll) n <= 8 * i) {
      int rz = (1 << k);
      int need_die = cnt.size() - rz;
      need_die = max(0, need_die);
      int s = 0;
      int ans = 1e9;
      for (int i = 0; i <= (int) guys.size(); i++) {
        if (need_die - i >= 0)
          ans = min(ans, s + suf[need_die - i]);
        if (i != (int) guys.size()) {
          s += guys[i];
        }
      }
      if (ans != 1e9) {
        cout << ans << endl;
        return 0;
      }
    }
  }
}