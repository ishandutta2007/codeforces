#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, t;
    cin >> n >> t;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    int k = 1;
    while (k != 0) {
        k = 0;
        long long c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= t - c) {
                c += a[i];
                k++;
            }
        }
        if (c == 0) {
            break;
        }
        ans += (t / c) * k;
        t %= c;
    }
    cout << ans;
    return 0;
}