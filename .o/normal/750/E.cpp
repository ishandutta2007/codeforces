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
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);
// ans: { prefix 201    } + { suffix 7    }

const int N_ = 200500, Q_ = 100500;
int N, Q;
char S[N_];

const int LEAF = 1<<18;
const int p[] = {1, 2, 0, 0, 0, 0, 4, 3, 0, 0,};


struct node {
  int v[5][5];
  node() { memset(v, 0, sizeof v); }
  int* operator[] (int x) { return v[x]; }
  int& get (int a, int b) { return v[p[a]][p[b]]; }
  node(char c) {
    for(int i = 0; i < 5; i++) {
      for(int j = 0; j < 5; j++) v[i][j] = (i != j) ? (int)1e7 : 0;
    }
    switch(c) {
      case '2':
        get(2, 0) = 0;
        get(2, 2) = 1;
        break;
      case '0':
        get(0, 1) = 0;
        get(0, 0) = 1;
        break;
      case '1':
        get(1, 7) = 0;
        get(1, 1) = 1;
        break;
      case '7':
        get(7, 6) = 0;
        break;
      case '6':
        get(6, 6) = 1;
        get(7, 7) = 1;
        break;
      default:
        break;
    }
  }
  /*

 1del  1del  1del
  |     |     |     |
  2 --> 0 --> 1 --> 7 --> goal
              |
              |___> 6 --> fail
  */
};

node merge (node &a, node &b) {
  node ret;
  for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) {
    ret[i][j] = (int)1e7;
    for(int k = i; k <= j; k++)
      ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
  }
  return ret;
}

node tree[LEAF+LEAF+5];

node query (int x, int y) {
  x += LEAF; y += LEAF;
  node retl('g'), retr('g');
  while(x <= y) {
    if( x & 1) retl = merge(retl, tree[x++]);
    if(~y & 1) retr = merge(tree[y--], retr);
    x >>= 1; y >>= 1;
  }
  return merge(retl, retr);
}


int main() {
  scanf("%d%d%s", &N, &Q, S+1);
  for(int i = 1; i <= N; i++) {
    tree[LEAF+i] = node(S[i]);
  }
  for(int i = LEAF-1; i >= 1; i--) {
    tree[i] = merge(tree[i+i], tree[i+i+1]);
  }
  while(Q--) {
    int a, b; scanf("%d%d", &a, &b);
    int ans = query(a, b).get(2, 6);
    if(ans > N) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}