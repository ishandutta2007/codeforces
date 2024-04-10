#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 5005;
const int BASE1 = 3137;
const int BASE2 = 10007;
const int MOD = 1000000007;

int N;
char s[MAXN];
int dp[MAXN][MAXN];
int suff[MAXN][MAXN];
pii hash[MAXN];
int pow1[MAXN], pow2[MAXN];

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    else if (x < 0) x += MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d%s", &N, s);
}

pii get(int x, int y) {
    pii res;
    res.first = hash[y].first - (x ? hash[x - 1].first * pow1[y - x + 1] : 0);
    res.second = add(hash[y].second, x ? -mul(hash[x - 1].second, pow2[y - x + 1]) : 0);
    return res;
}

bool cmp(int x, int y) {
    int lo = 0, hi = y - x;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (get(x, x + mid - 1) == get(y, y + mid - 1)) lo = mid;
        else hi = mid - 1;
    }
    if (lo == y - x) return 0;
    return s[x + lo] < s[y + lo];
}

int solve() {
    hash[0] = pii(s[0], s[0]);
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < N; i++) {
        pow1[i] = pow1[i - 1] * BASE1;
        pow2[i] = mul(pow2[i - 1], BASE2);
        hash[i].first = hash[i - 1].first * BASE1 + s[i];
        hash[i].second = add(mul(hash[i - 1].second, BASE2), s[i]);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j < N; j++) {
            if (s[i] == '0') continue;
            int len = j - i + 1;
            if (j == N - 1) {
                dp[i][j] = 1;
                continue;
            }
            if (j + len >= N) continue;
            dp[i][j] = suff[j + 1][j + len + 1];
            if (cmp(i, j + 1)) 
                dp[i][j] = add(dp[i][j], dp[j + 1][j + len]);  
        }
        for (int j = N - 1; j >= i; j--)
            suff[i][j] = add(suff[i][j + 1], dp[i][j]);
    }
    
    return suff[0][0];
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}