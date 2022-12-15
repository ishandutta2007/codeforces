#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <bits/stdc++.h>
#include <limits.h>
 
using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu;

const int N_ = 500015;
const int LEAF = 524288;

int N, Q;
vector<int> Tree[N_];
int F;
int S[N_], E[N_];

void DFS (int u, int p = -1) {
    int i;
    S[u] = ++F;
    for(i = 0; i < Tree[u].size(); i++) {
        int v = Tree[u][i];
        if(v != p) DFS(v, u);
    }
    E[u] = F;
}

int TIME;
int T1[LEAF+N_], T2[LEAF+N_];

void add (int u) {
    int x = S[u]+LEAF, y = E[u]+LEAF;
    while(x <= y) {
        if((x&1) == 1) T1[x] = max(T1[x], TIME);
        if((y&1) == 0) T1[y] = max(T1[y], TIME);
        x = (x+1) >> 1;
        y = (y-1) >> 1;
    }
}

void del (int x) {
    int u = S[x]+LEAF;
    while(u > 0) {
    	T2[u] = max(T2[u], TIME);
    	u >>= 1;
    }
}

bool chk (int u) {
    int t1 = 0, t2 = 0;
    int x, y;
    
    x = S[u]+LEAF;
    t1 = T1[x];
    while(x >>= 1) t1 = max(t1, T1[x]);
    
    x = S[u]+LEAF; y = E[u]+LEAF;
    while(x <= y) {
        if((x & 1) == 1) t2 = max(t2, T2[x]);
        if((y & 1) == 0) t2 = max(t2, T2[y]);
        x = (x+1) >> 1;
        y = (y-1) >> 1;
    }
    
    return t1 > t2;
}

int main() {
    int i, j, k;
    
    scanf("%d", &N);
    for(i = 1; i < N; i++) {
        int u, v; scanf("%d%d", &u, &v);
        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    DFS(1);
    
    scanf("%d", &Q);
    for(TIME = 1; TIME <= Q; TIME++) {
        int c, v; scanf("%d%d", &c, &v);
        if(c == 1) {
            add(v);
        }else if(c == 2) {
            del(v);
        }else {
            printf("%d\n", chk(v));
        }
    }
    
    
    return 0;
}