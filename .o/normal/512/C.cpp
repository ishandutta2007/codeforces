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

int n, a[500];
bool P[25000];

int cap[205][205];

bool visited[205];

int find_aug (int u) {
    if(visited[u]) return 0;
    if(u > n) return 1;

    visited[u] = true;
    for(int v = 1; v <= n+1; v++) if(!visited[v] && cap[u][v] > 0) {
        int c = min(find_aug(v), cap[u][v]);
        if(c > 0) {
            cap[u][v] -= c;
            cap[v][u] += c;
            return c;
        }
    }
    
    return 0;
}

bool gph[205][205];

vector<vector<int> > ans;

void dfs (int u, vector<int> &a) {
    a.push_back(u);
    visited[u] = true;
    for(int v = 1; v <= n; v++) {
        if(gph[u][v] && !visited[v]) {
            visited[v] = true;
            dfs(v, a);
        }
    }
}

int main() {
    for(int i = 2; i <= 20000; i++) P[i] = true;
    for(int p = 2; p <= 20000; p++) if(P[p]) {
        for(int i = p+p; i <= 20000; i += p) P[i] = false;
    }
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a+i);
    
    for(int i = 1; i <= n; i++) {
        if(a[i] % 2 == 0) cap[i][n+1] = 2;
        else {
            cap[0][i] = 2;
            for(int j = 1; j <= n; j++) {
                if(a[j] % 2 == 0 && P[a[i] + a[j]]) cap[i][j] = 1;
            }
        }
    }
    
    for(int rep = 1; rep <= n; rep++) {
        int c = find_aug(0);
        if(c == 0) return 0 & puts("Impossible");
        memset(visited, 0, sizeof visited);
    }
    
    
    for(int i = 1; i <= n; i++) if(a[i] % 2 == 1){
        for(int j = 1; j <= n; j++)  if(a[j] % 2 == 0) {
            if(P[a[i] + a[j]] && cap[i][j] == 0) gph[i][j] = gph[j][i] = true;//, printf("%d %d\n",i,j);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            vector<int> a; dfs(i, a);
            ans.push_back(a);
        }
    }
    
    printf("%u\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%u", ans[i].size());
        for(int j = 0; j < ans[i].size(); j++) {
            printf(" %d", ans[i][j]);
            assert(P[a[ans[i][j]] + a[ans[i][(j+1)%ans[i].size()]]]);
        }
        puts("");
    }
    
    return 0;
}