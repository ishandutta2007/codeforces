#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define PII pair <int, ll>
#define x first
#define y second
#define M 500010
#define addedge(x, y, z) Go[++Cnt] = y, Next[Cnt] = Head[x], Head[x] = Cnt, Val[Cnt] = z, Deg[y]++
using namespace std;
typedef long long ll;
int n, Head[M], Next[M], Go[M], Val[M], Deg[M], L[M], R[M], V[M], vis[M], T, Cnt = 0, St = 0;
ll Ans[M], F[M][2], totV = 0;
vector <PII> Sm[M], G[M];
bool cmp(int x, int y) {return Deg[x] > Deg[y];}
bool cmpP(PII x, PII y) {return Deg[x.x] > Deg[y.x];}
ll getpre(vector <PII> &A1, vector <PII> &V, int v) {
    ll tot = 0;
    for(int s = 0, i = 0, w = 0, nxt; i + 1 < V.size(); i = nxt) {
        for(nxt = i; nxt < V.size(); nxt++) {
            if(V[nxt].x >= 0 && V[nxt].x != V[i].x) break;
            tot += V[nxt].x * V[nxt].y, s += V[nxt].y;
        }
        int t = lower_bound(A1.begin(), A1.end(), PII(V[nxt].x, -1e18)) - A1.begin();
        if(t + s >= v) {t = max(v - s, w); return (t ? A1[t - 1].y : 0) + tot - (s + t - v) * max(V[i].x, 0);}
        w = t;
    }
}
void DFS(int x, int f) {
    vector <PII> V(1, PII(-1, 0));
    vis[x] = T + 1, V.push_back(PII(0, 0)), V.push_back(PII(1e6 + 5, 0));
    ll tot = 0, fv = 0;
    for(int i = 0, g = G[x][0].x; i < G[x].size() && Deg[g = G[x][i].x] > T; i++) {
        V.push_back(PII(G[x][i].y, -1));
        if(g != f) DFS(G[x][i].x, x), tot += F[g][0], V.push_back(PII(F[g][1] - F[g][0], 1)); else fv = G[x][i].y;
    }
    sort(V.begin(), V.end());
    F[x][1] = getpre(Sm[x], V, Deg[x] - T - 1) + fv + tot, F[x][0] = getpre(Sm[x], V, Deg[x] - T) + tot;
}
int main() {
    scanf("%d", &n);
    vector <int> S(0);
    for(int i = 1, a, b, c; i < n; i++)
        scanf("%d%d%d", &L[i], &R[i], &V[i]), addedge(a = L[i], b = R[i], c = V[i]), addedge(b, a, c), totV += c,
        G[a].push_back(PII(b, c)), G[b].push_back(PII(a, c)),
        Sm[a].push_back(PII(c, 0)), Sm[b].push_back(PII(c, 0));
    for(int i = 1; i <= n; i++) S.push_back(i);
    for(int i = 1; i <= n; i++) if(Sm[i].size()) {
        sort(G[i].begin(), G[i].end(), cmpP), sort(Sm[i].begin(), Sm[i].end()), Sm[i][0].y = Sm[i][0].x;
        for(int j = 1; j < Sm[i].size(); j++) Sm[i][j].y = Sm[i][j - 1].y + Sm[i][j].x;
    }
    sort(S.begin(), S.end(), cmp);
    for(T = n - 1; T >= 1; T--) {
        while(St != S.size() && Deg[S[St]] > T) St++;
        ll ans = 0;
        for(int i = 0; i < St; i++) if(vis[S[i]] != T + 1) DFS(S[i], -1), ans += F[S[i]][0];
        Ans[T] = ans;
    }
    Ans[0] = totV;
    for(int i = 0; i < n; i++) printf("%lld ", Ans[i]);
}