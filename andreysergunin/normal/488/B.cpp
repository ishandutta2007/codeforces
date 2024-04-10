#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a[5], i, c;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 0)
        cout << "YES\n1\n2\n2\n3";
    if (n == 1)
        cout << "YES\n" << 2 * a[1] << '\n' << 2 * a[1] << '\n' << 3 * a[1];

    if (n == 2)
    {
        if (a[1] > a[2])
        {
            c = a[1];
            a[1] = a[2];
            a[2] = c;
        }
        if (3 * a[1] >= a[2])
            cout << "YES\n" << 4 * a[1] - a[2] << '\n' << 3 * a[1];
        else
            if ((a[2] + a[1]) % 4 == 0 && (a[2] + a[1]) % 4 >= a[1])
                cout << "YES\n" << (a[2] + a[1]) / 4 << '\n' << (a[2] + a[1]) / 4 * 3;
            else
                cout << "NO\n";
    }

    if (n == 3)
    {
        int p, q, r;
        p = min (a[1], min (a[2], a[3]));
        r = max (a[1], max (a[2], a[3]));
        q = a[1] + a[2] + a[3] - p - r;
        if (4 * p == q + r)
            cout << "YES\n" << 3 * p;
        else
            if (r % 3 == 0 && r * 4 / 3 == p + q)
                cout << "YES\n" << r / 3;
            else
                if (3 * p == r)
                    cout << "YES\n" << 4 * p - q;
                else
                    cout << "NO\n";
    }
    if (n == 4)
    {
        int p, q, s;
        p = min(min(a[1], a[2]),min(a[3], a[4]));
        q = max(max(a[1], a[2]),max(a[3], a[4]));
        s = a[1] + a[2] + a[3] + a[4];
        if (s == 4 *(q - p) && s == 2 * (s - p - q))
            cout << "YES\n";
        else
            cout <<"NO\n";
    }
    return 0;
}