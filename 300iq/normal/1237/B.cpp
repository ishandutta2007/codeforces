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
  int n;
  cin >> n;
  vector <int> a(n);
  vector <int> ind(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    ind[a[i]] = i;
  }
  int mx = n;
  int ans = 0;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  reverse(arr.begin(), arr.end());
  for (int b : arr) {
    b--;
    if (ind[b] > mx) {
      ans++;
    }
    mx = min(mx, ind[b]);
  }
  cout << ans << endl;
}