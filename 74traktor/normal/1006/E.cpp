#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<vector<int>> tree;

int current_preorder;
vector<int> preorder, max_preorder;
vector<int> sorted_by_preorder;

void Dfs(int w) {
  sorted_by_preorder[current_preorder] = w;
  preorder[w] = current_preorder++;
  for (int c : tree[w]) {
    Dfs(c);
  }
  max_preorder[w] = current_preorder - 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  assert(2 <= n);
  assert(1 <= q);
  tree.resize(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    assert(0 <= p and p < n);
    tree[p].push_back(i);
  }

  preorder.resize(n);
  max_preorder.resize(n);
  sorted_by_preorder.resize(n);
  current_preorder = 0;
  Dfs(0);

  for (int i = 0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    u--; k--;
    assert(0 <= u and u < n);
    assert(0 <= k and k < n);
    k += preorder[u];
    int answer = -1;
    if (k <= max_preorder[u]) {
      answer = sorted_by_preorder[k] + 1;
      assert(1 <= answer and answer <= n);
    }
    cout << answer << '\n';
  }
  return 0;
}