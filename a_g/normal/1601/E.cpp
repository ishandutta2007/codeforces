#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+2;

template<typename T>
class minSparseTable {
  public:
    int n;
    int rows;
    vector<vector<pair<T, int>>> st;
    minSparseTable (vector<T> vals) {
      n = vals.size();
      rows = floor(log2(n))+1;
      for (int i = 0; i < n; i++) {
        st.push_back(vector<pair<T, int>>(rows));
      }
      for (int i = 0; i < n; i++) {
        st[i][0] = make_pair(vals[i], i);
      }
      for (int j = 1; j < rows; j++) {
        for (int i = 0; i + (1<<j) <= n; i++) {
          st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
      }
    }
    pair<T, int> query(int l, int r) {
      int j = 31-__builtin_clz(r-l+1);
      return min(st[l][j], st[r-(1<<j)+1][j]);
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q, k;
  cin >> n >> q >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b(n-k); // b[i] = min(a[i], ..., a[i+k])
  deque<int> que;
  for (int i = 0; i < n; i++) {
    while (!que.empty() && a[que.back()] >= a[i]) que.pop_back();
    while (!que.empty() && que.front() < i-k) que.pop_front();
    que.push_back(i);
    if (i >= k) b[i-k] = a[que.front()];
  }

  vector<vector<vector<pair<int, int>>>> queries(k, vector<vector<pair<int, int>>>(n/k+1));
  // (l mod k, l/k) -> list of (# pts, query id)
  vector<long long> ans(q);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    ans[i] += a[l];
    queries[l%k][l/k].push_back(make_pair((r-l)/k, i));
  }

  for (int i = 0; i < k; i++) {
    vector<int> c;
    for (int j = i; j < n-k; j += k) {
      c.push_back(b[j]);
    }
    int len = c.size();
    minSparseTable<int> mst(c);
    vector<long long> dp(len+1);
    vector<int> nxt(len, len);
    vector<int> stk;
    for (int j = len-1; j >= 0; j--) {
      while (!stk.empty() && c[stk.back()] >= c[j]) stk.pop_back();
      if (!stk.empty()) nxt[j] = stk.back();
      stk.push_back(j);
      dp[j] = 1LL*c[j]*(nxt[j]-j) + dp[nxt[j]];
    }

    for (int j = 0; j <= n/k; j++) {
      for (pair<int, int>& p: queries[i][j]) {
        int d = p.first;
        int qid = p.second;
        if (!d) continue;
        int v = mst.query(j, j+d-1).second;
        ans[qid] += dp[j]-dp[nxt[v]]-1LL*c[v]*(nxt[v]-(j+d));
      }
    }
  }


  for (long long val: ans) cout << val << '\n';
}