#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int maxn = 1e5;

vector<vector<int>> adj;

vector<vector<int>> divisors(maxn+2);
vector<int> mu(maxn+2, 0);

ll expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

pair<bool, bool> dfs(int v, int p, int k) {
  // return value: first is if edge orientation is valid so far, second is if
  // the edge to parent is used
  int children = 0;
  int degree = 0;
  for (int u: adj[v]) {
    if (u != p) {
      pair<bool, int> p = dfs(u, v, k);
      children++;
      if (!p.first) return {0, 0};
      if (!p.second) degree++;
    }
  }
  if (degree % k == 0) return {1, 0};
  else if (degree % k == k-1) return {1, 1};
  return {0, 0};
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for (int k = 2; k <= maxn; k++) {
    for (int j = k; j <= maxn; j += k) {
      divisors[j].push_back(k);
    }
  }
  mu[1] = 1;
  for (int k = 2; k <= maxn; k++) {
    int p = divisors[k][0];
    if (k/p % p != 0) {
      mu[k] = - mu[k/p];
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> answers(n);
    adj.resize(n);
    adj.clear();
    for (int i = 0; i < n-1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    answers[0] = expmod(2, n-1, MOD);
    for (int k: divisors[n-1]) {
      if (dfs(0, 0, k).first) {
        answers[0] += mu[k];
        for (int j: divisors[k]) {
          answers[j-1] += mu[k/j];
        }
      }
    }
    if (answers[0] < 0) answers[0] += MOD;
    for (int s: answers) {
      cout << s << " ";
    }
    cout << endl;
  }
}