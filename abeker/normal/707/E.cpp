#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 2005;
const int MAXQ = 1000005;

int N, M, K, Q;
int len[MAXN];
int x[MAXN][MAXN], y[MAXN][MAXN];
int w[MAXN][MAXN];
bool on[MAXN];
int x1[MAXQ], y1[MAXQ];
int x2[MAXQ], y2[MAXQ];
vector <int> queries[MAXN];
ll f[MAXN][MAXN];
ll ans[MAXQ];
bool out[MAXQ];

void update(int x, int y, int val) {
    for (int i = x; i < MAXN; i += i & -i)
        for (int j = y; j < MAXN; j += j & -j)
            f[i][j] += val;  
}

ll get(int x, int y) {
    ll res = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            res += f[i][j];
    return res;
}

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", len + i);
        for (int j = 0; j < len[i]; j++) 
            scanf("%d%d%d", x[i] + j, y[i] + j, w[i] + j);                
    }
}

void solve() {
    memset(on, true, sizeof on);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        char buff[10];
        scanf("%s", buff);
        if (buff[0] == 'S') {
            int x;
            scanf("%d", &x);
            on[--x] ^= 1;
        }
        else {
            scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
            for (int j = 0; j < K; j++)
                if (on[j]) queries[j].push_back(i);
            out[i] = true;
        }
    }
    
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < len[i]; j++)
            update(x[i][j], y[i][j], w[i][j]);
        for (int j = 0; j < queries[i].size(); j++) {
            int q = queries[i][j];
            ans[q] += get(x2[q], y2[q]) + get(x1[q] - 1, y1[q] - 1) - get(x2[q], y1[q] - 1) - get(x1[q] - 1, y2[q]);
        }
        for (int j = 0; j < len[i]; j++)
            update(x[i][j], y[i][j], -w[i][j]);
    }
    
    for (int i = 0; i < Q; i++)
        if (out[i]) printf("%I64d\n", ans[i]);
}

int main() {
    load();
    solve();
    return 0;
}