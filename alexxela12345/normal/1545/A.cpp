#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

typedef long long ll;
typedef long double ldb;

void solve() {
  int n;
  cin >> n;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (i % 2 == 0) {
      a.push_back(x);
    } else {
      b.push_back(x);
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> arr(n);
  for (int i = 0; i < (int) a.size(); i++) {
    arr[2 * i] = a[i];
  }
  for (int i = 0; i < (int) b.size(); i++) {
    arr[2 * i + 1] = b[i];
  }
  auto arr2 = arr;
  sort(arr2.begin(), arr2.end());
  if (arr == arr2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}