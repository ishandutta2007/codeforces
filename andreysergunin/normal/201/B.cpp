#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>

using namespace std;

long long sqr(long long x) {
    return x * x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);
    vector< vector<int> > c;
    c.resize(n);
    long long sxc = 0, syc = 0, sc = 0;
    for (int i = 0; i < n; i++) {
        c[i].resize(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &c[i][j]);
            sxc += (long long)c[i][j] * (4 * i + 2);
            syc += (long long)c[i][j] * (4 * j + 2);
            sc += (long long)c[i][j];
        }
    }
    if (sc == 0) {
        cout << 0 << endl;
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    long long xm = sxc / sc;
    if (sxc % sc == 0 && xm % 4 == 2) {
        xm -= 2;
    }
    else {
        xm = xm - xm % 2;
        if (xm % 4 == 2)
            xm += 2;
    }
    long long ym = syc / sc;
    if (syc % sc == 0 && ym % 4 == 2) {
        ym -= 2;
    }
    else {
        ym = ym - ym % 2;
        if (ym % 4 == 2)
            ym += 2;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += (long long)c[i][j] * (sqr(xm - 4 * i - 2) + sqr(ym - 4 * j - 2));
    cout << ans << endl;
    cout << xm / 4 << " " << ym / 4 << endl;
}