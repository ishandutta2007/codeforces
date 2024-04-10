#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 200005;
const int MAXM = 1000005;
const int MOD = 1000000007;

int N, K, Q;
int a[MAXN];
int prime[MAXM];
int moebius[MAXM];
int fact[MAXN], inv[MAXN];
int cnt[MAXM];
vector <int> divs[MAXM];

void load() {
    scanf("%d%d%d", &N, &K, &Q);
    for (int i = 0; i < N + Q; i++)
        scanf("%d", a + i);
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

inline int pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

inline int choose(int n, int k) {
    if (n < k) return 0;
    return mul(fact[n], mul(inv[k], inv[n - k]));
}

void solve() {
    for (int i = 1; i < MAXM; i++) 
        for (int j = i; j < MAXM; j += i) {
            if (!prime[j] && i > 1) prime[j] = i;
            divs[j].push_back(i);
        }
    
    moebius[1] = 1;
    for (int i = 2; i < MAXM; i++) {
        vector <int> factors;
        int last = 1;
        for (int x = i; x > 1; x /= prime[x]) {
            if (prime[x] != last) factors.push_back(prime[x]);
            last = prime[x];
        }
        int sz = factors.size();
        for (int j = 0; j < 1 << sz; j++) {
            int x = i;
            for (int k = 0; k < sz; k++)
                if (j >> k & 1) x /= factors[k];
            moebius[i] += __builtin_popcount(j) & 1 ? -x : x;
        }
    }
    
    fact[0] = inv[0] = 1; 
    for (int i = 1; i <= N + Q; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = pow(fact[i], MOD - 2);
    }
    
    int sol = 0;
    for (int i = 0; i < N + Q; i++) {
        for (int j = 0; j < divs[a[i]].size(); j++) {
            int tmp = divs[a[i]][j];
            sol = add(sol, mul(choose(cnt[tmp], K - 1), add(moebius[tmp], 0)));   
            cnt[tmp]++;
        }
        if (i >= N) printf("%d\n", sol);
    }
}

int main() {
    load();
    solve();
    return 0;
}