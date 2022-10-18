#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int inf = 5e18;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    int a[n];
    int mp = -inf, mpq = -inf, mpqr = -inf;
    for(int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        mp = max(mp, p * t);
        mpq = max(mpq, mp + q * t);
        mpqr = max(mpqr, mpq + r * t);
    }
    cout << mpqr << endl;
    return 0;
}