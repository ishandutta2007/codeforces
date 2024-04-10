#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const ll BASE = 1000000007;
const ll MOD = 2147448012;

int N, W;
ll a[MAXN], b[MAXN];

inline ll mul(ll x, ll y) { return x * y % MOD; }

inline void add(ll &x, ll y) { x = (x + y % MOD + MOD) % MOD; }
 
inline ll sub(ll x, ll y) { return (x - y + MOD) % MOD; }

void load() {
    scanf("%d%d", &N, &W);
    for (int i = 1; i <= N; i++)
        scanf("%I64d", a + i);
    for (int i = 1; i <= W; i++) 
        scanf("%I64d", b + i);
}

int solve() {
    
    if (W == 1) return N;
    
    ll pow = 1;
    for (int i = 1; i < W; i++)
        pow = mul(pow, BASE);
         
    for (int i = 1; i < N; i++) 
        add(a[i], a[i - 1] * BASE - a[i + 1]);
        
    for (int i = 1; i < W; i++) 
        add(b[i], b[i - 1] * BASE - b[i + 1]);
        
    int sol = 0;
    for (int i = 1; i + W - 2 < N; i++)
        sol += sub(a[i + W - 2], mul(pow, a[i - 1])) == b[W - 1]; 
        
    return sol;
}
 
int main() {
    load();
    printf("%d\n", solve());
    return 0;
}