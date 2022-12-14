#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n < m)
        swap (n, m);
    int k = n - m, ans = 0;
    ans += min(m, k);
    n -= 2 * k;
    m -= k;
    if (m > 0){
        bool mod = 0;
        if (m % 3 == 2)
            mod = 1;
        ans += (2 * (m / 3)) + mod;
    }
    cout << ans << endl;
}