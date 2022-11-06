#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const int maxN = 100011;
const int maxK = 111;

int n, m, k, s, i, j, x, y;
int a[maxN], dp[maxK][maxN];
vector<int> wh[maxN];
vector<int> list[maxN];
queue<int> Q;
vector<int> aux;

void pre(int tp) {
    int i;

    for (auto e : wh[tp]) {
        dp[tp][e] = 1;
        Q.push(e);
    }

    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        for (auto to : list[node]) {
            if (dp[tp][to] > 0) continue;
            dp[tp][to] = dp[tp][node] + 1;
            Q.push(to);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%d", &n, &m, &k, &s);
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        wh[a[i]].pb(i);
    }
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        list[x].pb(y);
        list[y].pb(x);
    }

    for (i = 1; i <= k; i++)
        pre(i);

    for (i = 1; i <= n; i++) {
        aux.clear();
        for (j = 1; j <= k; j++) aux.pb(dp[j][i]);
        sort(aux.begin(), aux.end());

        int ans = 0;
        for (j = 0; j < s; j++) ans += aux[j];
        printf("%d ", ans - s);
    }

    return 0;
}