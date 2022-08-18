#include <iostream>
#include <set>
#include <iomanip>
#include <limits>
#include <algorithm>

typedef long double ldouble;
typedef long long llong;

const ldouble PI = 3.141592653589793238L;
const ldouble EPS = 0.000001;
const int MAX_C = 100005; 
const ldouble INF = std::numeric_limits<long double>::infinity();

using namespace std;

class segtree {
  llong* tree;
  int segstart, segsize, treeh;
  llong ident;

  int rstart (int vertex, int height) {
    return (vertex << height) - segstart;
  }

  int rend (int vertex, int height) {
    return rstart(vertex + 1, height) - 1;
  }

  llong ttop (int left, int right, int root, int height) {
    left = std::max(left, rstart(root, height));
    right = std::min(right, rend(root, height));

    if (left == rstart(root, height) && 
	right == rend(root, height)) {
      return tree[root];
    } else if (left > right) {
      return ident;
    } else {
      return max(ttop(left, right, root << 1, height - 1),
		    ttop(left, right, root << 1 ^ 1, height - 1));
    }
  }

public:
  segtree (int s, ldouble id) {
    ident = id;

    for (int i = 2; i < 20; i++) {
      if (s < 1 << i) {
	segstart = 1 << i;
	segsize = segstart * 2;
	treeh = i;
	break;
      }
    }
      
    tree = new llong [segsize];
    for (int i = 0; i < segsize; i++) {
      tree[i] = id;
    }
  }

  llong top (int left, int right) {
    return ttop(left, right, 1, treeh);
  }

  void set (int index, llong val) {
    tree[index + segstart] = val;
    
    for (int i = index + segstart; i != 1; i >>= 1) {
      if (tree[i >> 1] != max(tree[i], tree[i ^ 1])) {
	tree[i >> 1] = max(tree[i], tree[i ^ 1]);
      } else {
	break;
      }
    }
  }
};

int id [MAX_C];
int sid [MAX_C];
llong vol [MAX_C];

bool comp (int a, int b) {
  if (vol[a] == vol[b]) {
    return a > b;
  } else {
    return vol[a] < vol[b];
  }
}

int main () {
  ios::sync_with_stdio(false);

  int cakec;
  cin >> cakec;

  for (int i = 0; i < cakec; i++) {
    llong radius, height;
    cin >> radius >> height;
    vol[i] = radius * radius * height;
    sid[i] = i;
  }

  sort(sid, sid + cakec, comp);
  for (int i = 0; i < cakec; i++) {
    id[sid[i]] = i;
  }

  segtree dp (cakec + 5, 0);
  llong ans = 0;
  for (int i = 0; i < cakec; i++) {
    llong base;
    if (id[i] == 0) {
      base = 0;
    } else {
      base = dp.top(0, id[i] - 1);
    }

    ans = max(ans, base + vol[i]);
    dp.set(id[i], base + vol[i]);
  }

  ldouble dans = PI * (ldouble) ans;

  cout << fixed << setprecision(15) << dans << endl;
}