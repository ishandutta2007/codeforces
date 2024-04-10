#include <cstdio>
using namespace std;

const int MAXN = 200005;
const int MOD = 1000000007;

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int pow(int x, int y) {
    int res = 1;
    for (; y; y >>= 1) {
        if (y & 1) res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

int cnt[MAXN];

int main() {
    int M;
    scanf("%d", &M);
    while (M--) {
        int prime;
        scanf("%d", &prime);
        cnt[prime]++;
    }
    
    bool square = true;
    for (int i = 0; i < MAXN; i++) 
        if (cnt[i] % 2) square = false;
    
    int N = 1;    
    for (int i = 0; i < MAXN; i++)
        N = mul(N, pow(i, square ? cnt[i] / 2 : cnt[i]));
    
    for (int i = 0; i < MAXN; i++) 
        if (!square && cnt[i] % 2) {
            N = pow(N, (cnt[i] + 1) / 2);
            square = true;
        }
        else N = pow(N, cnt[i] + 1);

    printf("%d\n", N);
    return 0;
}