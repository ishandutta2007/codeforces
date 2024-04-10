#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int n;
    cin >> n;
    int ans = 0;
    while(n--)
    {
        int x;
        cin >> x;
        ans += x > b && x < c;
    }
    cout << ans << endl;
}