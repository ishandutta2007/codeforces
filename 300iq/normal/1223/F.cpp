#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#ifdef iq
  mt19937_64 rnd(228);
#else
  mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 3e5 + 7;

ll h[N], g[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < N; i++) {
    h[i] = rnd();
    g[i] = rnd();
  }
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    ll ans = 0;
    function <void(int, int)> rec = [&] (int l, int r) {
      if (r - l == 1) {
        return;
      } else {
        int m = (l + r) / 2;
        vector <int> st;
        map <ll, int> cnt;
        ll sum = 0;
        for (int i = m; i < r; i++) {
          if (st.empty() || st.back() != a[i]) {
            sum += h[st.size()] * g[a[i]];
            st.push_back(a[i]);
          } else {
            sum -= h[st.size() - 1] * g[st.back()];
            st.pop_back();
          }
          cnt[sum]++;
        }
        st.clear();
        sum = 0;
        for (int i = m - 1; i >= l; i--) {
          if (st.empty() || st.back() != a[i]) {
            sum += h[st.size()] * g[a[i]];
            st.push_back(a[i]);
          } else {
            sum -= h[st.size() - 1] * g[st.back()];
            st.pop_back();
          }
          ans += cnt[sum];
        }
        rec(l, m);
        rec(m, r);
      }
    };
    rec(0, n);
    cout << ans << '\n';
  }
}