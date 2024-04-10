#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 5016
#define inf 2000000000

int n, m, i, x, y, cnt;
vector<int> to[maxN], from[maxN];
vector< vector<int> > comp;
vector<int> aux;
bool us[maxN];
stack<int> S;
int belong[maxN];
bool leaf[maxN];

queue<int> Q;
int dist[maxN];

int ans;



void dfs_to(int node) {
    us[node] = true;
    for (auto e : to[node])
        if (!us[e])
            dfs_to(e);
    S.push(node);
}

void dfs_from(int node) {
    us[node] = true;
    belong[node] = cnt;
    aux.pb(node);

    for (auto e : from[node])
        if (!us[e])
            dfs_from(e);
}

int small_cycle(int id) {
    int i;
    int ans = comp[id].size();
    int act;

    aux = comp[id];

    for (int base : aux) {
        act = inf;
        for (int e : aux)
            dist[e] = inf;


        dist[base] = 0;
        Q.push(base);

        while (!Q.empty()) {
            int node = Q.front(); Q.pop();
            for (auto e : to[node]) {
                if (e == base) act = min(act, dist[node] + 1);
                if (dist[e] != inf) continue;
                dist[e] = dist[node] + 1;
                Q.push(e);
            }
        }

        ans = min(ans, act);
    }

    return ans * 999 + 1 + aux.size() - ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++) {
        scanf("%d%d", &x, &y);
        to[x].pb(y);
        from[y].pb(x);
    }

    for (i = 1; i <= n; i++)
        if (!us[i])
            dfs_to(i);

    memset(us, 0, sizeof(us));
    while (!S.empty()) {
        int node = S.top(); S.pop();
        if (us[node]) continue;

        aux.clear();
        dfs_from(node);
        comp.pb(aux);
        cnt++;
    }

    for (i = 0; i < comp.size(); i++) leaf[i] = true;
    for (i = 1; i <= n; i++)
        for (int e : to[i])
            if (belong[i] != belong[e])
                leaf[ belong[i] ] = false;

    for (i = 0; i < comp.size(); i++) {
        if (!leaf[i] || comp[i].size() == 1)
            ans += comp[i].size();
        else
            ans += small_cycle(i);
    }

    printf("%d", ans);

    return 0;
}