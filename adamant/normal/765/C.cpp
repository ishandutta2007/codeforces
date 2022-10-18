#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, a, b;
    cin >> k >> a >> b;
    int ta = a / k, tb = b / k;
    if(ta > tb)
        swap(ta, tb), swap(a, b);
    if(ta > 0 && tb > 0 || tb != 0 && b % k == 0)
    {
        cout << ta + tb << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}