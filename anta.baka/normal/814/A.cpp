/*















*/

#include <bits/stdc++.h>

using namespace std;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  if(k > 1) return cout << "Yes", 0;
  int a[n];
  int pos;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] == 0) pos = i;
  }
  cin >> a[pos];
  for(int i = 1; i < n; i++) if(a[i - 1] > a[i]) return cout << "Yes", 0;
  cout << "No";
}