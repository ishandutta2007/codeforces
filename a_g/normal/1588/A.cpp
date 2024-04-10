#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool win = 1;
    for (int i = 0; i < n; i++) {
      if (b[i] - a[i] < 0 || b[i]-a[i] > 1) win = 0;
    }
    cout << (win ? "YES" : "NO") << endl;
  }
}