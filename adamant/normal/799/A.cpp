#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int a = (n / k + bool(n % k)) * t;
    int b = 0;
    int cur_cakes = 0;
    int T;
    for(T = 0; cur_cakes < n; )
    {
        T++;
        if(T > 0 && T % t == 0)
            cur_cakes += k;
        if(T > d && (T - d) % t == 0)
            cur_cakes += k;
    }
    if(T < a)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}