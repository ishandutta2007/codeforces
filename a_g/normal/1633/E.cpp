#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edges;
vector<tuple<int, int, int, int, long long>> answers;
int n;

const int N = 1e8+5;

class dsu {
  public:
    vector<int> parents;
    vector<int> ranks;
    dsu (int n) {
      parents.resize(n);
      iota(parents.begin(), parents.end(), 0);
      ranks.resize(n, 0);
    }
    int root(int u) {
      return parents[u] == u ? u : parents[u] = root(parents[u]);
    }
    bool join(int u, int v) {
      int a = root(u);
      int b = root(v);
      if (a == b) return 0;
      parents[a] = b;
      if (ranks[a] == ranks[b]) ranks[b]++;
      return 1;
    }
};

void calc(int x) {
  dsu d(n);
  sort(edges.begin(), edges.end(),
      [&](tuple<int, int, int>& a, tuple<int, int, int>& b) {
      if (abs(get<0>(a)-x) != abs(get<0>(b)-x)) return abs(get<0>(a)-x) < abs(get<0>(b)-x);
      return a < b;
      });
  int upper = N;
  int lower = 0;
  long long b = 0;
  int a = 0;
  for (tuple<int, int, int> e: edges) {
    if (d.join(get<1>(e), get<2>(e))) {
      if (get<0>(e) >= x) {
        upper = min(upper, get<0>(e));
        b += get<0>(e);
        a--;
      }
      else {
        lower = max(lower, get<0>(e));
        b -= get<0>(e);
        a++;
      }
    }
  }
  answers.push_back(make_tuple(x, lower, upper, a, b));
  return;
}

long long query(int x) {
  long long ans = 1e18;
  int i = lower_bound(answers.begin(), answers.end(), make_tuple(x, -1, 0, 0, 0))-answers.begin();
  for (int u: {i, i-1}) {
    if (i >= 0 && get<1>(answers[i]) <= x && x <= get<2>(answers[i])) {
      ans = min(ans, 1LL*get<3>(answers[i])*x+get<4>(answers[i]));
    }
  }
  return ans;
}


int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> n >> m;
  set<int> vals;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(make_tuple(w, u-1, v-1));
    vals.insert(w);
  }

  for (int i = 0; i < m; i++) {
    for (int j = i+1; j < m; j++) {
      int s = get<0>(edges[i])+get<0>(edges[j]);
      vals.insert(s/2);
    }
  }
  vals.insert(N);
  for (int x: vals) calc(x);

  int p, k, a, b, c;
  cin >> p >> k >> a >> b >> c;
  int q;
  k -= p;
  long long ans = 0;
  while (p--) {
    cin >> q;
    ans ^= query(q);
  }
  while (k--) {
    q = (1LL * q * a + b) % c;
    ans ^= query(q);
  }
  cout << ans << '\n';
}