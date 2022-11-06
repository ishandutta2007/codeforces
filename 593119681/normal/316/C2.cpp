#include <cstdio>
#define N 80 + 5
#define D 6400 + 5
#define M 100000 + 5
#define INF 0x7fffffff

const int Fx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, S, T, cnt, tot = 1, ans;
int Id[N][N], A[N][N];
int Head[D], Dis[D], f[D], Inq[D];
int q[M];

struct Edge
{
    int next, node, flow, w;
}h[M];

inline void addedge(int u, int v, int fl, int w)
{
    h[++ tot].next = Head[u], Head[u] = tot;
    h[tot].node = v, h[tot].flow = fl, h[tot].w = w;
    h[++ tot].next = Head[v], Head[v] = tot;
    h[tot].node = u, h[tot].flow = 0, h[tot].w = -w;
}

inline bool SPFA()
{
    for (int i = S; i <= T; i ++)
        Dis[i] = INF, Inq[i] = 0;
    int l = 1, r = 1;
    Dis[S] = 0, q[1] = S, Inq[S] = 1;
    while (l <= r)
    {
        int z = q[l ++];
        Inq[z] = 0;
        for (int i = Head[z]; i; i = h[i].next)
        {
            int d = h[i].node, p = h[i].flow, w = h[i].w;
            if (!p) continue ;
            if (Dis[d] > Dis[z] + w)
            {
                Dis[d] = Dis[z] + w;
                f[d] = i;
                if (!Inq[d])
                {
                    q[++ r] = d;
                    Inq[d] = r;
                }
            }
            if (Inq[d] && Dis[d] < Dis[q[l]])
            {
                int u = q[l], v = Inq[d];
                q[l] = d, q[v] = u;
                Inq[d] = l, Inq[u] = v;
            }
        }
    }
    return Dis[T] != INF;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    scanf("%d%d", &n, &m);
    S = 0, T = n * m + 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
        {
            scanf("%d", A[i] + j);
            Id[i][j] = ++ cnt;
        }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (i + j & 1)
            {
                addedge(S, Id[i][j], 1, 0);
                for (int k = 0; k < 4; k ++)
                {
                    int tx = i + Fx[k][0], ty = j + Fx[k][1];
                    if (tx && ty && tx <= n && ty <= m)
                        addedge(Id[i][j], Id[tx][ty], 1, A[i][j] != A[tx][ty]);
                }
            }
            else addedge(Id[i][j], T, 1, 0);
    while (SPFA())
        for (int x = T; x != S; x = h[f[x] ^ 1].node)
        {
            ans += h[f[x]].w;
            h[f[x]].flow --;
            h[f[x] ^ 1].flow ++;
        }
    printf("%d\n", ans);
    
    #ifndef ONLINE_JUDGE
        fclose(stdin);
        fclose(stdout);
    #endif
    return 0;
}