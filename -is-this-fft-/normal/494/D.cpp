#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

struct modint {
  ll val;

  modint () {
    val = 0;
  }

  modint (ll _val) {
    val = _val;
  }
};

modint operator+ (modint p, modint q) {
  return modint((p.val + q.val) % MOD);
}

modint operator- (modint p, modint q) {
  return modint((p.val - q.val + MOD) % MOD);
}

modint operator- (modint p) {
  return modint(0) - p;
}

modint operator* (modint p, modint q) {
  return modint((p.val * q.val) % MOD);
}

modint operator^ (modint p, int q) {
  modint pows [30];

  pows[0] = p;
  for (int i = 1; i < 30; i++) {
    pows[i] = pows[i - 1] * pows[i - 1];
  }

  modint ans (1);
  for (int i = 0; i < 30; i++) {
    if (q & 1 << i) {
      ans = ans * pows[i];
    }
  }

  return ans;
}

modint operator/ (modint p, modint q) {
  return p * (q ^ (MOD - 2));
}

modint sq (modint x) {
  return x * x;
}

#include <vector>

const int MAX_N = 1e5 + 5;

int vertexc;
vector<pair<int, modint>> adj [MAX_N];

int sub_size [MAX_N];
modint sub_sumd [MAX_N];
modint sub_sumsq [MAX_N];

void build_subs (int vertex, int par) {
  sub_size[vertex] = 1;
  for (pair<int, modint> pr : adj[vertex]) {
    if (pr.first != par) {
      int nxt = pr.first;
      build_subs(nxt, vertex);

      sub_size[vertex] += sub_size[nxt];
      sub_sumd[vertex] = sub_sumd[vertex]
        + sub_size[nxt] * pr.second
        + sub_sumd[nxt];
      sub_sumsq[vertex] = sub_sumsq[vertex]
        + sub_size[nxt] * sq(pr.second)
        + 2 * pr.second * sub_sumd[nxt]
        + sub_sumsq[nxt];
    }
  }
}

modint sumd [MAX_N];
modint sumsq [MAX_N];
modint nxtsum [MAX_N];
modint nxtsq [MAX_N];

void build_sumsq (int vertex, int par, modint oversum, modint overh) {
  for (pair<int, modint> pr : adj[vertex]) {
    if (pr.first != par) {
      int nxt = pr.first;

      nxtsum[nxt] = sub_size[nxt] * pr.second
        + sub_sumd[nxt];

      oversum = oversum + nxtsum[nxt];

      nxtsq[nxt] = sub_size[nxt] * sq(pr.second)
        + 2 * pr.second * sub_sumd[nxt]
        + sub_sumsq[nxt];

      overh = overh + nxtsq[nxt];
    }
  }

  sumd[vertex] = oversum;
  sumsq[vertex] = overh;
  
  for (pair<int, modint> pr : adj[vertex]) {
    if (pr.first != par) {
      int nxt = pr.first;

      modint cur_sumd = oversum - nxtsum[nxt];
      modint new_oversum =
        (vertexc - sub_size[nxt]) * pr.second
        + cur_sumd;
      
      modint cur_sumsq = overh - nxtsq[nxt];
      modint new_overh =
        (vertexc - sub_size[nxt]) * sq(pr.second)
        + 2 * pr.second * cur_sumd
        + cur_sumsq;

      build_sumsq(nxt, vertex, new_oversum, new_overh);
    }
  }
}

const int MAX_LG = 19;

int lvl [MAX_N];
modint pot [MAX_N];
int jmp [MAX_N][MAX_LG];

void build_lca (int vertex, int par) {
  lvl[vertex] = lvl[par] + 1;
  jmp[vertex][0] = par;
  for (int i = 1; i < MAX_LG; i++) {
    jmp[vertex][i] = jmp[jmp[vertex][i - 1]][i - 1];
  }

  for (pair<int, modint> nxt : adj[vertex]) {
    if (nxt.first != par) {
      pot[nxt.first] = pot[vertex] + nxt.second;
      build_lca(nxt.first, vertex);
    }
  }
}

int lca (int p, int q) {
  if (p == q) return p;

  if (lvl[p] < lvl[q]) swap(p, q);

  int diff = lvl[p] - lvl[q];
  for (int i = 0; i < MAX_LG; i++) {
    if (diff & 1 << i) {
      p = jmp[p][i];
    }
  }

  if (p == q) return p;

  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (jmp[p][i] != jmp[q][i]) {
      p = jmp[p][i];
      q = jmp[q][i];
    }
  }

  return jmp[p][0];
}

modint dist (int p, int q) {
  int lc = lca(p, q);
  return pot[p] - pot[lc] + pot[q] - pot[lc];
}

modint query (int u, int v) {
  if (lca(u, v) == v) {
    modint duv = dist(u, v);
    modint outsv = sumsq[v] - sub_sumsq[v];
    modint sumoutside = (vertexc - sub_size[v]) * sq(duv)
      + 2 * duv * (sumd[v] - sub_sumd[v])
      + outsv;
    return sumsq[u] - 2 * sumoutside;
  } else {
    modint duv = dist(u, v);
    modint sumwithin = sub_size[v] * sq(duv)
      + 2 * duv * sub_sumd[v]
      + sub_sumsq[v];
    return 2 * sumwithin - sumsq[u];
  }
}

int main () {
  ios::sync_with_stdio(false);

  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  build_subs(1, 0);
  build_sumsq(1, 0, 0, 0);
  build_lca(1, 0);

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int u, v;
    cin >> u >> v;

    cout << query(u, v).val << '\n';
  }
}