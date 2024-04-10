#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 800;

int gcd (int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    int a[MAXN * MAXN];
    cin >> n;
    for (int i = 0; i < n * n; i++)
        cin >> a[i];
    sort(a, a + n * n);
    int v[MAXN * MAXN];
    memset(v, 0, n * n * sizeof(int));
    int ans [MAXN];
    int k = n * n - 1;
    for (int i = 0; i < n; i++) {
        while (v[k] == 1)
            k--;
        ans[i] = a[k];
        int b[MAXN];
        for (int j = 0; j <= i; j++) {
            b[j] = gcd(ans[i], ans[j]);
        }
        for (int j = 0; j < i; j++) {
            b[i + j + 1] = gcd(ans[i], ans[j]);
        }
        sort(b, b + 2 * i + 1);
        int t = 0;
        for (int j = 0; j < n * n && t < 2 * i + 1; j++)
            if (b[t] == a[j] && v[j] == 0) {
                v[j] = 1;
                t++;
            }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    
    return 0;
}