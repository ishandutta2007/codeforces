#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;
#define gc getchar
inline void read(int &x){
    register bool f;
    register char ch;
    for (f = false, ch = gc(); !isdigit(ch); ch = gc()) if (ch == '-') f = true;
    for (x = 0; isdigit(ch); ch = gc()) x = ((x + (x << 2)) << 1) + (ch ^ '0');
    if (f) x = -x;
}
const int N = 100005;
int n, k, m, l, a[N];
long long sum = 0;
inline int abs(int x){
    return x > 0 ? x : -x;
}
int main(){
    read(n), read(k), read(l), m = n * k;
    for (register int i = 1; i <= m; ++i) read(a[i]);
    sort(a + 1, a + 1 + m);
    register int t = upper_bound(a + 1, a + 1 + m, a[1] + l) - a - 1, p = 0;
    if (t < n) return printf("0"), 0;
    for (register int i = 1; i <= n; ++i){
        sum += a[++p];
        for (register int j = 0; j < k - 1 && t - p > n - i; ++j) ++p;
    }
    return printf("%I64d", sum), 0;
}