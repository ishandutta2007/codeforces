#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

set<int> s[N];
int set_adj[N];

void solve() {
  int n, m;
  cin >> n >> m;

  int cnt_adj = 0;
  vector<int> id(n);
  for (int i = 0; i < n; ++i) {
    cin >> id[i];
    id[i]--;
    s[id[i]].insert(i);
    if (i && id[i] == id[i - 1]) {
      ++cnt_adj;
      set_adj[id[i]]++;
    }
  }

  cout << n - cnt_adj - 1 << "\n";

  m--;
  while (m--) {
    int to, from;
    cin >> to >> from;
    --to, --from;

    int i = to;
    int j = from;
    if (s[i].size() < s[j].size()) {
      swap(i, j);
    }

    int new_cnt = set_adj[i];
    for (auto el: s[j]) {
      auto [it, _] = s[i].insert(el);
      auto nxt = next(it);
      if (nxt != s[i].end() && *nxt == el + 1) {
        new_cnt++;
      }
      if (it != s[i].begin()) {
        auto pr = prev(it);
        if (*pr == el - 1) {
          new_cnt++;
        }
      }
    }
    cnt_adj += (new_cnt - set_adj[j] - set_adj[i]);
    set_adj[i] = new_cnt;
    set_adj[j] = 0;

    if (i != to) {
      s[i].swap(s[j]);
      swap(set_adj[i], set_adj[j]);
    }
    cout << n - cnt_adj - 1 << "\n";
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