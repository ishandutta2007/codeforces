#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1000005;
const int BASE1 = 10007;
const int BASE2 = 3137;
const int MOD = 1000000007;

int N, K;
char s[MAXN];
int lcp[MAXN];
pii hash[MAXN];
int pow1[MAXN], pow2[MAXN];
int sum[MAXN];

void load() {
    scanf("%d%d%s", &N, &K, s + 1);
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

pii get(int lo, int hi) {
    int h1 = hash[hi].first - pow1[hi - lo + 1] * hash[lo - 1].first;
    int h2 = add(hash[hi].second, -mul(pow2[hi - lo + 1], hash[lo - 1].second));
    return pii(h1, h2);
}

bool check(int x) {
    pii pref = get(1, x);
    for (int i = 0; i < K; i++) 
        if (get(i * x + 1, (i + 1) * x) != pref) return 0;
    return 1;
}

void solve() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= N; i++) {
        hash[i] = pii(hash[i - 1].first * BASE1 + s[i], add(mul(hash[i - 1].second, BASE2), s[i])); 
        pow1[i] = pow1[i - 1] * BASE1;
        pow2[i] = mul(pow2[i - 1], BASE2);
    }
    
    for (int i = 1; i <= N; i++) {
        int lo = 0, hi = N - i + 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (get(1, mid) == get(i, i + mid - 1)) lo = mid;
            else hi = mid - 1;
        }
        lcp[i] = lo;
    }
    
    for (int i = 1; K * i <= N; i++) {
        if (!check(i)) continue;
        int pos = K * i;
        int len = min(lcp[pos + 1], i);
        sum[pos]++;
        sum[pos + len + 1]--; 
    }
    
    for (int i = 1; i <= N; i++) {
        sum[i] += sum[i - 1];
        printf("%d", !!sum[i]);
    }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}