#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#ifndef LOCAL
#define endl '\n'
#endif

//#define int long long

#define sz(v) ((int)(v).size())
//#define all(x) (x).begin(),(x).end()

vector<int> cur;
vector<vector<int>> all;

void genAll(int n) {
  if (n == 0) {
    all.push_back(cur);
    return;
  }
  cur.push_back(0);
  genAll(n - 1);
  cur.back() = 1;
  genAll(n - 1);
  cur.back() = -1;
  genAll(n - 1);
  cur.pop_back();
}

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  all.clear();
  genAll(n);
  for (auto &el : all) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += el[i] * arr[i];
    }
    for (int i = 0; i < n; i++) {
      if (el[i] == 0 && sum == arr[i]) {
	cout << "YES" << endl;
	return;
      }
    }
  }
  cout << "NO" << endl;
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