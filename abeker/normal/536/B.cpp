#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1000005;
const int BASE1 = 10007;
const int BASE2 = 3137;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

int N, M;
char s[MAXN];
int pos[MAXN];
int cnt[MAXN];
pii hash[MAXN];
int pow1[MAXN];
int pow2[MAXN];

inline int mul(int x, int y, int mod) {
    return (ll)x * y % mod;
}

inline int add(int x, int y, int mod) {
    x += y;
    if (x < 0) x += mod;
    else if (x >= mod) x -= mod;
    return x;
}

void load() {
    scanf("%d%d%s", &N, &M, s + 1);
    for (int i = 0; i < M; i++) 
        scanf("%d", pos + i);    
}

pii get(int lo, int hi) {
    return pii(add(hash[hi].first, -mul(pow1[hi - lo + 1], hash[lo - 1].first, MOD1), MOD1),
               add(hash[hi].second, -mul(pow2[hi - lo + 1], hash[lo - 1].second, MOD2), MOD2));
}

int solve() {
    int len = strlen(s + 1);
    pow1[0] = pow2[0] = 1;
    hash[0] = pii(0, 0);
    for (int i = 1; i <= len; i++) {
        pow1[i] = mul(pow1[i - 1], BASE1, MOD1);
        pow2[i] = mul(pow2[i - 1], BASE2, MOD2);
        hash[i] = pii(add(mul(hash[i - 1].first, BASE1, MOD1), s[i], MOD1), 
                      add(mul(hash[i - 1].second, BASE2, MOD2), s[i], MOD2));
    }
    
    for (int i = 0; i < M; i++) {
        cnt[pos[i]]++;
        cnt[pos[i] + len]--;
        if (!i) continue;
        int com = pos[i - 1] - pos[i] + len;
        if (com > 0 && get(1, com) != get(len - com + 1, len)) return 0;
    }
    
    int sol = 1;
    for (int i = 1; i <= N; i++) {
        cnt[i] += cnt[i - 1];
        if (!cnt[i]) sol = (ll)sol * 26 % MOD1;
    }
    return sol;
}
  
int main() {    
    load();
    printf("%d\n", solve());
    return 0;
}