#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

ll N, K;
int L, M;
map <ll, bool> bio;
map <ll, int> memo;

inline int add(int x, int y) {
    x += y;
    if (x >= M) x -= M;
    else if (x < 0) x += M;
    return x;
}

inline int mul(int x, int y) {
    return (ll)x * y % M;
}

void load() {
    scanf("%I64d%I64d%d%d", &N, &K, &L, &M);
}

int pow(int x, ll y) {
    if (!y) return 1;
    if (y % 2) return mul(x, pow(x, y - 1));
    int res = pow(x, y / 2);
    return mul(res, res);
}

int fib(ll x) {
    int &ref = memo[x];
    if (bio[x]) return ref;
    bio[x] = true;
    if (x < 2) ref = (int)x;
    else if (x % 2) ref = add(pow(fib(x / 2), 2), pow(fib(x / 2 + 1), 2));
    else ref = mul(fib(x / 2), add(fib(x / 2), mul(2, fib(x / 2 - 1))));
    return ref;
}

int solve() {
    if (L <= 60 && K >= 1ll << L) return 0;
    int cnt = __builtin_popcountll(K);        
    int ways = fib(N + 2);
    return mul(pow(add(pow(2, N), -ways), (ll)cnt), pow(ways, (ll)(L - cnt)));
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}