#include <cstdio>
using namespace std;

const int MAXN = 1000005;
const int MOD = 1000000007;

int P, K;

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void load() {
    scanf("%d%d", &P, &K);
}

int pow(int x, int y) {
    int res = 1;
    while (y--)
        res = mul(res, x);
    return res;
}

int solve() {
    if (K == 0)     
        return pow(P, P - 1);
    if (K == 1)
        return pow(P, P);
    
    int ord = 1;
    for (int pot = K; pot != 1; pot = (long long)pot * K % P)
        ord++;
        
    return pow(P, (P - 1) / ord); 
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}