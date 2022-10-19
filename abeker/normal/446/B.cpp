#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const int MAXK = 1000005;

int N, M, K, P;
int a[MAXN][MAXN];
int row[MAXN], col[MAXN];
ll best[MAXK];
priority_queue <ll> Q;

void load() {
    scanf("%d%d%d%d", &N, &M, &K, &P);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            scanf("%d", a[i] + j);
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
}

ll solve() {
    for (int i = 0; i < N; i++)
        Q.push((ll)row[i]);
    
    for (int i = 1; i <= K; i++) {
        ll tmp = Q.top();
        Q.pop();
        Q.push(tmp - (ll)M * P);
        best[i] = best[i - 1] + tmp;
    }
    
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < M; i++)
        Q.push((ll)col[i]);
        
    ll sol = (ll)-1e18, sum = 0;
    for (int i = 0; i <= K; i++) {
        ll tmp = Q.top();
        Q.pop();
        Q.push(tmp - (ll)N * P);
        sol = max(sol, sum + best[K - i] - (ll)i * (K - i) * P);
        sum += tmp;
    }
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}