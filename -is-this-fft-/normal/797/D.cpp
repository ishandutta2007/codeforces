#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;

int lft [MAX_N];
int rgt [MAX_N];
int val [MAX_N];

set<int> reaches;
void dfs (int u, pair<int, int> range) {
  if (range.first <= val[u] && val[u] <= range.second) {
    reaches.insert(val[u]);
  }

  if (lft[u] != -1) {
    dfs(lft[u], make_pair(range.first, min(range.second, val[u] - 1)));
  }

  if (rgt[u] != -1) {
    dfs(rgt[u], make_pair(max(range.first, val[u] + 1), range.second));
  }
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  set<int> roots;
  for (int i = 1; i <= n; i++) {
    roots.insert(i);
  }

  for (int i = 1; i <= n; i++) {
    cin >> val[i] >> lft[i] >> rgt[i];
    roots.erase(lft[i]);
    roots.erase(rgt[i]);
  }
  
  int root = *roots.begin();
  dfs(root, make_pair(0, 1e9 + 5));

  int ans = n;
  for (int i = 1; i <= n; i++) {
    if (reaches.count(val[i])) {
      ans--;
    }
  }

  cout << ans << endl;
}