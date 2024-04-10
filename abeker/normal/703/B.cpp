#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

int N, K;
int cost[MAXN], idx[MAXN];
bool cap[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", cost + i);
    for (int i = 0; i < K; i++) {
        scanf("%d", idx + i);
        cap[--idx[i]] = true;
    }
}

ll solve() {
    ll sol = 0;
    for (int i = 0; i < N; i++)
        if (!cap[i] && !cap[(i + 1) % N])
            sol += (ll)cost[i] * cost[(i + 1) % N];
    
    ll sum = 0;
    for (int i = 0; i < N; i++)
        sum += cost[i];
    
    ll t = 0, q = 0;
    for (int i = 0; i < K; i++) {
        t += cost[idx[i]];
        q += (ll)cost[idx[i]] * cost[idx[i]];
    }
    
    sol += t * sum;
    sol -= (t * t + q) / 2;
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}