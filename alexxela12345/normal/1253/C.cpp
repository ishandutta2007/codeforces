#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef long double ldb;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >>  n;
  int m;
  cin >> m;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  vector<int> sum1(m);
  vector<int> sum2(m);
  int cur_ans = 0;
  for (int i = 0; i < n; i++) {
    cur_ans -= sum1[i % m];
    sum1[i % m] += arr[i];
    sum1[i % m] += sum2[i % m];
    cur_ans += sum1[i % m];
    sum2[i % m] += arr[i];
    cout << cur_ans << " ";
  }
  return 0;
}