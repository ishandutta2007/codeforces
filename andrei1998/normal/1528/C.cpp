#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1000000 + 5;

int N;

vector<int> graph1[NMAX];
vector<int> graph2[NMAX];

int cnt;
int first2[NMAX];
int last2[NMAX];

bool isAnc2(int sus, int jos) {
  return first2[sus] <= first2[jos] && first2[jos] <= last2[sus];
}

int cntNonLeaves;
bool cmp(int a, int b) { return first2[a] < first2[b]; }
set<int, decltype(cmp) *> nodes(cmp);

void addToSet(int node) {
  set<int>::iterator nxt = nodes.lower_bound(node);
  if (nxt != nodes.begin() && nxt != nodes.end()) {
    set<int>::iterator prv = prev(nxt);
    cntNonLeaves -= isAnc2(*prv, *nxt);
  }
  if (nxt != nodes.begin()) {
    set<int>::iterator prv = prev(nxt);
    cntNonLeaves += isAnc2(*prv, node);
  }
  if (nxt != nodes.end()) {
    cntNonLeaves += isAnc2(node, *nxt);
  }
  nodes.insert(node);
}

void removeFromSet(int node) {
  set<int>::iterator me = nodes.lower_bound(node);
  assert(*me == node);
  if (me != nodes.begin()) {
    set<int>::iterator prv = prev(me);
    cntNonLeaves -= isAnc2(*prv, node);
  }
  set<int>::iterator nxt = next(me);
  if (nxt != nodes.end()) {
    cntNonLeaves -= isAnc2(node, *nxt);
  }
  if (me != nodes.begin() && nxt != nodes.end()) {
    set<int>::iterator prv = prev(me);
    cntNonLeaves += isAnc2(*prv, *nxt);
  }
  nodes.erase(node);
}

int getLeaves() { return nodes.size() - cntNonLeaves; }

void dfs2(int node, int father) {
  first2[node] = ++cnt;
  for (auto it : graph2[node]) {
    if (it != father) {
      dfs2(it, node);
    }
  }
  last2[node] = cnt;
}

int ans;
void dfs1(int node, int father) {
  addToSet(node);
  if (graph1[node].empty()) {
    ans = max(ans, getLeaves());
  }
  for (auto it : graph1[node]) {
    if (it != father) {
      dfs1(it, node);
    }
  }
  removeFromSet(node);
}

int solve() {
  cnt = 0;
  ans = 1;
  cntNonLeaves = 0;
  nodes.clear();
  dfs2(1, 0);
  dfs1(1, 0);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 0;
  cin >> t;
  while (t--) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
      graph1[i].clear();
      graph2[i].clear();
    }
    for (int i = 2; i <= N; ++i) {
      int fat;
      cin >> fat;
      graph1[fat].push_back(i);
    }
    for (int i = 2; i <= N; ++i) {
      int fat;
      cin >> fat;
      graph2[fat].push_back(i);
    }
    cout << solve() << '\n';
  }
  return 0;
}