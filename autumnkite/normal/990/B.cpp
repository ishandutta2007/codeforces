#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, x, a[1000005], ans;
int main(){
    scanf("%d%d", &n, &k), ans = n;
    for (register int i = 1; i <= n; ++i) scanf("%d", &x), ++a[x];
    for (register int i = 1, j = 0; i <= 1000000; ++i)
        if (a[i]){
            if (j >= i - k && j) ans -= a[j];
            j = i;
        }
    return printf("%d", ans), 0;
}