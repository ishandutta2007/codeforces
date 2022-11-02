#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#define LL long long
#define pb push_back
#define F first
#define S second
#define sz(c) (int)c.size()
#define mp make_pair
#define f first
#define s second
const int inf = (1ll << 30) - 1;
typedef long long ll;

using namespace std;

const long  double eps = 1e-15L;
int P[20][1000100];
vector<int> g[1000100];
int n;
int timer = 0;
int lev[1000100];

void dfs(int v, int p){
    P[0][v] = p;
    //1 --> 2 --> 3
    lev[v] = lev[p] + 1;
    for(int i = 1; i < 20; i++) P[i][v] = P[i-1][P[i-1][v]];
    for(auto to: g[v]){
        if(to == p) continue;
        dfs(to, v);
    }
}

int u[1000100];
int k;
int main(){
    cin >> n >> k;
    k = n - k;
    for(int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(n, 0);
    u[0] = 1;
    for(int i = n; i>=1; i--){
        if(u[i]) continue;
        int v = i;
        for(int j = 19; j >= 0; j--){
            if(!u[P[j][v]]) v = P[j][v];
        }
        v = P[0][v];
        if(lev[i] - lev[v] <= k){
            int x = i;
            while(x != v) {
                u[x] = 1;
                x = P[0][x];
                k--;
            }
        }
        //cout << k << " ";
    }
    for(int i = 1; i <= n; i++) if(!u[i]) cout << i << " ";
    return 0;
}