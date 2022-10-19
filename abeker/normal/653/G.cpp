#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 300005;
const int MOD = 1000000007;

int N;
int p[MAXN];
vector <int> exp[MAXN];
int fact[MAXN], inv[MAXN];
int val[MAXN], coef[MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pot(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

int choose(int n, int k) {
    return mul(fact[n], mul(inv[k], inv[n - k]));
}

void init() {
    for (int i = 2; i < MAXN; i++) {
        if (p[i]) continue;
        for (int j = i; j < MAXN; j += i)
            if (!p[j]) p[j] = i;
    }
}

void factor(int x) {
    while (x > 1) {
        int tmp = p[x], curr = 0;
        for (; !(x % tmp); x /= tmp)
            curr++;
        exp[tmp].push_back(curr);
    }
}

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        factor(x);
    }
}

int solve() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = pot(fact[i], MOD - 2);
    }
     
    for (int i = 0; i < N; i++)
        val[i] = add(i ? val[i - 1] : pot(2, N - 1), -choose(N - 1, i));
    
    for (int i = 0; i < N; i++) 
        coef[i] = add(val[N - i - 1], -val[i]);
    
    int sol = 0;
    for (int i = 0; i < MAXN; i++) {
        sort(exp[i].begin(), exp[i].end());
        for (int j = 0; j < exp[i].size(); j++) 
            sol = add(sol, mul(exp[i][j], coef[j + N - (int)exp[i].size()]));
    }
    
    return sol;           
}

int main() {
    init();
    load();
    printf("%d\n", solve());
    return 0;
}