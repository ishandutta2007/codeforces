#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = max(0, a[i]-i+n-1)/n;
  }
  int m = *min_element(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    if (b[i] == m) {
      cout << i+1 << endl;
      return 0;
    }
  }
}