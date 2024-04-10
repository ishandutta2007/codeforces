#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int BASE = 3137;
const int MOD = 1000000007;

int N, M;
char s[MAXN], t[MAXN];
int hash[MAXN], pattern;
int dp[MAXN], pref[MAXN];
int pow;

inline int mul(int x, int y) { return (ll)x * y % MOD; }

inline int add(int x, int y) { 
    x += y;
    if (x < 0) x += MOD;
    else if (x >= MOD) x -= MOD;
    return x;
}

void load() {
    scanf("%s%s", s + 1, t + 1);
}

inline int get(int x) {
    return add(hash[x + M - 1], -mul(hash[x - 1], pow));
}

int solve() {
    N = strlen(s + 1);
    M = strlen(t + 1);
    
    if (N < M) return 0;
    
    pow = 1;
    for (int i = 1; i <= M; i++) { 
        pow = mul(pow, BASE);
        pattern = add(mul(pattern, BASE), t[i]);
    }
    
    for (int i = 1; i <= N; i++) 
        hash[i] = add(mul(hash[i - 1], BASE), s[i]);
        
    dp[0] = 1;
    pref[0] = 1;
    int last = -1;
    
    for (int i = 1; i <= N; i++) {
        if (i >= M && get(i - M + 1) == pattern) 
            last = i - M;
        if (last != -1) dp[i] = pref[last];
        dp[i] = add(dp[i - 1], dp[i]);
        pref[i] = add(pref[i - 1], dp[i]);
    }
    
    return add(dp[N], -1);
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}