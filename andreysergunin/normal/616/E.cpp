#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int P = 1e9 + 7;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    if (n < m) {
        ans = (n % P) * ((m - n) % P) % P;
        m = n;
    }
    long long i = 1;
    for ( ; i * i <= n && i <= m; i++)
        ans = (ans + n % i) % P;
    for (long long j = n / i; j >= n / m; j--) {
        long long l = n / (j + 1) + 1;
        long long r = n / j;
        l = max(l, i);
        r = min(r, m);
        long long x = ((r - l + 1) % P) * (n % P) % P;
        long long y = (((r - l + 1) * (r + l) / 2) % P) * j % P;
        y = ((((r - l + 1) % P) * ((r + l) % P)) % P * (P + 1) / 2) % P * j % P;
        ans = (ans + x - y + P) % P;
    }
    cout << ans << endl;
    return 0;
}