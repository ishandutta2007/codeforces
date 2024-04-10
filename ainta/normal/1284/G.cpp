#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, Num[30][30], cnt, EC, vis[1010], Deg[1010], chk[1010], CK[1000], isEven[1010];
char p[30][30], Res[50][50];
vector<int>Even, G[1010], E[1010];
struct Edge {
    int a, b;
}Z[1010];
vector<Edge>Ed;
void DFS(int a) {
    vis[a] = 1;
    for (auto &x : G[a]) {
        if (!vis[x])DFS(x);
    }
}
bool OK1() {
    int i;
    for (i = 1; i <= cnt; i++) {
        G[i].clear();
        vis[i] = 0;
    }
    for (i = 0; i < EC; i++) {
        if (!chk[i]) {
            G[Ed[i].a].push_back(Ed[i].b);
            G[Ed[i].b].push_back(Ed[i].a);
        }
    }
    DFS(1);
    for (i = 1; i <= cnt; i++)if (!vis[i])return false;
    return true;
}
bool OK2(){
    int i;
    for (i = 1; i <= cnt; i++)Deg[i] = 0;
    for (i = 0; i < EC; i++)if (!chk[i])Deg[Ed[i].a]++, Deg[Ed[i].b]++;
    for (auto &t : Even) {
        if (Deg[t] < 2)return false;
    }
    return true;
}
int Q[1010], Path[1010];
bool Pos() {
    int i, j, TP[4], k;
    for (i = 0; i < EC; i++)E[i].clear(), CK[i] = 0;
    for (i = 0; i < EC; i++){
        if(!chk[i]){
            chk[i] = 1;
            if(OK1() && OK2())return true;
            chk[i] = 0;
        }
    }
    for (i = 0; i < EC; i++) {
        if (!chk[i]) {
            chk[i] = 1;
            if (OK1()) CK[i] |= 1;
            if (OK2()) CK[i] |= 2;
            chk[i] = 0;
            TP[0] = Ed[i].a, TP[1] = Ed[i].b;
            for (j = 0; j < EC; j++) {
                if (chk[j]) {
                    int ck1 = 0, ck2 = 1;
                    if ((CK[i] & 1) || (vis[Ed[j].a] != vis[Ed[j].b])) ck1 = 1;
                    TP[2] = Ed[j].a, TP[3] = Ed[j].b;
                    Deg[TP[2]]++, Deg[TP[3]]++;
                    for (k = 0; k < 4; k++) {
                        if (isEven[TP[k]] && Deg[TP[k]] < 2)ck2 = 0;
                    }
                    Deg[TP[2]]--, Deg[TP[3]]--;
                    if (ck1)E[j].push_back(i);
                    if (ck2) E[i].push_back(j);
                }
            }
        }
    }
    int head = 0, tail = 0, ed = -1;
    for (i = 0; i < EC; i++) {
        vis[i] = 0;
        Path[i] = -1;
        if (CK[i] & 1) {
            Q[++tail] = i;
            vis[i] = 1;
        }
    }
    while (head < tail) {
        int x = Q[++head];
        if (CK[x] & 2) {
            ed = x;
            break;
        }
        for (auto &y : E[x]) {
            if (!vis[y]) {
                Q[++tail] = y;
                vis[y] = 1;
                Path[y] = x;
            }
        }
    }
    if (ed == -1)return false;
    int t = ed;
    while (t != -1) {
        chk[t] = !chk[t];
        t = Path[t];
    }
    return true;
}
void Solve() {
    int i, j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%s", p[i]);
    }
    for (i = 0; i < 1000; i++)isEven[i] = 0;
    cnt = 0;
    Even.clear();
    Ed.clear();
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (p[i][j] == 'O') {
                Num[i][j] = ++cnt;
                Z[cnt] = { i,j };
                if ((i || j) && (i + j) % 2 == 0) {
                    Even.push_back(Num[i][j]);
                    isEven[Num[i][j]] = 1;
                }
                if (i && p[i - 1][j] == 'O') {
                    Ed.push_back({ Num[i - 1][j], Num[i][j] });
                }
                if (j && p[i][j - 1] == 'O') {
                    Ed.push_back({ Num[i][j - 1], Num[i][j] });
                }
            }
        }
    }
    EC = Ed.size();
    for (i = 0; i < EC; i++)chk[i] = 0;
    vector<int>T;
    if (!OK1() || !OK2()) {
        puts("NO");
        return;
    }
    while (Pos());
    int cc = 0;
    for (i = 0; i < EC; i++) {
        if (!chk[i])cc++;
    }
    if (cc != cnt - 1) {
        puts("NO");
        return;
    }
    puts("YES");
    for (i = 0; i < 2 * n; i++) {
        for (j = 0; j < 2 * m-1; j++) {
            Res[i][j] = ' ';
        }
        Res[i][j] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            Res[i * 2][j * 2] = p[i][j];
        }
    }
    for (i = 0; i < EC; i++) {
        if (!chk[i]) {
            Edge p1 = Z[Ed[i].a], p2 = Z[Ed[i].b];
            Res[p1.a + p2.a][p1.b + p2.b] = 'O';
        }
    }
    for (i = 0; i < 2 * n - 1; i++)printf("%s\n", Res[i]);
}
int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        Solve();
    }
}