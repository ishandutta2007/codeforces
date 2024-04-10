#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long i, s, n, p[200000], t,q ;
    bool f, fl;
    cin >> n;
    if (n == 1)
        cout << "YES\n1";
    else
    {


    t = 0;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            t = 1;
    if (t == 0)
    {
        f = true;
        s = 2;
        while (f)
        {
            q = s;
            for (i = 0; i < n; i++)
                p[i] = 0;
            p[1] = 1;
            for (i = 0; i < n; i++)
            {
                p[q] = 1;
                q = (q * s) % n;
            }
            fl = true;
            for (i = 1; i < n; i ++)
                if (p[i] == 0)
                    fl = false;
            if (fl)
                f = false;
            s++;
        }
        s--;
        q = s;
        for (i = 1; i < n - 1; i++)
        {
            p[i] = q;
            q = (q * s) % n;
        }
        cout << "YES\n1\n";
        for (i = 1; i < n - 1; i++)
        {
            if (i % 2 == 0)
                cout << p[i] << '\n';
            else
                cout << p[n - 1 - i] << '\n';
        }
        cout << n << '\n';
    }
    else
        if (n == 4)
            cout << "YES\n1\n3\n2\n4\n";
        else
            cout << "NO\n";

    }
}