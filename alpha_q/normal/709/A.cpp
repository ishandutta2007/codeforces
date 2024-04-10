#include <bits/stdc++.h>

using namespace std;

int n;
long long b, d, cur = 0;
int ans = 0;

int main (int argc, char const *argv[]) {
    scanf("%d %lld %lld", &n, &b, &d);
    for (int i = 1; i <= n; ++i) {
        long long x; 
        scanf("%lld", &x);
        if (x > b) continue;
        cur += x;
        if (cur > d) ++ans, cur = 0;
    }
    printf("%d\n", ans);
    return 0;
}