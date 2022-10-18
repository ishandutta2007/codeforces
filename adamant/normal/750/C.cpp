#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int inf = 1e9;
    int mn = -inf;
    int mx = +inf;
    int n;
    cin >> n;
    int thr = 1900;
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        int k, d;
        cin >> k >> d;
        if(d == 1)
            mn = max(mn, thr - total);
        else
            mx = min(mx, thr - total - 1);
        total += k;
        //cout << mn << ' ' << mx << endl;
    }
    if(mn > mx)
        cout << "Impossible\n";
    else if(mx == inf)
        cout << "Infinity\n";
    else
        cout << mx + total << endl;
    return 0;
}