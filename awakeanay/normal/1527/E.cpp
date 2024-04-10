#include <iostream>
#include <vector>

#define int long long

#define left (id+1)
#define mid ((l+r)/2)
#define right (id+2*(mid-l+1))

const int INF = 1000000000000000;

int n;

struct seg
{
  std::vector<int> tree, lazy;

  void push(int id, int l, int r) {
    if(lazy[id]) {
      tree[left] += lazy[id];
      tree[right] += lazy[id];
      lazy[left] += lazy[id];
      lazy[right] += lazy[id];
      lazy[id] = 0;
    }
  }

  int query(int x, int y, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return INF;

    if(x <= l && r <= y)
      return tree[id];

    push(id, l, r);
    return std::min(query(x, y, left, l, mid), query(x, y, right, mid+1, r));
  }

  void update(int x, int y, int val, int id = 0, int l = 0, int r = n-1) {
    if(y < l || r < x)
      return;

    if(x <= l && r <= y) {
      tree[id] += val;
      lazy[id] += val;
      return;
    }

    push(id, l, r);
    update(x, y, val, left, l, mid);
    update(x, y, val, right, mid+1, r);

    tree[id] = std::min(tree[left], tree[right]);
  }
};

signed main() {
  int k;
  std::cin >> n >> k;

  seg st;
  st.tree = std::vector<int>(2*n-1, INF);
  st.lazy = std::vector<int>(2*n-1, 0);

  std::vector<int> lval(n+1, -1), lid(n, -1);
  int arr[n];
  for(int i = 0; i < n; i++) {
    std::cin >> arr[i];
    lid[i] = lval[arr[i]];
    lval[arr[i]] = i;
  }

  int dp[n][k+1];

  int cur = 0;
  for(int i = 0; i < n; i++) {
    if(lid[i] != -1)
      cur += i-lid[i];
    dp[i][1] = cur;
  }

  for(int j = 2; j <= k; j++) {
    for(int i = 0; i < n; i++) {
      dp[i][j] = INF;
      if(lid[i] > 0) {
        st.update(0, lid[i]-1, i-lid[i]);
      }
      
      if(i) {
        dp[i][j] = st.query(0, i-1);
      }

      int cval = st.query(i, i);
      st.update(i, i, dp[i][j-1]-cval);
    }
  }

  std::cout << dp[n-1][k] << std::endl;

  return 0;
}