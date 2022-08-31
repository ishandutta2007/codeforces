#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef long long ll;

const int MAX_N = 100005;
const int MAX_LG = 18;

vector<int> adj [MAX_N];
int lvl [MAX_N];
int jmp [MAX_N][MAX_LG];
int ord [MAX_N];
int rord [MAX_N];

int cur;
void build (int vertex, int parent) {
  cur++;
  ord[vertex] = cur;
  lvl[vertex] = lvl[parent] + 1;
  jmp[vertex][0] = parent;
  for (int i = 1; i < MAX_LG; i++) {
    jmp[vertex][i] = jmp[jmp[vertex][i - 1]][i - 1];
  }

  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      build(nxt, vertex);
    }
  }
  rord[vertex] = cur;
}

int anc_at (int p, int d) {
  for (int i = 0; i < MAX_LG; i++) {
    if (d & 1 << i) {
      p = jmp[p][i];
    }
  }
  return p;
}

int lca (int p, int q) {
  if (lvl[p] < lvl[q]) {
    swap(p, q);
  }

  int diff = lvl[p] - lvl[q];
  p = anc_at(p, diff);
  if (p == q) {
    return p;
  }

  for (int i = MAX_LG - 1; i >= 0; i--) {
    if (jmp[p][i] != jmp[q][i]) {
      p = jmp[p][i];
      q = jmp[q][i];
    }
  }
  return jmp[p][0];
}

bool by_ord (int p, int q) {
  return ord[p] < ord[q];
}

int qid;
int in_cur [MAX_N];
int in_virt [MAX_N];
vector<int> virt_ch [MAX_N];
int dp0 [MAX_N];
int dp1 [MAX_N];

void solve (int vertexc) {
  qid++;

  int specc;
  cin >> specc;

  vector<int> specs (specc);
  for (int i = 0; i < specc; i++) {
    cin >> specs[i];
    in_cur[specs[i]] = qid;
    in_virt[specs[i]] = qid;
  }

  for (int u : specs) {
    if (in_cur[jmp[u][0]] == qid && u != 1) {
      cout << -1 << '\n';
      return;
    }
  }

  sort(specs.begin(), specs.end(), by_ord);
  vector<int> virtuals;
  for (int i = 0; i < specc; i++) {
    virtuals.push_back(specs[i]);
  }
  
  for (int i = 0; i < specc - 1; i++) {
    int u = specs[i];
    int v = specs[i + 1];
    int lc = lca(specs[i], specs[i + 1]);
    if (in_virt[lc] != qid) {
      in_virt[lc] = qid;
      virtuals.push_back(lc);
    }

    if (in_cur[lc]) {
      for (int k = 0; k < 2; k++) {
        int du = lvl[u] - lvl[lc];
        if (du != 0) {
          int anc = anc_at(u, du - 1);
          if (in_virt[anc] != qid) {
            in_virt[anc] = qid;
            virtuals.push_back(anc);
          }
        }
        swap(u, v);
      }
    }
  }

  sort(virtuals.begin(), virtuals.end(), by_ord);
  vector<int> cur_par;
  for (int i = 0; i < (int) virtuals.size(); i++) {
    int u = virtuals[i];
    if (cur_par.empty()) {
      cur_par.push_back(u);
      assert(u == virtuals.front());
    } else {
      while (rord[cur_par.back()] < ord[u]) {
        cur_par.pop_back();
      }
      virt_ch[cur_par.back()].push_back(u);
      //  cout << " edge " << cur_par.back() << " " << u << endl;
      cur_par.push_back(u);
    }
  }

  reverse(virtuals.begin(), virtuals.end());
  for (int u : virtuals) {
    // values for dp0 and dp1 if we do not remove u
    ll a = 0;
    ll b = 0;
    for (int nxt : virt_ch[u]) {
      a += dp0[nxt];
      b = min(b, (ll) (dp1[nxt] - dp0[nxt]));
    }
    b += a;

    // value for dp0 if we remove u
    ll c = 0;
    for (int nxt : virt_ch[u]) {
      c += min(dp1[nxt], dp0[nxt]);
    }

    if (in_cur[u] == qid) {
      dp0[u] = MAX_N;
      dp1[u] = a;
    } else {
      dp0[u] = min(a, c + 1);
      dp1[u] = b;
    }

    dp0[u] = min(dp0[u], MAX_N);
    dp1[u] = min(dp1[u], MAX_N);
    //cout << u << " " << dp0[u] << " " << dp1[u] << " " << a << " " << b << " " << c << endl;
  }

  for (int u : virtuals) {
    virt_ch[u].clear();
  }
  
  cout << min(dp0[virtuals.back()], dp1[virtuals.back()]) << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int vertexc;
  cin >> vertexc;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  build(1, 1);

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    solve(vertexc);
  }
}