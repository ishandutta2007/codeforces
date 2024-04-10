#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct TwoMax {
  pair<int, int> fst, snd;

  TwoMax () : fst(-1, -1), snd(-1, -1) {}
  
  void add (pair<int, int> pr) {
    if (pr > fst) {
      snd = fst;
      fst = pr;
    } else if (pr > snd) {
      snd = pr;
    }
  }
};

TwoMax merge (TwoMax p, TwoMax q) {
  TwoMax ans = p;
  ans.add(q.fst);
  ans.add(q.snd);
  return ans;
}

class Segtree {
  int n;
  vector<TwoMax> tree;
  vector<int> lfend;
  vector<int> rgend;

public:
  Segtree (vector<int> init) {
    n = 1;
    while (n < (int) init.size()) {
      n *= 2;
    }

    tree = vector<TwoMax> (2 * n, TwoMax());
    lfend = vector<int> (2 * n);
    rgend = vector<int> (2 * n);

    for (int i = 0; i < (int) init.size(); i++) {
      tree[n + i].add(make_pair(init[i], i));
    }
    
    for (int i = n; i < 2 * n; i++) {
      lfend[i] = i - n;
      rgend[i] = i - n;
    }

    for (int i = n - 1; i > 0; i--) {
      lfend[i] = lfend[2 * i];
      rgend[i] = rgend[2 * i + 1];
      tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    }
  }

  TwoMax query (int ql, int qr, int u = 1) {
    ql = max(ql, lfend[u]);
    qr = min(qr, rgend[u]);

    if (ql > qr) {
      return TwoMax();
    }

    if (ql == lfend[u] && qr == rgend[u]) {
      return tree[u];
    }

    return merge(query(ql, qr, 2 * u), query(ql, qr, 2 * u + 1));
  }
};

const int MAX_N = 2e5 + 5;
const int INF = 1e9 + 5;

struct Query {
  int type, l, r;
};

Query qs [MAX_N];

vector<int> zs [MAX_N];
vector<int> ze [MAX_N];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, qc;
  cin >> n >> qc;

  for (int i = 0; i < qc; i++) {
    int t;
    cin >> t;

    if (t == 0) {
      cin >> qs[i].l >> qs[i].r >> qs[i].type;
    } else {
      qs[i].type = 2;
      cin >> qs[i].l;
    }

    qs[i].l--; qs[i].r--;
  }

  for (int i = 0; i < qc; i++) {
    if (qs[i].type == 0) {
      zs[qs[i].l].push_back(i);
      ze[qs[i].r].push_back(i);
    }
  }
  
  set<int> cur_segs;
  vector<int> cov_time (n);
  for (int i = 0; i < n; i++) {
    for (int u : zs[i]) {
      cur_segs.insert(u);
    }

    if (cur_segs.empty()) {
      cov_time[i] = INF;
    } else {
      cov_time[i] = *cur_segs.begin();
    }
    
    for (int u : ze[i]) {
      cur_segs.erase(u);
    }
  }

  vector<int> sick_time (n, INF);
  Segtree tree (cov_time);
  for (int i = 0; i < qc; i++) {
    if (qs[i].type == 1) {
      auto tb = tree.query(qs[i].l, qs[i].r);
      if (tb.snd.first != INF) {
        int pers = tb.fst.second;
        int conf = max(tb.snd.first, i);
        sick_time[pers] = min(sick_time[pers], conf);
      }
    }
  }

  for (int i = 0; i < qc; i++) {
    if (qs[i].type == 2) {
      int cur = qs[i].l;

      if (sick_time[cur] < i) {
        cout << "YES" << '\n';
      } else if (cov_time[cur] < i) {
        cout << "NO" << '\n';
      } else {
        cout << "N/A" << '\n';
      }
    }
  }
}