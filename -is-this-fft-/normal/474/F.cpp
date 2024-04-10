#include <iostream>
#include <algorithm>
#include <map>

const int MAX_ANT = 100005;
const int MAX_QUERY = 100005;
const int INF = 1023456789;
const char newl = '\n';

struct gcd {
  int operator() (int a, int b) {
    while (true) {
      if (a == 0) {
	return b;
      } else if (b == 0) {
	return a;
      } else {
	//std::swap(a, b);
	a ^= b;
	b ^= a;
	a ^= b;
	b %= a;
      }
    }
  }
};

struct elem {
  int val, cnt;

  elem () {
    val = INF;
    cnt = 0;
  }
  
  elem (int v, int c) {
    val = v;
    cnt = c;
  }
};

struct mincnt {
  elem operator() (elem a, elem b) {
    if (a.val == b.val) {
      return elem(a.val, a.cnt + b.cnt);
    } else if (a.val < b.val) {
      return a;
    } else {
      return b;
    }
  }
};

bool operator!= (elem a, elem b) {
  return (a.val != b.val) || (a.cnt != b.cnt);
}

template<typename T, class comp>
class segtree {
  T* tree;
  int segstart, segsize, treeh;
  T ident;

  int rstart (int vertex, int height) {
    return (vertex << height) - segstart;
  }

  int rend (int vertex, int height) {
    return rstart(vertex + 1, height) - 1;
  }

  T ttop (int left, int right, int root, int height) {
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
  segtree (int s, T id) {
    ident = id;

    for (int i = 2; i < 20; i++) {
      if (s < 1 << i) {
	segstart = 1 << i;
	segsize = segstart * 2;
	treeh = i;
	break;
      }
    }
      
    tree = new T [segsize];
    for (int i = 0; i < segsize; i++) {
      tree[i] = id;
    }
  }

  T top (int left, int right) {
    return ttop(left, right, 1, treeh);
  }

  void set (int index, T val) {
    tree[index + segstart] = val;
    
    for (int i = index + segstart; i != 1; i >>= 1) {
      if (tree[i >> 1] != comp()(tree[i], tree[i ^ 1])) {
	tree[i >> 1] = comp()(tree[i], tree[i ^ 1]);
      } else {
	break;
      }
    }
  }
};

int main () {
  std::ios::sync_with_stdio(false);

  int antc;
  std::cin >> antc;

  
  segtree<int, gcd> gctree (antc + 1, 0);
  segtree<elem, mincnt> mintree (antc + 1, elem(INF, 0));
  
  for (int i = 1; i <= antc; i++) {
    int ant;
    std::cin >> ant;
    
    gctree.set(i, ant);
    mintree.set(i, elem(ant, 1));
  }

  int queryc;
  std::cin >> queryc;

  for (int i = 0; i < queryc; i++) {
    int left, right;
    std::cin >> left >> right;
    
    int gc = gctree.top(left, right);
    elem mn = mintree.top(left, right);

    if (gc == mn.val) {
      std::cout << right - left + 1 - mn.cnt << newl;
    } else {
      std::cout << right - left + 1 << newl;
    }
  }

  return 0;
}