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
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <list>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 100500;

int N;
vector<int> tree[N_];
int parent[N_];
int sz[N_];
ll cnt[N_];
int num[N_];
int length[N_];
int nd[N_];
int Q;

void dfs (int u, int p = -1) {
    sz[u] = 1;
    parent[u] = p;
    for(int e = 0; e < tree[u].size(); e++) {
        int v = tree[u][e];
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        cnt[v] = (ll)sz[v] * (N - sz[v]) * 2;
        length[u] ^= length[v];
        num[u] ^= num[v];
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N-1; i++) {
        int u, v, l; scanf("%d%d%d", &u, &v, &l);
        tree[u].push_back(v);
        tree[v].push_back(u);
        length[u] ^= l;
        length[v] ^= l;
        num[u] ^= i;
        num[v] ^= i;
    }
    
    dfs(1);
    
    ll ans = 0;
    for(int i = 2; i <= N; i++) {
        ans += cnt[i] * length[i];
        nd[num[i]] = i;
    }
    
    lf factor = 3. / ((lf)N * (N-1));
    
    scanf("%d", &Q);
    while(Q--) {
        int e, d; scanf("%d%d", &e, &d);
        int u = nd[e];
        ans += cnt[u] * (d - length[u]);
        length[u] = d;
        printf("%.10lf\n", (lf)ans * factor);
    }
    
    return 0;
}