#include <bits/stdc++.h>

using namespace std;
const int MAXN = 60000;



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, p, x, y;
    int a[MAXN];
    cin >> n >> k >> p >> x >> y;
    int s = 0;
    int l = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        s += a[i];
        if (a[i] < y)
            l++;
    }
    if (l > n / 2)
    {
        cout << -1;
        return 0;
    }

    if (k - l > n / 2)
    {
        s += n - k;
        if (s > x)
        {
            cout << -1;
            return 0;
        }
        for (int i = 0; i < n - k; i++)
            cout << "1 ";
        return 0;
    }
    s += ((n / 2 + 1) - (k - l)) * y + (n / 2 - l);
    if (s > x)
    {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n / 2 - l; i++)
        cout << "1 ";
    for (int i = 0; i < (n / 2 + 1) - (k - l); i++)
        cout << y << ' ';

    return 0;
}