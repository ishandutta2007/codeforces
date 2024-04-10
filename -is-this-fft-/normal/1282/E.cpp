#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <list>

using namespace std;

const int MAX_N = 1e5 + 5;

set<int> cur_ones;
int cnt [MAX_N];

void add_cnt (int idx, int val) {
  if (cnt[idx] == 1) {
    cur_ones.erase(idx);
  }
  cnt[idx] += val;
  if (cnt[idx] == 1) {
    cur_ones.insert(idx);
  }
}

set<int> pcs_w [MAX_N];
map<int, list<int>*> nbors [MAX_N];

list<int>* merge (list<int> *L, list<int> *R) {
  if (L->size() > R->size()) {
    for (auto it = R->begin(); it != R->end(); it++) {
      L->push_back(*it);
    }
    return L;
  } else {
    for (auto it = L->rbegin(); it != L->rend(); it++) {
      R->push_front(*it);
    }
    return R;
  }
}

void solve () {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cnt[i] = 0;
    cur_ones = set<int> ();
    nbors[i].clear();
    pcs_w[i].clear();
  }
  
  vector<vector<int>> pieces (n - 2);
  for (int i = 0; i < n - 2; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    pieces[i] = {a, b, c};
    for (int u : pieces[i]) {
      add_cnt(u, 1);
    }

    for (int u : pieces[i]) {
      pcs_w[u].insert(i);
    }
  }

  vector<int> Q;
  for (int i = 0; i < n - 2; i++) {
    int corner = *cur_ones.begin();
    int piece = *pcs_w[corner].begin();
    Q.push_back(piece + 1);

    vector<int> oth;
    for (int u : pieces[piece]) {
      if (u != corner) {
        oth.push_back(u);
      }
    }

    int U = oth[0];
    int V = corner;
    int W = oth[1];

    if (nbors[U].count(V) == 0) {
      nbors[U][V] = new list<int> ({U});
    }

    if (nbors[V].count(U) == 0) {
      nbors[V][U] = new list<int> ({V});
    }

    if (nbors[V].count(W) == 0) {
      nbors[V][W] = new list<int> ({V});
    }

    if (nbors[W].count(V) == 0) {
      nbors[W][V] = new list<int> ({W});
    }

    if (i != n - 3) {
      list<int> *uv = nbors[U][V];
      list<int> *vw = nbors[V][W];
      list<int> *vu = nbors[V][U];
      list<int> *wv = nbors[W][V];

      nbors[U][W] = merge(uv, vw);
      nbors[W][U] = merge(wv, vu);
      nbors[U].erase(V);
      nbors[V].erase(U);
      nbors[V].erase(W);
      nbors[W].erase(V);
    } else {
      if (nbors[W].count(U) == 0) {
        nbors[W][U] = new list<int> ({W});
      }

      list<int> uv = *nbors[U][V];
      list<int> vw = *nbors[V][W];
      list<int> wu = *nbors[W][U];

      for (int t : uv) {
        cout << t << " ";
      }
      for (int t : vw) {
        cout << t << " ";
      }
      for (int t : wu) {
        cout << t << " ";
      }
      cout << '\n';
    }

    for (int u : pieces[piece]) {
      add_cnt(u, -1);
    }

    for (int u : pieces[piece]) {
      pcs_w[u].erase(piece);
    }
  }

  for (int u : Q) {
    cout << u << " ";
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}