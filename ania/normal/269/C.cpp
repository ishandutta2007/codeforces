#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 200100;
bool vis[maxn];
int res[maxn];
int sum[maxn];
vector<pair<int,pii> > g[maxn];
queue<int> q;

void proc(int u) {
    vis[u] = true;
    FOR(i,g[u].size()) {
        int v = g[u][i].fi;
        int w = g[u][i].se.fi;
        int it = g[u][i].se.se;
        if (vis[v]) {
            continue;
        }
        if (it > 0) {
            res[it-1] = 0;
        } else {
            res[-1-it] = 1;
        }
        sum[v] -= 2*w;
        //printf("u = %d, w = %d, sum[%d] = %d, it = %d\n", u, w, v, sum[v], it);
        if (sum[v] == 0) {
            q.push(v);
        }
    }
}

int main() {
    int n,m,a,b,c;
    scanf("%d%d", &n, &m);
    FOR(i,m) {
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        g[a].push_back(make_pair(b, make_pair(c,i+1)));
        g[b].push_back(make_pair(a, make_pair(c,-i-1)));
        sum[a] += c;
        sum[b] += c;
    }
    /*
    FOR(i,n) {
        FOR(j,g[i].size()) {
            printf("%d -> %d (%d, %d)\n", i, g[i][j].fi, g[i][j].se.fi, g[i][j].se.se);
        }
    }
    */
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u != n-1) {
            proc(u);
        }
    }
    FOR(i,m) {
        printf("%d\n", res[i]);
    }
	return 0;
}