#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // your code here
    int n, m, a;
    cin >> n >> m >> a;
    cout << 1LL * ((n - 1) / a + 1) * ((m - 1) / a + 1);
    cout.flush();
    return 0;
}