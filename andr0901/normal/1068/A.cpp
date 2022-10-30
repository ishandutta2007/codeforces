#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long n, m, k, l;
    cin >> n >> m >> k >> l;
    if (k + l > n) {
        cout << -1;
        return 0;
    }
    if (m > n) {
        cout << -1;
        return 0;
    }
    if (l == 0) {
        cout << 0;
        return 0;
    }
    if ((k + l) % m == 0) {
        if ((k + l) > n) cout << -1;
        else cout << (k + l) / m;
    } else {
        if ((((k + l) + m - (k + l) % m)) > n) cout << -1;
        else cout << ((k + l) + m - (k + l) % m) / m;
    }
    return 0;
}