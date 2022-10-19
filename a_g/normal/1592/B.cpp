#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b.begin(), b.end());
    bool good = 1;
    for (int i = n-x; i <= x-1; i++) {
      if (a[i] != b[i]) good = 0;
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}