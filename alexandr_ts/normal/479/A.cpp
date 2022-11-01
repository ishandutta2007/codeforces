#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10];
    cin >> a[0] >> a[1] >> a[2];
    int ans = max(a[0] * a[1] * a[2], (a[0] + a[1]) * a[2]);
    ans = max(ans, a[0] + a[1] + a[2]);
    ans = max(ans, a[0] * (a[1] + a[2]));
    cout << ans;
    return 0;
}