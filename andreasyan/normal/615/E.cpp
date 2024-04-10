#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1000000009;
const long long xx[6] = {1, -1, -2, -1, 1, 2};
const long long yy[6] = {2, 2, 0, -2, -2, 0};

long long n;

long long x, y;

int solv()
{
    cin >> n;
    long long l = 0, r = N;
    long long q;
    while (l <= r)
    {
        long long m = (l + r) / 2;
        long long s = (m * (m + 1) / 2) * 6;
        if (n <= s)
        {
            q = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }
    if (q == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    for (int i = 0; i < 6; ++i)
    {
        x += xx[i] * ((q - 1) * q / 2);
        y += yy[i] * ((q - 1) * q / 2);
        if (i == 0)
        {
            x += xx[i] * (q - 1);
            y += yy[i] * (q - 1);
        }
        if (i == 1)
        {
            x -= xx[i] * (q - 1);
            y -= yy[i] * (q - 1);
        }
    }
    long long qq = n - (((q - 1) * q) / 2) * 6;
    if (qq)
    {
        --qq;
        x += xx[0];
        y += yy[0];
    }
    if (qq <= q - 1)
    {
        x += xx[1] * qq;
        y += yy[1] * qq;
        qq = 0;
    }
    else
    {
        x += xx[1] * (q - 1);
        y += yy[1] * (q - 1);
        qq -= (q - 1);
    }
    for (int i = 2; i < 6; ++i)
    {
        if (qq <= q)
        {
            x += xx[i] * qq;
            y += yy[i] * qq;
            qq = 0;
        }
        else
        {
            x += xx[i] * q;
            y += yy[i] * q;
            qq -= q;
        }
    }
    x += qq * xx[0];
    y += qq * yy[0];
    cout << x << ' ' << y << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}