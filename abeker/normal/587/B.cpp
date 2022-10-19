#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1000005;
const int MOD = 1000000007;

int N, K;
pii p[MAXN];
int dp[MAXN];
int pref[MAXN];
int last[MAXN];
ll L;

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (ll)x * y % MOD;
}

void load() {
    scanf("%d%I64d%d", &N, &L, &K);
    for (int i = 1; i <= N; i++) { 
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
}

int solve() {
    sort(p + 1, p + N + 1);
    int pos = N;
    for (int i = N; i; i--) {
        if (p[i].first != p[i + 1].first) pos = i;
        last[i] = pos;
    }
    
    int sol = 0;
    ll cnt = L / (ll)N;
    ll tot = (L + (ll)N - 1) / (ll)N;
    for (int i = 1; i <= N; i++)
        pref[i] = 1;
    
    for (int j = 1; j <= K; j++) {
        for (int i = 1; i <= N; i++)
            dp[i] = pref[last[i]];
        
        for (int i = 1; i <= N; i++)
            pref[i] = add(pref[i - 1], dp[i]);
            
        if (j <= cnt) 
            sol = add(sol, mul(pref[N], add((int)(cnt % (ll)MOD), -j + 1)));
            
        for (int i = 1; i <= N; i++)
            if (p[i].second - 1 < L % (ll)N && j <= tot) 
                sol = add(sol, dp[i]);
    }
    
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}