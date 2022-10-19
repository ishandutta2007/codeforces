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
  int n, k;
  cin >> n >> k;
  vector<int> used(2 * n);
  vector<pair<int, int>> arr(k);
  for (int i = 0; i < k; i++) {
    cin >> arr[i].first >> arr[i].second;
    arr[i].first--;
    arr[i].second--;
    used[arr[i].first] = 1;
    used[arr[i].second] = 1;
  }
  vector<int> un;
  for (int i = 0; i < 2 * n; i++) {
    if (!used[i])
      un.push_back(i);
  }
  for (int i = 0; i < (n - k); i++) {
    arr.push_back({un[i], un[i + (n - k)]});
  }

  auto contains = [&](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first && a.second < b.second && b.first < a.second;
  };
  
  for (auto &el : arr) {
    if (el.first > el.second)
      swap(el.first, el.second);
  }
  sort(arr.begin(), arr.end());
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (contains(arr[j], arr[i])) {
	//cout << arr[j].first << " " << arr[j].second << " " << arr[i].first << " " << arr[i].second << endl;
	ans++;
      }
    }
  }
  cout << ans << endl;
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