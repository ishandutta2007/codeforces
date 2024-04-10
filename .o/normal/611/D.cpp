#define _CRT_SECURE_NO_WARNINGS
      
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
      
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
      
const int N_ = 5005, lgN_ = 16;
char S[N_]; int N;
      
int SA[N_], CP[lgN_][N_+N_];
int start[N_], lnk[N_], temp[N_];
      
int RMQ[lgN_][N_+N_];
int lg2[N_];
      
      // from http://oj.uz/submission/14231
      
void build_suffix_array() {
    for(int i = 1; i <= N; i++) SA[i] = i, CP[0][i] = S[i] - '0' + 2;
    for(int k = 0; k+1 < lgN_; k++) {
        for(int c = 1; c >= 0; c--) {
            for(int i = N; i > 0; i--) {
                int x = SA[i] + (c<<k); if(x > N) x = 0;
                int v = CP[k][x];
                lnk[i] = start[v]; start[v] = i;
                temp[i] = SA[i];
            }
            for(int i = 0, p = 0; i <= N || i <= 26; i++) {
                for(int j = start[i]; j > 0; j = lnk[j]) SA[++p] = temp[j];
                start[i] = -1;
            }
        }
              
        int *now = CP[k], *nxt = CP[k+1];
        nxt[SA[1]] = 1;
        for(int i = 2, v = 1; i <= N; i++) {
            int ap = now[SA[i-1]], bp = now[SA[i]];
            int an = (SA[i-1] + (1<<k) <= N) ? now[SA[i-1] + (1<<k)] : 0;
            int bn = (SA[i] + (1<<k) <= N) ? now[SA[i] + (1<<k)] : 0;
            if(ap < bp || (ap == bp && an < bn)) ++v;
            nxt[SA[i]] = v;
        }
    }
}
      
int lcp_logn (int x, int y) {
    int r = 0;
    if(x == y) return N-x+1;
    for(int k = lgN_; --k >= 0; ) {
        if(CP[k][x+r] == CP[k][y+r]) r += 1<<k;
    }
    return r;
}
      
void build_lcp () {
    for(int i = 1; i < N; i++) RMQ[0][i] = lcp_logn(SA[i], SA[i+1]);
    for(int i = 1, v = 0; i <= N; i++) v += (i>>v), lg2[i] = v-1;
      
    for(int k = 1; k < lgN_; k++) {
        for(int i = 1; i + (1<<k) - 1 <= N - 1; i++) RMQ[k][i] = min(RMQ[k-1][i], RMQ[k-1][i + (1<<(k-1))]);
    }
}
      
int lcp_constant (int x, int y) {
    if(x == y) return N-x+1;
      
    x = CP[lgN_-1][x]; y = CP[lgN_-1][y];
    if(x > y) swap(x, y);
    int l = y-x; int k = lg2[l];
    return min(RMQ[k][x], RMQ[k][y-(1<<k)]);
}

int cmp (int a, int b, int maxlength = N) {
    int l = lcp_constant(a, b);
    if(l >= maxlength) return 0; 
    return S[l + a] < S[l + b];
}

ll tb[N_][N_];
const ll MOD = (ll)1e9 + 7;    
ll res;
      
int main() {
    scanf("%d%s", &N, S+1);
      
    build_suffix_array();
    build_lcp();
      
for(int i = N; i > 0; i--) {
 tb[i][N] = 1;
 for(int j = N-1; j >= i; j--) {
  tb[i][j] = tb[i][j+1];
  int next_pos = j + (j-i+1);
  if(S[j+1] != '0' && next_pos <= N) { 
   tb[i][j] += tb[j+1][next_pos + !cmp(i, j+1, j-i+1)];
   tb[i][j] %= MOD;
  }
 }
}

printf("%lld\n", tb[1][1]);
    return 0;
}