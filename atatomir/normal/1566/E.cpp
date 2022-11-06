#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

//#define debug(x) ;
#define debug(x) cerr << #x << " = " << x << "\n";

ostream& operator<<(ostream& cerr, vector<ll> aux) {
  cerr << "[";
  for (auto e : aux) cerr << e << ' ';
  cerr << "]";
  return cerr;
}

const int maxN = 200011;

int t, n, x, y;
vector<int> adj[maxN];
int answer;

bool dfs(int node, int parent) {
  int sons = 0;

  for (auto to: adj[node]) {
    if (to == parent) continue;
    if (dfs(to, node))
      sons++;
  }

  if (sons > 0) {
    answer += sons - 1;
    return false;
  } else {
    return true;
  }
}

void solve_test() {
  cin >> n;
  for (int i = 1; i <= n; i++) adj[i].clear();

  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }

  answer = 0;
  dfs(1, 0);
  cout << answer + 1 << '\n';
}

int main()
{
  //freopen("test.in", "r", stdin);

  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    solve_test();
  }

  return 0;
}