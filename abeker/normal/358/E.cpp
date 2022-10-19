#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1005;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int N, M;
int a[MAXN][MAXN];
bool bio[MAXN][MAXN];
vector < pii > V;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", a[i] + j);
}

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M && a[x][y];
}

void dfs(int x, int y) {
    bio[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny) && !bio[nx][ny]) 
            dfs(nx, ny);
    }
}

int get(int x, int y, int dir, int k) {
    for (int i = 0; i < k; i++) {
        x += dx[dir];
        y += dy[dir];
        if (!ok(x, y)) return i;
    }
    return k;
}

void solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (a[i][j]) V.push_back(pii(i, j));        
    pii mini = *min_element(V.begin(), V.end());
    pii maks = *max_element(V.begin(), V.end());
    int g = __gcd(abs(maks.first - mini.first), abs(maks.second - mini.second));
    
    dfs(mini.first, mini.second);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (a[i][j] && !bio[i][j]) {
                puts("-1");
                return;
            }
                
    bool ex = false;
    for (int k = 2; k <= g; k++) {
        if (g % k) continue;
        bool ok = true;
        for (int i = 0; i < V.size(); i++)
            if ((V[i].first - mini.first) % k && (V[i].second - mini.second) % k) {
                ok = false;
                break;
            }
        if (!ok) continue;
        
        int cnt = 0;
        for (int i = 0; i < V.size(); i++) {
            if ((V[i].first - mini.first) % k || (V[i].second - mini.second) % k) continue;
            int deg = 0;
            for (int j = 0; j < 4; j++) {
                int tmp = get(V[i].first, V[i].second, j, k);
                if (tmp % k) ok = false;
                if (tmp == k) deg++;         
            }
            if (deg & 1) cnt++;
        }
        if (ok && cnt < 3) {
            printf("%d ", k);
            ex = true;
        }
    }
    
    if (!ex) printf("-1");
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}