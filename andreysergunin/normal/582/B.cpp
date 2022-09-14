#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 1e5;
const int INF = 1e9;

int gcd (int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, t;
    int a[MAXN];
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int m = min(t, n) * n;
    int b[MAXN];
    for (int i = 0; i < m; i++)
        b[i] = a[i % n];
    
    int d[MAXN];
    d[0] = -INF;
    for (int i = 1; i <= m; ++i)
        d[i] = INF;
    
    for (int i = 0; i < m; i++) {
        int j = int ((upper_bound (d, d + m, b[i]) - d));
        if (d[j - 1] <= b[i] && b[i] <= d[j])
            d[j] = b[i];
    }
    
    int ans = 0;
    for (int i = 0; i <= m; ++i)
        if (d[i] != INF)
            ans = i;
    
    int k = 0;
    for (int q = 1; q <= 300; q++) {
        int u = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == q)
                u++;
        k = max(u, k);
    }
    cout << ans + (t - m / n) * k;
    
    return 0;
}