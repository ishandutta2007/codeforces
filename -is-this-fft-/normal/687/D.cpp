#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class DSU {
  vector<int> _root;
  vector<int> _sign;
  vector<int> _rnk;
  vector<int> age;
  int cur_age;

  void reset_vertex (int u) {
    _root[u] = u;
    _sign[u] = 1;
    _rnk[u] = 0;
    age[u] = cur_age;
  }
  
  int& root (int u) {
    if (age[u] != cur_age) {
      reset_vertex(u);
    }

    return _root[u];
  }

  int& sign (int u) {
    if (age[u] != cur_age) {
      reset_vertex(u);
    }

    return _sign[u];
  }

  int& rnk (int u) {
    if (age[u] != cur_age) {
      reset_vertex(u);
    }

    return _rnk[u];
  }
  
public:
  DSU (int n = 0) : _root(n), _sign(n), _rnk(n), age(n, 0), cur_age(1) {}

  void reset () {
    cur_age++;
  }
  
  pair<int, int> find (int u) {
    if (root(u) == u) {
      return make_pair(u, 1);
    } else {
      auto pr = find(root(u));
      return make_pair(pr.first, sign(u) * pr.second);
    }
  }

  int merge (int u, int v) { // -1 - you fucked up the graph, 0 - no change, 1 - change
    int sgn = -1;
    auto up = find(u);
    auto vp = find(v);

    u = up.first;
    v = vp.first;
    sgn *= up.second * vp.second;

    if (u == v && sgn == 1) return 0;
    if (u == v && sgn == -1) return -1;

    if (rnk(u) > rnk(v)) swap(u, v);
    root(u) = v;
    sign(u) = sgn;
    if (rnk(u) == rnk(v)) rnk(v)++;
    return 1;
  }
};

const int MAX_M = 1 << 20;

DSU pubdsu;

// edge data
int weight [MAX_M];
int from [MAX_M];
int to [MAX_M];

vector<int> useful [2 * MAX_M];
int lfend [2 * MAX_M];
int rgend [2 * MAX_M];

vector<int> merge (const vector<int> &p, const vector<int> &q, int &lw) {
  pubdsu.reset();
  int ps = p.size();
  int qs = q.size();

  vector<int> ans;
  lw = -1;
  
  int pptr = 0, qptr = 0;
  while (pptr < ps || qptr < qs) {
    int choice;
    if (pptr < ps && qptr < qs) {
      if (weight[p[pptr]] > weight[q[qptr]]) {
        choice = 0;
      } else {
        choice = 1;
      }
    } else if (pptr < ps) {
      choice = 0;
    } else {
      // qptr < qs
      choice = 1;
    }

    int cur;
    if (choice == 0) {
      cur = p[pptr];
      pptr++;
    } else {
      cur = q[qptr];
      qptr++;
    }
    
    int res = pubdsu.merge(from[cur], to[cur]);
    if (res == -1) {
      ans.push_back(cur);
      lw = weight[cur];
      return ans;
    } else if (res == 1) {
      ans.push_back(cur);
    }
  }
  return ans;
}

void query (int u, int ql, int qr, int &lw, vector<int> &tmp) {
  ql = max(ql, lfend[u]);
  qr = min(qr, rgend[u]);

  if (ql > qr) return;
  if (ql == lfend[u] && qr == rgend[u]) {
    tmp = merge(tmp, useful[u], lw);
    return;
  }
  query(2 * u, ql, qr, lw, tmp);
  query(2 * u + 1, ql, qr, lw, tmp);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m, q;
  cin >> n >> m >> q;

  pubdsu = DSU(n + 1);
  for (int i = 1; i <= m; i++) {
    cin >> from[i] >> to[i] >> weight[i];
  }

  for (int i = MAX_M; i < 2 * MAX_M; i++) {
    lfend[i] = i - MAX_M;
    rgend[i] = i - MAX_M;
  }

  for (int i = MAX_M - 1; i >= 1; i--) {
    lfend[i] = lfend[2 * i];
    rgend[i] = rgend[2 * i + 1];
  }

  for (int i = 1; i <= m; i++) {
    useful[MAX_M + i].push_back(i);
  }

  for (int i = MAX_M - 1; i >= 1; i--) {
    int trash;
    useful[i] = merge(useful[2 * i], useful[2 * i + 1], trash);
  }
  
  /*
  for (int i = 1; i < MAX_M; i++) {
    cerr << lfend[i] << " " << rgend[i] << ": ";
    for (auto e : useful[i]) {
      cerr << e << " ";
    }
    cerr << endl;
  }
  */

  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;

    int ans = -1;
    vector<int> tmp;
    query(1, l, r, ans, tmp);

    cout << ans << '\n';
  }
}