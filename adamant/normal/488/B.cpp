#include <bits/stdc++.h>

using namespace std;
#define int int64_t

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 0)
    {
        cout << "YES" << '\n' << 1 << '\n' << 1 << '\n' << 3 << '\n' << 3;
    }
    if(n == 1)
    {
        int x;
        cin >> x;
        cout << "YES" << '\n' << x << '\n' << 3 * x << '\n' << 3 * x;
    }
    if(n == 2)
    {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        if(y > 3 * x) cout << "NO";
        else if(y == 3 * x) cout << "YES" << '\n' << x << '\n' << y;
        else cout << "YES" << '\n' << 4 * x - y << '\n' << 3 * x;
    }
    if(n == 3)
    {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if(a[2] > 3 * a[0]) cout << "NO";
        else if(a[2] == 3 * a[0]) cout << "YES" << '\n' << a[0] + a[2] - a[1];
        else if(!(a[2] % 3)) {if(a[0] - a[2] / 3 == a[2] - a[1]) cout << "YES" << '\n' << a[2] / 3;
        else if(a[1] - a[0] != 3 * a[0] - a[2]) cout << "NO";}
        else if(a[1] - a[0] != 3 * a[0] - a[2]) cout << "NO";
        else cout << "YES" << '\n' << 3 * a[0];
    }
    if(n == 4)
    {
        int a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);
        if(a[3] != 3 * a[0]) cout << "NO";
        else if(a[0] + a[3] != a[1] + a[2]) cout << "NO";
        else cout << "YES";
    }
    cout << '\n';
}