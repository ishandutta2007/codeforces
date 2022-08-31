#include <iostream>
#include <map>
#include <algorithm>

typedef long long llong;

using namespace std;

const int MAX_RING = 100005;

struct ring {
  llong inner, outer, height;
};

ring comps [MAX_RING];

bool operator< (ring p, ring q) {
  if (p.outer == q.outer) {
    if (p.inner == q.inner) {
      return p.height > q.height;
    }
    return p.inner > q.inner; /* smaller are more universal and should be on top */
  } else {
    return p.outer > q.outer;
  }
}

struct maxll {
  llong operator() (llong p, llong q) {
    return max(p, q);
  }
};

template<typename T, class comp>
class segtree {
  T* tree;
  llong segstart, segsize, treeh;
  T ident;

  llong rstart (llong vertex, llong height) {
    return (vertex << height) - segstart;
  }

  llong rend (llong vertex, llong height) {
    return rstart(vertex + 1, height) - 1;
  }

  T ttop (llong left, llong right, llong root, llong height) {
    left = std::max(left, rstart(root, height));
    right = std::min(right, rend(root, height));

    if (left == rstart(root, height) && 
	right == rend(root, height)) {
      return tree[root];
    } else if (left > right) {
      return ident;
    } else {
      return comp()(ttop(left, right, root << 1, height - 1),
		    ttop(left, right, root << 1 ^ 1, height - 1));
    }
  }

public:
  segtree (llong s, T id) {
    ident = id;

    for (llong i = 2; i < 20; i++) {
      if (s < 1 << i) {
	segstart = 1 << i;
	segsize = segstart * 2;
	treeh = i;
	break;
      }
    }
      
    tree = new T [segsize];
    for (llong i = 0; i < segsize; i++) {
      tree[i] = id;
    }
  }

  T top (llong left, llong right) {
    return ttop(left, right, 1, treeh);
  }

  void set (llong index, T val) {
    tree[index + segstart] = val;
    
    for (llong i = index + segstart; i != 1; i >>= 1) {
      if (tree[i >> 1] != comp()(tree[i], tree[i ^ 1])) {
	tree[i >> 1] = comp()(tree[i], tree[i ^ 1]);
      } else {
	break;
      }
    }
  }
};


int main () {
  llong ringc;
  cin >> ringc;

  map<llong, llong> compr;
  for (llong i = 0; i < ringc; i++) {
    cin >> comps[i].inner >> comps[i].outer >> comps[i].height;
    compr[comps[i].inner] = 0;
    compr[comps[i].outer] = 0;
  }

  llong cur = 1;
  for (auto i = compr.begin(); i != compr.end(); i++) {
    i->second = cur;
    cur++;
  }

  for (int i = 0; i < ringc; i++) {
    comps[i].inner = compr[comps[i].inner];
    comps[i].outer = compr[comps[i].outer];
  }

  sort(comps, comps + ringc);
  segtree<llong, maxll> highest (cur + 5, 0);
  llong ans = 0;
  for (llong i = 0; i < ringc; i++) {
    llong besth = max(highest.top(0, comps[i].outer - 1) + comps[i].height,
                      highest.top(comps[i].inner, comps[i].inner));
    highest.set(comps[i].inner, besth);
    ans = max(ans, besth);
  }

  cout << ans << endl;
}