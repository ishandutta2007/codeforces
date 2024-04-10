#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

typedef long long ll;
typedef pair<int, int> Point;
#define x first
#define y second

Point pos [MAX_N];

ll cross (Point p, Point q) {
  return (ll) p.x * (ll) q.y - (ll) p.y * (ll) q.x;
}

ll dot (Point p, Point q) {
  return (ll) p.x * (ll) q.x + (ll) p.y * (ll) q.y;
}

Point operator- (Point p, Point q) {
  return Point(p.x - q.x, p.y - q.y);
}

struct CcwComparator {
  int center, parent; // indices

  int dir (int p) const {
    auto u = pos[parent] - pos[center];
    auto v = pos[p] - pos[center];
    auto c = cross(u, v);

    if (c == 0) {
      if (dot(u, v) >= 0) {
        return 0; // collinear with parent
      } else {
        return 2; // opp to parent
      }
    } else if (c > 0) {
      return 1;
    } else {
      return 3;
    }
  }
  
  CcwComparator () {
  }

  CcwComparator (int _center, int _parent) :
    center(_center), parent(_parent) {
  }
  
  bool operator() (int p, int q) const {
    int pdir = dir(p);
    int qdir = dir(q);
    if (pdir != qdir) {
      return pdir < qdir;
    }

    auto u = pos[p] - pos[center];
    auto v = pos[q] - pos[center];
    return cross(u, v) > 0;
  }
};

vector<int> adj [MAX_N];

set<int, CcwComparator> tree [MAX_N]; // sorted in ccw order relative to parent
int lfend [MAX_N];
int rgend [MAX_N];

void build (int u, int p, int &cur) {
  lfend[u] = cur;
  cur++;

  sort(adj[u].begin(), adj[u].end(), CcwComparator(u, p));
  tree[u] = set<int, CcwComparator> (CcwComparator(u, p));
  for (int nxt : adj[u]) {
    if (lfend[nxt] == 0) {
      tree[u].insert(nxt);
      build(nxt, u, cur);
    }
  }

  rgend[u] = cur;
}

// p -> q -> r, process the things at q
// we need to add arrows to things that are strictly between
// p and r in ccw order in the adjacency list of p
int process (int p, int q, int r) {
  int ans = 0;

  bool skip = tree[q].empty();
  const auto &cmp = tree[q].key_comp();
  if (cmp(r, p)) {
    // parent is in the range of [p, r] counterclockwise
    // the only way we have nothing to add here is if
    if (tree[q].upper_bound(p) == tree[q].end() &&
        tree[q].lower_bound(r) == tree[q].begin()) {
      skip = true;
    }
  } else {
    // parent is not in the range of [p, r] counterclockwise
    auto it = tree[q].upper_bound(p);
    if (it == tree[q].end()) {
      skip = true;
    } else if (r == *it || cmp(r, *it)) {
      skip = true;
    }
  }

  if (!skip) {
    auto lit = tree[q].upper_bound(p); // first to be included
    auto rit = tree[q].lower_bound(r); // first to be excluded

    int L;
    if (lit == tree[q].end()) {
      L = *tree[q].begin();
    } else {
      L = *lit;
    }
    ans += lfend[L];

    int R;
    if (rit == tree[q].begin()) {
      R = *tree[q].rbegin();
    } else {
      R = *prev(rit);
    }
    ans -= rgend[R];

    if (cmp(R, L)) {
      ans -= rgend[q];
      ans += lfend[q] + 1;
    }
  }

  if (q != 1 &&
      cmp.parent != r &&
      cmp.parent != p &&
      cmp(r, p)) {
    ans += rgend[q] - lfend[q];
  }

  return ans;
}

int solve (vector<int> &query) {
  // check if it is ccw, if not, reverse
  ll area = 0;
  int K = query.size();
  for (int i = 0; i < K; i++) {
    area += cross(pos[query[i]], pos[query[(i + 1) % K]]);
  }

  if (area < 0) {
    reverse(query.begin(), query.end());
  }

  int pts = 0;
  for (int i = 0; i < K; i++) {
    pts += process(query[i], query[(i + 1) % K], query[(i + 2) % K]);
  }

  if (pts <= 0) {
    pts += rgend[1] - lfend[1]; // n
  }
  return pts;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    cin >> pos[i].x >> pos[i].y;
  }

  int cur = 1;
  build(1, 0, cur);

  int qc;
  cin >> qc;

  for (int i = 0; i < qc; i++) {
    int k;
    cin >> k;

    vector<int> q (k);
    for (int j = 0; j < k; j++) {
      cin >> q[j];
    }

    cout << solve(q) << '\n';
  }
}