#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    bitset<1000> f;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        x %= m;
        f |= (f << x) | (f >> (m - x));
        f.set(x);
        if (f[0]) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}