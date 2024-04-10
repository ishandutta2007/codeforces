#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;

ll N, M;
char x[MAXN], y[MAXN];
int a[30][MAXN], b[30][MAXN];

void load() {
    scanf("%I64d%I64d%s%s", &N, &M, x, y);
}

ll solve() {
    int K = strlen(x);
    int L = strlen(y);
    int g = __gcd(K, L);
    for (int i = 0; i < K; i++)
        a[x[i] - 'a'][i % g]++;
    for (int i = 0; i < L; i++)
        b[y[i] - 'a'][i % g]++;
    
    ll sol = 0;
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < g; j++)
            sol += (ll)a[i][j] * b[i][j];
    ll len = N * K;
    ll lcm = (ll)K * L / g;
    sol *= len / lcm;
    
    return len - sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}