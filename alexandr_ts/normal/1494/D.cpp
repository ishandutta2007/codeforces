#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 510;

int a[N][N];
vector<pair<int, int>> edges;
int salary[N * N];
int cur_id;

int f(vector<int> ids) {
  if (ids.size() == 1) return ids[0];
  int mx = -INF;
  for (size_t i = 0; i < ids.size(); ++i) {
    for (size_t j = i + 1; j < ids.size(); ++j) {
      mx = max(mx, a[ids[i]][ids[j]]);
    }
  }
  vector<int> used(ids.size());
  vector<vector<int>> groups;
  for (size_t i = 0; i < ids.size(); ++i) {
    if (used[i]) continue;
    groups.push_back({});
    for (size_t j = i; j < ids.size(); ++j) {
      if (a[ids[i]][ids[j]] < mx) {
        groups.back().push_back(ids[j]);
        used[j] = true;
      }
    }
  }

  /*
  for (auto i: ids) cout << i << " ";cout << endl;
  cout << "mx: " << mx << ", groups - " << groups.size() << endl << endl;
  */

  vector<int> roots;
  for (auto& g: groups) {
    roots.push_back(f(g));
  }
  for (auto r: roots) {
    edges.push_back({r, cur_id});
  }

  salary[cur_id] = mx;
  cur_id++;
  return cur_id - 1;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
    salary[i] = a[i][i];
  }
  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 0);
  cur_id = n;
  int root = f(ids);
  cout << root + 1 << endl;
  for (int i = 0; i < root + 1; ++i) {
    cout << salary[i] << " ";
  }
  cout << "\n";
  cout << root + 1 << endl;
  for (auto e: edges) {
    cout << e.first + 1 << " " << e.second + 1 << "\n";
  }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}