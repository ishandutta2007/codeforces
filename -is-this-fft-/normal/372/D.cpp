#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9 + 5;

struct PairMin {
  pair<int, int> operator() (pair<int, int> p, pair<int, int> q) {
    return min(p, q);
  }
};

template<typename T, class OP>
class SegTree {
  int length;
  vector<T> tree;
  vector<int> lend;
  vector<int> rend;
  OP op;
  T id;

  void update (int vertex) {
    if (vertex == 0) {
      return;
    }

    tree[vertex] = op(tree[2 * vertex], tree[2 * vertex + 1]);
    update(vertex / 2);
  }
  
public:
  SegTree () {}
  
  SegTree (int _length, T _id) {
    length = 1;
    while (length < _length) {
      length *= 2;
    }

    id = _id;

    tree = vector<T> (2 * length, id);
    lend = vector<int> (2 * length);
    rend = vector<int> (2 * length);
    op = OP ();

    for (int i = length; i < 2 * length; i++) {
      lend[i] = i - length;
      rend[i] = i - length;
    }

    for (int i = length - 1; i >= 1; i--) {
      lend[i] = lend[2 * i];
      rend[i] = rend[2 * i + 1];
    }
  }

  void set (int idx, T val) {
    tree[length + idx] = val;
    update((length + idx) / 2);
  }

  T query (int ql, int qr, int vertex = 1) {
    ql = max(ql, lend[vertex]);
    qr = min(qr, rend[vertex]);

    if (ql > qr) {
      return id;
    } else if (ql == lend[vertex] && qr == rend[vertex]) {
      return tree[vertex];
    } else {
      return op(query(ql, qr, 2 * vertex),
                query(ql, qr, 2 * vertex + 1));
    }
  }
};

const int MAX_LG = 18;
const int MAX_N = 1e5 + 5;

vector<int> adj [MAX_N];

vector<int> shortEuler;
pair<int, int> shortEulerInterval [MAX_N];
void shortEulerDfs (int vertex, int parent) {
  shortEuler.push_back(vertex);
  shortEulerInterval[vertex].first = (int) shortEuler.size() - 1;
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      shortEulerDfs(nxt, vertex);
    }
  }
  shortEulerInterval[vertex].second = (int) shortEuler.size() - 1;
}

vector<int> longEuler;
int longEulerPos [MAX_N];
void longEulerDfs (int vertex, int parent) {
  longEuler.push_back(vertex);
  longEulerPos[vertex] = (int) longEuler.size() - 1;
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      longEulerDfs(nxt, vertex);
      longEuler.push_back(vertex);
    }
  }
}

int lvl [MAX_N];
void lvlDfs (int vertex, int parent) {
  lvl[vertex] = lvl[parent] + 1;
  for (int nxt : adj[vertex]) {
    if (nxt != parent) {
      lvlDfs(nxt, vertex);
    }
  }
}

pair<int, int> lcaRMQ [MAX_LG + 2][2 * MAX_N];
void buildLcaRMQ () {
  for (int i = 0; i < (int) longEuler.size(); i++) {
    lcaRMQ[0][i] = make_pair(lvl[longEuler[i]], longEuler[i]);
  }

  for (int k = 1; k < MAX_LG + 2; k++) {
    for (int i = 0; i < (int) longEuler.size(); i++) {
      if (i + (1 << (k - 1)) < (int) longEuler.size()) {
        lcaRMQ[k][i] = min(lcaRMQ[k - 1][i], lcaRMQ[k - 1][i + (1 << (k - 1))]);
      } else {
        lcaRMQ[k][i] = lcaRMQ[k - 1][i];
      }
    }
  }
}

int clz (int N) {
  return 32 - __builtin_clz(N) - 1;
}

pair<int, int> lcaRMQQuery (int l, int r) {
  int diff = r - l;
  int k = clz(diff);
  pair<int, int> ans = min(lcaRMQ[k][l], lcaRMQ[k][r - (1 << k) + 1]);
  return ans;
}

// SegTree<pair<int, int>, PairMin> LCATree;
// SegTree<int, Add> descTree;

int descFen [MAX_N];
void descAdd (int idx, int val) {
  idx++;
  for (int i = idx; i < MAX_N; i += i & -i) {
    descFen[i] += val;
  }
}

