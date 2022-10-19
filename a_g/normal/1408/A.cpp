#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N], b[N], c[N];
int p[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    p[0] = a[0];
    for (int i = 1; i < n-1; i++) {
      if (a[i] == p[i-1]) p[i] = b[i];
      else p[i] = a[i];
    }
    if (a[n-1] == p[n-2] || a[n-1] == p[0]) {
      if (b[n-1] == p[n-2] || b[n-1] == p[0]) {
        p[n-1] = c[n-1];
      }
      else p[n-1] = b[n-1];
    }
    else p[n-1] = a[n-1];
    for (int i = 0; i < n; i++) {
      cout << p[i] << ' ';
    }
    cout << '\n';
  }
}