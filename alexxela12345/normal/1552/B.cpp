#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#ifndef LOCAL
#define endl '\n'
#endif

//#define int long long

#define sz(v) ((int)(v).size())
#define all(x) (x).begin(),(x).end()

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> arr(n, vector<int> (5));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }

  auto cmp = [&](int a, int b) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
      if (arr[a][i] < arr[b][i]) {
	cnt++;
      }
    }
    return cnt >= 3;
  };
  
  int a = 0;
  for (int i = 1; i < n; i++) {
    if (cmp(i, a)) {
      a = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != a) {
      if (cmp(i, a)) {
	cout << -1 << endl;
	return;
      }
    }
  }
  cout << a + 1 << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}