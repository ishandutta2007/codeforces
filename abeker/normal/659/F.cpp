#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1005;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, M;
ll K;
int a[MAXN][MAXN];
vector <pii> V;
int dad[MAXN * MAXN];
int sz[MAXN * MAXN];
bool bio[MAXN][MAXN];
bool vis[MAXN][MAXN];
int cnt;
ll num;

void load() {
    scanf("%d%d%I64d", &N, &M, &K);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", a[i] + j);
}

int f(int x, int y) {
    return x * M + y;
}

bool cmp(const pii &lhs, const pii &rhs) {
    return a[lhs.first][lhs.second] > a[rhs.first][rhs.second];
}

int find(int x) {
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
    if (rand() % 2) swap(x, y);
    x = find(x);
    y = find(y);
    if (x == y) return;
    dad[x] = y;
    sz[y] += sz[x];
}

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}

void dfs(int x, int y) {
    if (!ok(x, y)) return;
    if (!bio[x][y]) return;
    if (vis[x][y]) return;
    vis[x][y] = true;
    if (++cnt == num) {
        puts("YES");
        for (int i = 0; i < N; i++, puts(""))
            for (int j = 0; j < M; j++)
                printf("%I64d ", vis[i][j] ? K / num : 0);
        exit(0);
    }
    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            V.push_back(pii(i, j));
            int curr = f(i, j);
            dad[curr] = curr;
            sz[curr] = 1;
        }
    
    sort(V.begin(), V.end(), cmp);
    
    for (int i = 0; i < V.size(); i++) {
        int cx = V[i].first;
        int cy = V[i].second;
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (ok(nx, ny) && bio[nx][ny])
                join(f(cx, cy), f(nx, ny));
        }
        bio[cx][cy] = true;
        if (K % a[cx][cy]) continue;
        num = K / a[cx][cy];
        if (num > sz[find(f(cx, cy))]) continue;
        dfs(cx, cy);
    }    
    
    puts("NO");
}

int main() {
    load();
    solve();
    return 0;
}