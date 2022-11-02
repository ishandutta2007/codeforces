#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int maxn = 1e5 + 9;
int x[maxn];
int n;

bool check()
{
    for (int i = 1; i < n; i++)
    {
        if (abs(x[i] - x[i - 1]) != 1)
            return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    n = a + b + c + d;
    int A = a, B = b, C = c, D = d;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (a)
            {
                x[i] = 0;
                a--;
            }
            else
            {
                x[i] = 2;
                c--;
            }
        }
        else
        {
            if (b)
            {
                x[i] = 1;
                b--;
            }
            else
            {
                x[i] = 3;
                d--;
            }
        }
    }
    if (a == 0 && b == 0 && c == 0 && d == 0 && check())
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        return 0;
    }
    a = A;
    b = B;
    c = C;
    d = D;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
        {
            if (a)
            {
                x[i] = 0;
                a--;
            }
            else
            {
                x[i] = 2;
                c--;
            }
        }
        else
        {
            if (b)
            {
                x[i] = 1;
                b--;
            }
            else
            {
                x[i] = 3;
                d--;
            }
        }
    }
    if (a == 0 && b == 0 && c == 0 && d == 0 && check())
    {
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << x[i] << " ";
        return 0;
    }
    cout << "NO";
}