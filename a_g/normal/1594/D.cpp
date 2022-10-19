#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool contradict = 0;

typedef struct node node;
struct node {
  node *parent;
  int rank=0;
  int size=1;
  bool differ=0; //different alignment as parent?
};

node* root(node *a) {
  if (a->parent == a) return a;
  bool differ = a->differ;
  node* oldparent = a->parent;
  a->parent = root(a->parent);
  a->differ = differ^(oldparent->differ);
  return a->parent;
}

void join(node *u, node *v, bool differ) {
  node *a = root(u);
  node *b = root(v);
  bool newdiffer = (u->differ)^(v->differ)^differ;
  if (a == b) {
    if (u->differ^v->differ^differ) contradict = 1;
  }
  int size = a->size + b->size;
  if (a->rank > b->rank) swap(a, b);
  // b has higher rank
  a->parent = b;
  a->differ = newdiffer;
  b->size = size;
  if (a->rank == b->rank) b->rank++;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    contradict = 0;
    int n, m;
    cin >> n >> m;
    vector<node> nodes(n);
    for (int i = 0; i < n; i++) {
      nodes[i].parent = &nodes[i];
    }
    for (int i = 0; i < n; i++) {
      //cout << i << " " << &nodes[i] << " " << nodes[i].parent << " " << nodes[i].differ << endl;
    }
    while (m--) {
      int i, j;
      string c;
      cin >> i >> j >> c;
      i--, j--;
      bool differ = (c == "imposter");
      join(&nodes[i], &nodes[j], differ);
      for (int i = 0; i < n; i++) {
        //cout << i << " " << &nodes[i] << " " << nodes[i].parent << " " << nodes[i].differ << endl;
      }
    }

    if (contradict) cout << -1 << endl;
    else {
      int ans = 0;
      set<int> roots;
      map<node*, int> same;
      map<node*, int> different;
      for (int i = 0; i < n; i++) {
        if (root(&nodes[i]) == &nodes[i]) roots.insert(i);
        if (nodes[i].differ) {
          different[root(&nodes[i])]++;
          //cout << "different " << i << endl;
        }
        else  {
          same[root(&nodes[i])]++;
          //cout << "same " << i << endl;
        }
      }
      for (int i: roots) {
        //cout << i << " " << same[&nodes[i]] << " " << different[&nodes[i]] << endl;
        ans += max(same[&nodes[i]], different[&nodes[i]]);
      }
      cout << ans << endl;
    }
  }
}