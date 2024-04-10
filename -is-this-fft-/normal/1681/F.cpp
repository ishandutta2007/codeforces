#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Subtree {
  int glob_add;
  map<int, int> cnt;

public:
  Subtree () : glob_add(0), cnt() {
  }

  int get (int x) {
    return cnt[x] + glob_add;
  }

  void reset (int x) {
    cnt[x] = -glob_add;
  }

  void increase () {
    glob_add++;
  }

  void subsume (Subtree *oth) {
    for (auto it = oth->cnt.begin(); it != oth->cnt.end(); it++) {
      cnt[it->first] += it->second;
    }

    glob_add += oth->glob_add;
  }
};

class Stack {
  vector<int> last;
  vector<pair<int, int>> stk; // value, value old last
  
public:
  Stack (int _n) : last(_n + 1, 0) {
  }
  
  void push (int idx, int value) {
    stk.push_back({value, last[value]});
    last[value] = idx;
  }

  void pop () {
    last[stk.back().first] = stk.back().second;
    stk.pop_back();
  }
  
  int get_last (int value) {
    return last[value];
  }
};

const int MAX_N = 5e5 + 5;

vector<pair<int, int>> adj [MAX_N];
int sz [MAX_N];
Subtree* subs [MAX_N];

int dn [MAX_N];

void build_dn (int u, int e, int p) {
  sz[u] = 1;

  pair<int, int> bigcpr = make_pair(-1, -1);
  for (auto pr : adj[u]) {
    int nxt = pr.first;
    if (nxt != p) {
      build_dn(nxt, pr.second, u);
      sz[u] += sz[nxt];
      bigcpr = max(bigcpr, make_pair(sz[nxt], nxt));
    }
  }

  int bigc = bigcpr.second;
  if (bigc == -1) {
    subs[u] = new Subtree();
  } else {
    subs[u] = subs[bigc];
  }

  for (auto pr : adj[u]) {
    int nxt = pr.first;
    if (nxt != p && nxt != bigc) {
      subs[u]->subsume(subs[nxt]);
      delete subs[nxt];
    }
  }

  subs[u]->increase();
  dn[u] = subs[u]->get(e);
  subs[u]->reset(e);
}

typedef long long ll;

void solve (int u, int e, int p, Stack &stk, ll &ans) {
  if (u != 1) {
    int last = stk.get_last(e);
    int up;
    if (last == 0) {
      up = subs[1]->get(e);
    } else {
      up = dn[last];
    }

    ans += (ll) up * (ll) dn[u];
  }

  stk.push(u, e);

  for (auto pr : adj[u]) {
    int nxt = pr.first;
    if (nxt != p) {
      solve(nxt, pr.second, u, stk, ans);
    }
  }
  
  stk.pop();
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  build_dn(1, 0, 0);
  ll ans = 0;
  Stack stk (n);
  solve(1, 0, 0, stk, ans);

  cout << ans << endl;
}