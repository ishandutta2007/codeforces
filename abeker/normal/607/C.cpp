#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

typedef pair <int, int> hash;

const int MAXN = 1000005;
const int BASE1 = 3137;
const int BASE2 = 10007;
const int MOD = 1000000007;

int N;
char a[MAXN], b[MAXN];
hash pref[MAXN];

void load() {
    scanf("%d%s%s", &N, a + 1, b + 1);
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

hash merge(hash h, char c) {
    return hash(add(mul(h.first, BASE1), c), h.second * BASE2 + c); 
}

char opp(char c) {
    if (c == 'N') return 'S';
    if (c == 'S') return 'N';
    if (c == 'W') return 'E';
    if (c == 'E') return 'W';
    assert(0);
}

bool solve() {
    N--;
    for (int i = 1; i <= N; i++) 
        pref[i] = merge(pref[i - 1], a[i]);
    
    int pot1 = 1, pot2 = 1;
    hash curr, suff(0, 0);
    for (int i = N; i; i--) { 
        pot1 = mul(pot1, BASE1);
        pot2 *= BASE2; 
        suff = merge(suff, opp(b[i]));
        curr.first = add(pref[N].first, -mul(pot1, pref[i - 1].first));
        curr.second = pref[N].second - pot2 * pref[i - 1].second;
        if (curr == suff) return false;
    }
    
    return true;
}

int main() {
    load();
    puts(solve() ? "YES" : "NO");
    return 0;
}