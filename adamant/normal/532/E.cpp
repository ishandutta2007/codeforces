#include <bits/stdc++.h>

using namespace std;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int mp = 0, ms = 0;
    while(a[mp] == b[mp])
        mp++;
    while(a[n - ms - 1] == b[n - ms - 1])
        ms++;
    int ans = 0;
    string A, B;
    A = b[mp] + a.substr(mp, n - ms - mp);
    B = b.substr(mp, n - ms - mp) + a[n - ms - 1];
    ans += A == B;
    A = a[mp] + b.substr(mp, n - ms - mp);
    B = a.substr(mp, n - ms - mp) + b[n - ms - 1];
    ans += A == B;
    cout << ans << "\n";
}