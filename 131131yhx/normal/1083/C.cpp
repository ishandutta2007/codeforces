#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 400010
#define PI pair <int, int>
#define f first
#define s second

using namespace std;

int Head[M], Next[M], Go[M], Fa[M][22], Dep[M], Cnt = 0, n, P[M], Sym[M];

void addedge(int a, int b) {
    Go[++Cnt] = b;
    Next[Cnt] = Head[a];
    Head[a] = Cnt;
}

void DFS(int x, int f = 0, int dep = 1) {
    Fa[x][0] = f;
    Dep[x] = dep;
    for(int T = Head[x]; T; T = Next[T]) if(Go[T] != f)
        DFS(Go[T], x, dep + 1);
}

int lca(int x, int y) {
    if(Dep[x] < Dep[y]) swap(x, y);
    int det = Dep[x] - Dep[y];
    for(int i = 18; i >= 0; i--)
        if((det >> i) & 1) x = Fa[x][i];
    if(x == y) return x;
    for(int i = 18; i >= 0; i--)
        if(Fa[x][i] != Fa[y][i]) x = Fa[x][i], y = Fa[y][i];
    return Fa[x][0];
}

int dis(int x, int y) {return Dep[x] + Dep[y] - 2 * Dep[lca(x, y)];}

PI S[M * 4];

int F[M * 4];

void merge(PI A, PI B, PI &C, int &d) {
    int Ds[4][4], O[4];
    O[0] = A.f;
    O[1] = A.s;
    O[2] = B.f;
    O[3] = B.s;
    for(int i = 0; i < 4; i++) Ds[i][i] = 0;
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++)
            Ds[j][i] = (Ds[i][j] = dis(O[i], O[j]));
    int mx = 0;
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++)
            mx = max(mx, Ds[i][j]);
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++) if(Ds[i][j] == mx) {
            int dd = Ds[i][j];
            for(int k = 0; k < 4; k++)
                if(Ds[i][k] + Ds[k][j] != dd) {d = 0; return;}
            d = 1, C = PI(O[i], O[j]); return;
        }
    d = 1, C = PI(O[0], O[0]);
}

void build(int x, int L, int R) {
    if(L == R) {
        S[x] = PI(Sym[L], Sym[L]);
        F[x] = 1;
        return;
    }
    int md = (L + R) / 2;
    build(x * 2, L, md);
    build(x * 2 + 1, md + 1, R);
    if(F[x * 2] && F[x * 2 + 1]) merge(S[x * 2], S[x * 2 + 1], S[x], F[x]); else F[x] = 0;
}

void modify(int x, int L, int R, int w, int v) {
    if(L == R) {
        S[x] = PI(v, v);
        F[x] = 1;
        return;
    }
    int md = (L + R) / 2;
    if(w <= md) modify(x * 2, L, md, w, v);
    else modify(x * 2 + 1, md + 1, R, w, v);
    if(F[x * 2] && F[x * 2 + 1]) merge(S[x * 2], S[x * 2 + 1], S[x], F[x]);  else F[x] = 0;
}

PI SS;

int ask(int x, int L, int R) {
    /*for(int i = L; i <= R; i++) {
        PI AA;
        int bb;
        merge(SS, PI(Sym[i], Sym[i]), AA, bb);
        if(bb) {
            SS = AA;
        } else return i;
    }
    return n;*/
    if(F[x] == 1) {
        PI AA;
        int bb;
        merge(SS, S[x], AA, bb);
        if(bb) {
            SS = AA;
            return -1;
        }
    }
    if(L == R) return L;
    int md = (L + R) / 2;
    int tmp = ask(x * 2, L, md);
    if(tmp == -1) return ask(x * 2 + 1, md + 1, R);
    return tmp;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &P[i]), Sym[P[i]] = i;
    for(int i = 2; i <= n; i++) {
        int d;
        scanf("%d", &d);
        addedge(d, i);
        addedge(i, d);
    }
    DFS(1);
    for(int i = 0; i <= 17; i++)
        for(int j = 1; j <= n; j++)
            Fa[j][i + 1] = Fa[Fa[j][i]][i];
    build(1, 1, n - 1);
    int q;
    scanf("%d", &q);
    while(q--) {
        int op;
        scanf("%d", &op);
        if(op == 2) {
            SS = PI(Sym[0], Sym[0]);
            int ans = ask(1, 1, n - 1);
            if(ans == -1) printf("%d\n", n); else printf("%d\n", ans);
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            int c = P[a], d = P[b];
            swap(Sym[c], Sym[d]);
            if(c) modify(1, 1, n - 1, c, b);
            if(d) modify(1, 1, n - 1, d, a);
            swap(P[a], P[b]);
        }
    }
    return 0;
}