#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];
int b[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) swap(a[i], b[i]);
    }
    cout << *max_element(a, a+n) * *max_element(b, b+n) << '\n';
  }
}