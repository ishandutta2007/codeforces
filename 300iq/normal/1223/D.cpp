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
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <pair <int, int> > e;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      e.push_back({a[i], i});
    }
    sort(e.begin(), e.end());
    vector <int> r(n);
    for (int i = n - 1; i >= 0; i--) {
      r[i] = i;
      if (i + 1 < n && e[i + 1].second > e[i].second) {
        r[i] = r[i + 1];
      }
    }
    vector <int> suf(n);
    set <int> q;
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = q.size();
      q.insert(e[i].first);
    }
    vector <int> pref(n);
    q.clear();
    for (int i = 0; i < n; i++) {
      pref[i] = q.size();
      q.insert(e[i].first);
    }
    int ans = q.size();
    for (int i = 0; i < n; i++) {
      if (i == 0 || e[i].first != e[i - 1].first) {
        int go = r[i];
        ans = min(ans, pref[i] + suf[go]);
      }
    }
    cout << ans << '\n';
  }
}