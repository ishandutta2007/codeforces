#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e7 + 10;
const int M = 800;
const int inf = 1e8;

int n;
char str[N]; int st[M], ed[M];

int rt, tot, ch[N][2], fail[N], fa[N], pre[N], num[N];
void insert(int id){
    int u = rt;
    for (int i = st[id]; i <= ed[id]; i ++){
        int nxt = str[i] - 'a';
        if (!ch[u][nxt]) ch[u][nxt] = ++ tot, fa[tot] = u, pre[tot] = nxt;
        u = ch[u][nxt];
        if (i == ed[id]) num[u] = id;
    }
}

int head, tail, que[N]; 
void call_fail(){
    head = tail = 0;
    que[tail = 1] = rt;
    while (head < tail){
        int u = que[++ head];

        for (int i = 0; i < 2; i ++)
            if (ch[u][i]) que[++ tail] = ch[u][i];
        int p = fa[u];
        while (u != rt && p != rt && !ch[fail[p]][pre[u]]) p = fail[p];
        if (p == rt) continue;
        fail[u] = ch[fail[p]][pre[u]];

        if (!num[u]) num[u] = num[fail[u]];
    }
}

int s, t, G[M][M];
int cnt = 1, lst[M * 2], cur[M * 2], nxt[N], to[N], f[N];
void add(int u, int v, int flow){
    nxt[++ cnt] = lst[u]; lst[u] = cnt; to[cnt] = v; f[cnt] = flow;
    nxt[++ cnt] = lst[v]; lst[v] = cnt; to[cnt] = u; f[cnt] = 0;
}

void link(int id){
    int u = rt;
    for (int i = st[id]; i <= ed[id]; i ++){
        int nxt = str[i] - 'a';
        u = ch[u][nxt];

        int tmp = i != ed[id] ? u : fail[u];
        if (num[tmp]){
            G[id][num[tmp]] = 1;
        }

    }
}

int d[N];
bool bfs(){
    head = tail = 0;
    for (int i = 1; i <= t; i ++) d[i] = 0;
    que[tail = 1] = s; d[s] = 1;
    while (head < tail){
        int u = que[++ head];
        for (int j = lst[u]; j; j = nxt[j]){
            int v = to[j];
            if (!d[v] && f[j]){
                d[v] = d[u] + 1;
                que[++ tail] = v;
                if (v == t) return 1;
            }

        }
    }
    return 0;
}
int dfs(int u, int flow){
    if (u == t) return flow;
    int ret = 0, a;
    for (int &j = cur[u]; j; j = nxt[j]){
        int v = to[j];

        if (d[v] == d[u] + 1 && flow && f[j] && (a = dfs(v, min(flow, f[j])))){
            ret += a, f[j] -= a;
            flow -= a, f[j ^ 1] += a;
        }
    }
    return ret;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++){
        st[i] = ed[i - 1] + 1;
        scanf("%s", str + st[i]);
        ed[i] = strlen(str + st[i]) + st[i] - 1;

        insert(i);
    }

    call_fail();

    for (int i = 1; i <= n; i ++) link(i);


    for (int k = 1; k <= n; k ++)
        for (int i = 1; i <= n; i ++)
            if (i != k) for (int j = 1; j <= n; j ++)
                            if (j != k && j != i) G[i][j] |= (G[i][k] && G[k][j]);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if (G[i][j] && i != j) add(i, j + n, 1);


    s = n * 2 + 1, t = s + 1;
    for (int i = 1; i <= n; i ++)
        add(s, i, 1), add(i + n, t, 1);

    int ans = n;

    while (bfs()){
        for (int i = 1; i <= t; i ++) cur[i] = lst[i];
        ans -= dfs(s, inf);
    }

    printf("%d\n", ans);

    for (int i = 1; i <= n; i ++)
        if (d[i] && !d[i + n]) printf("%d ", i);


    return 0;
}