#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long b;
    cin >> b;
    long long i;
    long long ans = 0;
    for (i = 1; i * i < b; i++) {
        if (b % i == 0) ans += 2;
    }
    if (i * i == b) ans += 1;
    cout << ans;
    return 0;
}