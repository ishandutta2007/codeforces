#include <bits/stdc++.h>

using namespace std;

const int mod = 1e4+7;

long long a[100000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans += a[i] * a[(n - 1 - i)];
        ans %= mod;
    }

    cout << ans;
    return 0;
}