#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 100500;
const int MAXN = 1e5 + 5;

int N, A[N_];
vector<int> R[N_];
int prv[N_], nxt[N_];

struct node {
  int v;
  node *l, *r;
  node(int v = 0): v(v), l(NULL), r(NULL) { }
  node* &left() {
    if(l != NULL) return l;
    l = new node();
    return l;
  }
  node* &right() {
    if(r != NULL) return r;
    r = new node();
    return r;
  }
};

node* roots[N_];

void upd (node *r1, node *r2, int nl, int nr, int x) {
  if(nl < nr) {
    int nm = (nl + nr) >> 1;
    if(x <= nm) {
      upd(r1->left(), r2->left(), nl, nm, x);
      r2->r = r1->r;
    }else {
      r2->l = r1->l;
      upd(r1->right(), r2->right(), nm+1, nr, x);
    }
  }
  r2->v = r1->v + 1;
}

void upd (node *r1, node *r2, int x) {
  upd(r1, r2, 1, N, x);
}

int get (node *nd, int nl, int nr, int x, int y) {
  if(nl == x && nr == y) return nd->v;
  int nm = (nl + nr) >> 1;
  int ret = 0;
  if(x <= nm)
    ret += get(nd->left(), nl, nm, x, min(nm, y));
  if(y > nm)
    ret += get(nd->right(), nm+1, nr, max(nm+1, x), y);
  return ret;
}

int get (node *nd, int x, int y) {
  if(x > y) return 0;
  assert(1 <= x && x <= y && y <= N);
  return get(nd, 1, N, x, y);
}

int find (node *nd, int nl, int nr, int p) {
  if(nl == nr) return nl;
  int nm = (nl + nr) >> 1;
  //printf("find %d(%d + %d) %d - %d %d\n",nd->v,nd->left()->v,nd->right()->v, p,nl,nr);
  return (p <= nd->left()->v) ?
    find(nd->left(), nl, nm, p) :
    find(nd->right(), nm+1, nr, p - nd->left()->v);
}

int find (node *nd, int p) {
  return find(nd, 1, N, p);
}

int ans[N_];

int main() {
  roots[0] = new node();

  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    prv[i] = R[A[i]].empty() ? 0 : R[A[i]].back();
    nxt[prv[i]] = i;
    if(prv[i] == 0) {
      node *rt = new node();
      upd(roots[0], rt, i);
      roots[0] = rt;
    }
    R[A[i]].push_back(i);
  }

  for(int i = 1; i <= N; i++) {
    int j = nxt[i];
    if(j != 0) {
      roots[i] = new node();
      upd(roots[i-1], roots[i], j);
    }else {
      roots[i] = roots[i-1];
    }
  }

  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; ) {
            //  distinct +         
      int d = get(roots[i-1], 1, i-1) + k + 1;
      int j = (roots[i-1]->v < d) ? N+1 : find(roots[i-1], d);
      ans[k] += 1;
      assert(i < j);
      i = j;
    }
  }

  for(int k = 1; k <= N; k++)
    printf("%d ", ans[k]);
  return 0;
}