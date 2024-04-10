#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 1e6 + 10;

pair<int, int> dir(char c) {
  if (c == 'L') return {-1, 0};
  if (c == 'R') return {1, 0};
  if (c == 'U') return {0, 1};
  return {0, -1};
}

bool check(pair<int, int> ob, const string& s) {
  int n = s.size();

  pair<int, int> cur = {0, 0};
  for (int i = 0; i < n; ++i) {
    auto d = dir(s[i]);
    pair<int, int> nxt = {cur.first + d.first, cur.second + d.second};
    if (nxt != ob) {
      cur = nxt;
    }
  } 
  return cur.first == 0 && cur.second == 0;
} 

void solve() {
  string s;
  cin >> s;
  int n = s.size();

  vector<pair<int, int>> v;
  pair<int, int> cur = {0, 0};
  for (int i = 0; i < n; ++i) {
    auto d = dir(s[i]);
    cur.first += d.first;
    cur.second += d.second;
    v.push_back(cur);
  }

  for (int i = 0; i < n; ++i) {
    if (check(v[i], s)) {
      cout << v[i].first << " " << v[i].second << "\n";
      return;
    }
  }
  cout << "0 0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
  cin >> t;
	while (t--) {
		solve();
	}
}