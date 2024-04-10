#include <bits/stdc++.h>

using namespace std;

int n, p[200500];

int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }

int main() {
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= 2 * n; ++i)
        p[i] = i;
    for (; m --> 0; ) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        for (int k = 0; k < 2; ++k)
            p[f(x + k * n)] = f(y + (k ^ z ^ 1) * n);
    }
    int res = 500000004;
    for (int i = 1; i <= n; ++i) {
        if (f(i) == f(i + n))
            res = 0;
        if (f(i) == i)
            res = (res + res) % 1000000007;
    }
    cout << res << endl;
    return 0;
}