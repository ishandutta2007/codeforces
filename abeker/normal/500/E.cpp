#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 200005;
const int INF = 2000000005;
const int LOG = 20;

int N, Q;
int p[MAXN], l[MAXN];
int next[LOG][MAXN];
int sum[LOG][MAXN];
stack <int> S;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", p + i, l + i);
        l[i] += p[i];
    }
}

int extend(int x, int y) {
    return max(p[y] - l[x], 0);
}

void add(int x) {
    while (!S.empty() && l[x] > l[S.top()])
        S.pop();
    next[0][x] = S.top();
    sum[0][x] = extend(x, S.top());
    S.push(x);
}

void init() {
    l[N] = INF;
    S.push(N);
    for (int i = N - 1; i >= 0; i--) add(i);
    
    for (int i = 0; i < LOG; i++) 
        next[i][N] = N;
        
    for (int i = 1; i < LOG; i++) 
        for (int j = 0; j < N; j++) { 
            next[i][j] = next[i - 1][next[i - 1][j]];
            sum[i][j] = sum[i - 1][j] + sum[i - 1][next[i - 1][j]];
        }
}

int query(int x, int y) {
    int cost = 0;
    for (int i = LOG - 1; i >= 0; i--) 
        if (next[i][x] <= y) {
            cost += sum[i][x];
            x = next[i][x];
        }
    return cost + extend(x, y);
}

void solve() {
    scanf("%d", &Q);
    while (Q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", query(--x, --y));
    }
}

int main() {
    load();
    init();
    solve();
    return 0;
}