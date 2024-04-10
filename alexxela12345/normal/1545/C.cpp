#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

typedef long long ll;
typedef long double ldb;

const int MOD = 998244353;

int mul(int a, int b) { return 1LL * a * b % MOD; }

int n;
vector<vector<int>> arr;
vector<vector<int>> g;

int m;
vector<int> used;

int neg(int i) { return (i + m) % (2 * m); }

bool isbad(int i, int j) {
  for (int k = 0; k < n; k++) {
    if (arr[i][k] == arr[j][k]) {
      return true;
    }
  }
  return false;
}

int cur_time;
vector<int> tin;

void dfs(int v) {
  used[v] = 1;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  tin[v] = cur_time++;
}

void solve() {
  used.clear();
  cur_time = 0;
  tin.clear();
  arr.clear();
  g.clear();
  cin >> n;
  arr.resize(2 * n, vector<int>(n));
  for (int i = 0; i < 2 * n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      arr[i][j]--;
    }
  }
  int ans2 = 1;
  vector<int> ans;
  {
    vector<vector<int>> arr2 = arr;
    while (!arr2.empty()) {
      int pos = -1;
      for (int j = 0; j < n; j++) {
	vector<int> cnt(n);
	for (auto &el : arr2) {
	  cnt[el[j]]++;
	}
	for (auto &el : cnt)
	  if (el == 0)
	    el = 1e9;
	auto it = min_element(cnt.begin(), cnt.end());
        if (*it == 1) {
	  pos = 0;
          while (arr2[pos][j] != it - cnt.begin()) {
            pos++;
          }
          break;
        }
      }
      if (pos == -1) {
	pos = 0;
	ans2 = mul(ans2, 2);
      }
      auto el = arr2[pos];
      {
        int pos2 = 0;
        while (arr[pos2] != el)
          pos2++;
        ans.push_back(pos2);
      }
      arr2.erase(arr2.begin() + pos);
      vector<vector<int>> arr3;
      for (auto el2 : arr2) {
	bool good = 1;
	for (int i = 0; i < n; i++) {
          if (el[i] == el2[i]) {
            good = 0;
	    break;
          }
        }
	if (!good)
	  continue;
	arr3.push_back(el2);
      }
      arr2 = arr3;
    }
  }
  cout << ans2 << endl;
  sort(ans.begin(), ans.end());
  for (int el : ans) {
    cout << el + 1 << " ";
  }
  cout << endl;

  assert((int) ans.size() == n);
  for (int el : ans) {
    for (int el2 : ans) {
      if (el == el2)
	break;
      assert(!isbad(el, el2));
    }
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