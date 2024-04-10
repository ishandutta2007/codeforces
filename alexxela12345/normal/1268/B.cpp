#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i = 0; i < n; i++) {
    cnt1 += arr[i] /  2;
    cnt2 += arr[i] - arr[i] / 2;
    swap(cnt1, cnt2);
  }
  cout << min(cnt1, cnt2) << endl;
}