#include <cstdio>
using namespace std;

const int MAXN = 500005;
const int MAXM = 10000005;
const int MOD = 1000000007;

int N;
int a[MAXN];
int p[MAXM];
int cnt[MAXM];
int pot[MAXN];

inline void add(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int f(int x) {
    int res = 0;
    for (; x > 1; res ^= 1) {
        int t = p[x];
        x /= t;
        if (!(x % t)) return -1;
    }
    return res;
}

int solve() {
    pot[0] = 1;
    for (int i = 1; i <= N; i++)
        pot[i] = mul(pot[i - 1], 2);
        
    for (int i = 2; i < MAXM; i++) {
        if (p[i]) continue;
        for (int j = i; j < MAXM; j += i)
            if (!p[j]) p[j] = i;
    }
    
    for (int i = 0; i < N; i++)
        cnt[a[i]]++;
    
    int num = 0, sum = 0;
    for (int i = 2; i < MAXM; i++) {
        int tmp = f(i);
        if (tmp == -1) continue;
        for (int j = 2 * i; j < MAXM; j += i)    
            cnt[i] += cnt[j];
        if (!cnt[i]) continue;
        if (tmp) {
            add(num, pot[cnt[i]] - 1);
            add(sum, mul(pot[cnt[i] - 1], cnt[i]));
        }
        else {
            add(num, -pot[cnt[i]] + 1);
            add(sum, -mul(pot[cnt[i] - 1], cnt[i]));
        }
    }
    
    int sol = mul(N, num);
    add(sol, -mul(2, sum));
    add(sol, N - cnt[1]);
    return sol;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}