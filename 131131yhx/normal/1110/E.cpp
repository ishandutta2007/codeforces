#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define M 200010

using namespace std;

int n, c[M], t[M];

signed main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for(int i = 1; i <= n; i++) scanf("%lld", &t[i]);
    if(c[1] != t[1] || c[n] != t[n]) {
        puts("No");
        return 0;
    }
    for(int i = 1; i < n; i++) c[i] = c[i + 1] - c[i];
    for(int i = 1; i < n; i++) t[i] = t[i + 1] - t[i];
    sort(c + 1, c + n);
    sort(t + 1, t + n);
    for(int i = 1; i < n; i++) if(c[i] != t[i]) {
        puts("No");
        return 0;
    }
    puts("Yes");
    return 0;
}