int descGet (int idx) {
  idx++;
  int ans = 0;
  for (int i = idx; i >= 1; i -= i & -i) {
    ans += descFen[i];
  }
  return ans;
}

int magicHullSize;
set<pair<int, int>> magicSet; /* <position in long Eulerian, index> */

int lca (int p, int q) {
  if (longEulerPos[p] > longEulerPos[q]) {
    swap(p, q);
  }
  return lcaRMQQuery(longEulerPos[p], longEulerPos[q]).second;
}

int dist (int p, int q) {
  return lvl[p] + lvl[q] - 2 * lvl[lca(p, q)];
}
  
int lcaOfMagicSet;

bool hasDescendantInMagicSet (int vertex) {
  return descGet(shortEulerInterval[vertex].second) > descGet(shortEulerInterval[vertex].first);
}

bool hasAncestorInMagicHull (int vertex) {
  return lca(vertex, lcaOfMagicSet) == lcaOfMagicSet;
}

int distToMagicHull (int vertex) {
  if (hasDescendantInMagicSet(vertex) && hasAncestorInMagicHull(vertex)) {
    return 0;
  }

  if (hasDescendantInMagicSet(vertex)) {
    return dist(lcaOfMagicSet, vertex);
  }

  if (hasAncestorInMagicHull(vertex)) {
    int ans = INF;
    auto ub = magicSet.upper_bound(make_pair(longEulerPos[vertex], vertex));
    if (ub != magicSet.end()) {
      ans = lvl[vertex] - lvl[lca(ub->second, vertex)];
    }

    if (ub != magicSet.begin()) {
      auto lb = prev(ub);
      ans = min(ans, lvl[vertex] - lvl[lca(lb->second, vertex)]);
    }

    return ans;
  }

  return dist(lcaOfMagicSet, vertex);
}

void init () {
  shortEulerDfs(1, 1);
  longEulerDfs(1, 1);
  lvlDfs(1, 1);
  magicHullSize = 0;
  buildLcaRMQ();
}  
  

void addToMagicSet (int vertex) {
  // cerr << "ADDED " << vertex << " TO HULL" << endl;
  if (!magicSet.empty()) {
    magicHullSize += distToMagicHull(vertex);
    // cerr << "DIST TO HULL IS " << distToMagicHull(vertex) << endl;
  } else {
    magicHullSize = 1;
  }
    
  magicSet.insert(make_pair(longEulerPos[vertex], vertex));
  descAdd(shortEulerInterval[vertex].first, 1);

  lcaOfMagicSet = lca((*magicSet.begin()).second, (*magicSet.rbegin()).second);
}

void removeFromMagicSet (int vertex) {
  // cerr << "REMOVED " << vertex << " FROM HULL" << endl;
  magicSet.erase(make_pair(longEulerPos[vertex], vertex));
  descAdd(shortEulerInterval[vertex].first, -1);

  if (!magicSet.empty()) {
    lcaOfMagicSet = lca((*magicSet.begin()).second, (*magicSet.rbegin()).second);
    magicHullSize -= distToMagicHull(vertex);
    // cerr << "DIST TO HULL IS " << distToMagicHull(vertex) << endl;
  } else {
    magicHullSize = 0;
  }
}

int getMagicHullSize () {
  // cerr << "HULL SIZE = " << magicHullSize << endl;
  return magicHullSize;
}

int main () {
  ios::sync_with_stdio(false);
  
  int vertexc, maxhull;
  cin >> vertexc >> maxhull;

  for (int i = 0; i < vertexc - 1; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  init();
  int ans = 0;
  for (int k = 1 << MAX_LG; k != 0; k /= 2) {
    int cur = ans + k; /* can we get a subtree with score = cur? */
    if (cur <= vertexc) {
      int smallestHull = INF;
      for (int i = 1; i <= cur; i++) {
        addToMagicSet(i);
      }
      smallestHull = min(smallestHull, getMagicHullSize());

      for (int i = cur + 1; i <= vertexc; i++) {
        removeFromMagicSet(i - cur);
        addToMagicSet(i);
        smallestHull = min(smallestHull, getMagicHullSize());
      }

      for (int i = vertexc + 1 - cur; i <= vertexc; i++) {
        removeFromMagicSet(i);
      }
      getMagicHullSize();

      if (smallestHull <= maxhull) {
        ans = cur;
      }
    }
  }

  cout << ans << endl;
}