#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2*n);
  for (int i = 0; i < 2*n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < 2*n; i += 2) {
    int b = a[i];
    for (int j = i+1; j < 2*n; j++) {
      if (a[j] == b) {
        ans += j-i-1;
        rotate(a.begin() + i, a.begin() + j, a.begin()+j+1);
        break;
      }
    }
  }
  cout << ans << endl;
}