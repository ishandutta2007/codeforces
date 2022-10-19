#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int fact[MAXN], inv[MAXN];
vector <int> D[MAXN];
int dp[MAXN];

inline int sub(int &x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pow(int x, int y) {
    if (!y) return 1;
    if (y & 1) return mul(pow(x, y - 1), x);
    int res = pow(x, y >> 1);
    return mul(res, res);
}

int choose(int n, int k) {
    return n < k ? 0 : mul(fact[n], mul(inv[k], inv[n - k]));
}

void init() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = pow(fact[i], MOD - 2);
        vector <int> tmp;
        for (int j = 1; j * j <= i; j++)
            if (!(i % j)) {
                D[i].push_back(j);
                if (j * j < i) tmp.push_back(i / j);
            }
        for (; !tmp.empty(); tmp.pop_back())
            D[i].push_back(tmp.back());
    }
}

void solve() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int N, F;
        scanf("%d%d", &N, &F);
        for (int i = 0; i < D[N].size(); i++) {
            int curr = D[N][i];
            dp[curr] = choose(curr - 1, F - 1);
            for (int j = 0; j < (int)D[curr].size() - 1; j++)
                sub(dp[curr], dp[D[curr][j]]);
        }
        printf("%d\n", dp[N]);
    }
}

int main() {
    init();
    solve();
    return 0;
}