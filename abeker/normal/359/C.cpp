#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llint;

const int MAXN = 100010;
const llint MOD = 1000000007, INF = 1ll << 60;

int n, x;
llint a[MAXN], sum, sol, tmp;

inline llint reduce(int m) {
    if (!m) return INF;
    llint ret = 0;
    for (; m % x == 0; m /= x)
        ret++;
    return ret;
}

inline llint pow(llint base, llint exp) {
    llint ret = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) ret = ret * base % MOD;
        base = base * base % MOD;
    }
    return ret;
}
 
int main() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) 
        a[i] = sum - a[i];
    sort(a, a + n);
    int num = 0;
    for (int i = 0; i < n;) {
        a[i] -= sol;
        tmp = reduce(num);
        if (tmp < a[i]) break;
        else {
            sol += a[i];
            if (num) 
                for (int j = 0; j < a[i]; j++)  
                    num /= x;
            for (llint curr = a[i]; i < n && a[i] == curr; i++) 
                num++;
        }
    }
    sol += reduce(num);
    printf("%I64d\n", pow((llint)x, min(sol, sum)));
    return 0;
}