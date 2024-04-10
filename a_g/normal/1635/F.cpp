#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+3;
const long long INF = 5e18;
long long ans[N];
int L[N], R[N];
int x[N], w[N];
vector<pair<int, int>> queries[N];
vector<pair<int, long long>> vals[N];

template<typename T>
class fenwick {
  public:
    vector<T> arr;
    fenwick (int n) {
      arr.resize(n+3, INF);
    }
    void add (int index, T val) {
      for (; index < arr.size(); index += (index & (-index))) {
        arr[index] = min(arr[index], val);
      }
    }
    T query(int index) {
      T ans = INF;
      for (; index > 0; index -= (index & (-index))) {
        ans = min(ans, arr[index]);
      }
      return ans;
    }
};

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> w[i];
  }
  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && w[stk.top()] > w[i]) {
      stk.pop();
    }
    if (!stk.empty()) {
      L[i] = stk.top();
    }
    stk.push(i);
  }
  stk = stack<int>();
  for (int i = n; i >= 1; i--) {
    while (!stk.empty() && w[stk.top()] > w[i]) {
      stk.pop();
    }
    if (!stk.empty()) {
      R[i] = stk.top();
    }
    stk.push(i);
  }

  auto insertvals = [&](int l, int r) {
    if (!l || !r) return;
    vals[l].emplace_back(r, 1LL*(x[r]-x[l])*(w[r]+w[l]));
  };

  for (int i = 1; i <= n; i++) {
    insertvals(L[i], i);
    insertvals(i, R[i]);
  }

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries[l].push_back(make_pair(i, r));
  }

  fenwick<long long> fenw(n);

  for (int l = n; l >= 1; l--) {
    for (pair<int, long long>& p: vals[l]) {
      fenw.add(p.first, p.second);
    }
    for (pair<int, int>& p: queries[l]) {
      ans[p.first] = fenw.query(p.second);
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
}