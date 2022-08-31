#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e5;

int l[N], r[N];
int cnt[N];

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector <int> a(n);
  for (int i = 0; i < N; i++) l[i] = n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
    cnt[a[i]]++;
  }
  int mx = 0;
  set <int> q;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    q.insert(a[i]);
    mx = max(mx, r[a[i]]);
    if (mx <= i) {
      int f = 0;
      int g = 0;
      for (int t : q) {
        f = max(f, cnt[t]);
        g += cnt[t];
      }
      sum += g - f;
      q.clear();
      mx = 0;
    }
  }
  cout << sum << endl;
}