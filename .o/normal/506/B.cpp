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
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int N_ = 100500;

int N, M;
vector<int> gph[N_], rev[N_], bth[N_];
int outdg[N_], indg[N_];
bool visited[N_];

vector<int> ord;

void dfs (int u) {
    visited[u] = true;
    for(int i = 0; i < gph[u].size(); i++) {
        int v = gph[u][i];
        if(!visited[v]) dfs(v);
    }
    ord.push_back(u);
}

queue<int> que;

int grp[N_], gn;
int c1[N_], c2[N_];


void dfs2 (int u) {
    visited[u] = true;
    ++c1[gn]; grp[u] = gn;
    for(int i = 0; i < bth[u].size(); i++) {
        int v = bth[u][i];
        if(!visited[v]) dfs2(v);
    }
}

int cnt3;
void dfs3 (int u) {
    visited[u] = true;
    ++cnt3;
    for(int i = 0; i < rev[u].size(); i++) {
        int v = rev[u][i];
        if(!visited[v]) dfs3(v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    
    scanf("%d%d", &N, &M);
    for(int e = 1; e <= M; e++) {
        int u, v; scanf("%d%d", &u, &v);
        gph[u].push_back(v);
        rev[v].push_back(u);
        bth[u].push_back(v);
        bth[v].push_back(u);
        ++outdg[u]; ++indg[v];
    }
    
    memset(visited, 0, sizeof visited);
    for(int i = 1; i <= N; i++) if(!visited[i]) dfs(i);
    
    memset(visited, 0, sizeof visited);
    for(int i = 1; i <= N; i++) if(!visited[i]) {
        ++gn; dfs2(i);
    }
    
    memset(visited, 0, sizeof visited);
    for(int i = ord.size(); i--; ) {
        int u = ord[i];
        if(!visited[u]) {
            cnt3 = 0;
            dfs3(u);
            if(cnt3 >= 2) c2[grp[u]] += 1;
        }
    }
    
    int ans = 0;
    for(int g = 1; g <= gn; g++) {
        c2[g] += c1[g] - 1;
        ans += min(c1[g], c2[g]);
    }
    
    printf("%d\n", ans);
    return 0;
}