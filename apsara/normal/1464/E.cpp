#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 998244353;
const int p = P;
const int V = 100100;
vector<int> g[V];
int sg[V];

int Pow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        y /= 2; x = (LL) x * x % P;
    }
    return res;
}

int dfs(int u) {
    if(sg[u] != -1) return sg[u];
    vector<int> nxt;
    nxt.PB(-1);
    nxt.PB(1e9);
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        nxt.PB(dfs(v));
    }
    sort(nxt.begin(), nxt.end());
    for (int i = 1; i < nxt.size(); ++i) if (nxt[i] > nxt[i - 1] + 1) {sg[u] = nxt[i - 1] + 1; break;}
    return sg[u];
}

LL a[5000][5000], ans[5000];

void solve(int n) {
    int maxi;
    LL tmp;
    for(int i=1;i<=n;i++)
	{
		if(!a[i][i])
		{
			maxi=0;
			for(int j=i+1;j<=n&&!maxi;j++)
				if(a[j][i]) maxi=j;
			if(!maxi) continue;
			for(int j=i;j<=n+1;j++)
				tmp=a[maxi][j],a[maxi][j]=a[i][j],a[i][j]=tmp;
		}
		for(int j=i+1;j<=n;j++)
		{
			tmp=a[j][i];
			if(!tmp) continue;
			for(int k=i;k<=n+1;k++)
				a[j][k]=((a[j][k]*a[i][i]-a[i][k]*tmp)%p+p)%p;
		}
	}
	for(int i=n;i;i--)
	{
		for(int j=i+1;j<=n;j++)
			a[i][n+1]=((a[i][n+1]-ans[j]*a[i][j])%p+p)%p;
		ans[i]=a[i][n+1]*Pow(a[i][i],p-2)%p;
	}
	//for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]); puts("ANS");
}

void PT(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n + 1; ++j) printf("%I64d ", a[i][j]); puts("");
    }
}
int cnt[V], Q[V], vis[V], pos[V];
int n, m, u, v;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            g[u].PB(v);
        }
        memset(sg, -1, sizeof(sg));
        memset(cnt, 0, sizeof(cnt));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i) cnt[dfs(i)]++;
        //for (int i = 1; i <= n; ++i) printf("%d ", sg[i]); puts("");
        vector<int> mv;
        for (int i = 0; i <= n; ++i) if (cnt[i] > 0) mv.PB(i);
        //for (int i = 0; i < mv.size(); ++i) printf("%d ", mv[i]); puts("");
        int top = 0, tail = 0;
        Q[++tail] = 0;
        vis[0] = 1;
        pos[0] = 1;
        while (top != tail) {
            u = Q[++top];
            //printf("Q %d\n", u);
            for (int i = 0; i < mv.size(); ++i) {
                v = u ^ mv[i];
                if (!vis[v]) {
                    vis[v] = 1;
                    Q[++tail] = v;
                    pos[v] = tail;
                }
            }
        }
        int all = Pow(n + 1, P - 2);
        //printf("ALL %d\n", all);
        for (int i = 1; i <= tail; ++i) {
            //a[i][tail + 1] = Q[i] == 0 ? 0 : (P - all) % P;
            a[i][tail + 1] = Q[i] == 0 ? 0 : all % P;
            for (int j = 1; j <= tail; ++j) {
                a[i][j] = (P - (LL) cnt[Q[i] ^ Q[j]] * all % P) % P;
            }
            a[i][i] = (P + 1 - (LL) cnt[0] * all % P) % P;
        }

        //PT(tail);
        solve(tail);
        printf("%I64d\n", ans[1]);
    }
    return 0;
}

/*
1 0

2 1
1 2

5 5
1 4
5 2
4 3
1 5
5 4
*/