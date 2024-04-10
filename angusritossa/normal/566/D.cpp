#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
// union find from lecture code
const int N = 200010;
int parent[N];
int subtree_size[N];  

void init(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
    subtree_size[i] = 1;
  }
}

int root(int x) {
  // only roots are their own parents
  return parent[x] == x ? x : root(parent[x]);
}

void join(int x, int y) {
  // join roots
  x = root(x); y = root(y);
  // test whether already connected
  if (x == y)
    return;
  // size heuristic
  // hang smaller subtree under root of larger subtree
  if (subtree_size[x] < subtree_size[y]) {
    parent[x] = y;
    subtree_size[y] += subtree_size[x];
  } else {
    parent[y] = x;
    subtree_size[x] += subtree_size[y];
  }
}

set<int> s;
int main() {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    init(n);
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }

    for (int update = 0; update < q; update++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            join(x, y);
        } else if (t == 2) {
            for (int i = x; i < y; i++) {
                i = *s.lower_bound(i); // skipping ahead
                if (i < y) {
                    //cout << "merging " << i << " " << i+1 << "\n";
                    if (root(i) != root(i+1)) {
                        join(i, i+1);
                        s.erase(i);
                    }
                }
            }
        } else {
            if (root(x) == root(y)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}