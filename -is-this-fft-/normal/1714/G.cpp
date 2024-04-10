#include <iostream>

using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>,
  rb_tree_tag, tree_order_statistics_node_update>;

// cur.order_of_key(2)
// the number of elements in the set less than 2
// *cur.find_by_order(1)
// the 1-st smallest number in the set(0-based)

typedef long long ll;

const int MAX_N = 2e5 + 5;

vector<int> ch [MAX_N];
ll A [MAX_N];
ll B [MAX_N];
int ans [MAX_N];

void dfs (int u, ll Asum, ll Bsum, ordered_set<ll> &stk) {
  if (u != 1) {
    stk.insert(Bsum);
  }
  for (int nxt : ch[u]) {
    dfs(nxt, Asum + A[nxt], Bsum + B[nxt], stk);
  }
  if (u != 1) {
    ans[u] = stk.order_of_key(Asum + 1);
    stk.erase(Bsum);
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    ch[i].clear();
  }

  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p >> A[i] >> B[i];
    ch[p].push_back(i);
  }

  ordered_set<ll> stk;
  dfs(1, 0, 0, stk);
  for (int i = 2; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}