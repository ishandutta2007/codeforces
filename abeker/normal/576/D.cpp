#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector < vector <ll> > vvll;

const int MAXN = 155;
const int INF = 0x3f3f3f3f;

struct edge {
    int a, b, d;
    edge(int a, int b, int d) : a(a), b(b), d(d) {}
    edge() : a(0), b(0), d(0) {}
    bool operator <(const edge &rhs) const {
        if (d != rhs.d) return d < rhs.d;
        if (a != rhs.a) return a < rhs.a;
        return b < rhs.b;
    }
};

int N, M;
vector <edge> V;
vector <int> E[MAXN];
int dist[MAXN];

struct matrix {
    int a[MAXN][MAXN];
    matrix() {
        memset(a, 0, sizeof a);
    }
    void identity() {
        for (int i = 0; i < N; i++)
            a[i][i] = 1;
    }
    vvll rows() {
        vvll res(N);
        for (int i = 0; i < N; i++) {
            res[i].resize(3);
            for (int j = 0; j < N; j++)
                if (a[i][j]) res[i][j / 63] |= 1ll << j % 63;
        }
        return res;
    }
    vvll cols() {
        vvll res(N);
        for (int j = 0; j < N; j++) {
            res[j].resize(3);
            for (int i = 0; i < N; i++)
                if (a[i][j]) res[j][i / 63] |= 1ll << i % 63;
        }
        return res;
    }
    void output() const {
        for (int i = 0; i < N; i++, puts(""))
            for (int j = 0; j < N; j++)
                printf("%d ", a[i][j]);
        puts("");
    }
};

matrix operator *(matrix A, matrix B) {
    matrix C;
    vvll ar = A.rows(), bc = B.cols();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) 
            for (int k = 0; k < 3; k++) 
                if (ar[i][k] & bc[j][k]) 
                    C.a[i][j] = 1;
    return C;
}

matrix pow(matrix A, int k) {
    matrix R;
    R.identity();
    for (; k; k >>= 1) {
        if (k & 1) R = R * A;
        A = A * A;
    }
    return R;
}

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        x--; y--;
        V.push_back(edge(x, y, z));
    }
}

void bfs() {
    queue <int> Q;
    memset(dist, -1, sizeof dist);
    dist[N - 1] = 0;
    Q.push(N - 1);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (int i = 0; i < E[x].size(); i++) {
            int nxt = E[x][i];
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[x] + 1;
            Q.push(nxt);
        } 
    }
}   

void solve() {
    V.push_back(edge(-1, -1, 0));
    sort(V.begin(), V.end());
    matrix curr, trans;
    curr.identity();
    int sol = INF;
    for (int i = 1; i <= M; i++) {
        curr = curr * pow(trans, V[i].d - V[i - 1].d);
        trans.a[V[i].a][V[i].b] = 1;
        E[V[i].b].push_back(V[i].a);
        bfs();
        for (int j = 0; j < N; j++)
            if (dist[j] != -1 && curr.a[0][j])
                sol = min(sol, V[i].d + dist[j]);
    }
    if (sol == INF) puts("Impossible");
    else printf("%d\n", sol);
}

int main() {
    load();
    solve();
    return 0;
}