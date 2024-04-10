#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+7;
int a[N];
ll b[N];

bool solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool done = 1;
  b[0] = 0;
  for (int i = 0; i < n; i++) {
    b[i+1] = a[i] - b[i];
    if (b[i+1] < 0) done = 0;
  }
  if (b[n] != 0) done = 0;
  if (done) return 1;
  if (b[n]&1) return 0;
  
  ll d = b[n]/2;

  int l = 0;
  int r = n-2;
  for (int i = n-1; i > 0; i--) {
    ll c = ((n-i)&1 ? d : -d);
    if (b[i] < 0 && b[i] + 2*c < 0) return 0;
    if (b[i] < 0) {
      r = min(r, i-1);
      if (b[i] + c < 0) {
        r = min(r, i-2);
      }
    }
    if (b[i] + 2*c < 0) {
      l = max(l, i-1);
      if (b[i] + c < 0) {
        l = max(l, i);
      }
    }
  }
  /*
  for (int i = 0; i <= n; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
  cout << l << " " << r << endl;
  */
  for (int i = l; i <= r; i++) {
    int sign = ((n-i)&1 ? -1 : 1);
    if (sign * (a[i+1] - a[i]) == d) return 1;
  }
  return 0;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}