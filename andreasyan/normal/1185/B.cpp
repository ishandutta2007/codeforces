#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];
int m;
char b[N];

bool solv()
{
    cin >> a;
    n = strlen(a);
    cin >> b;
    m = strlen(b);
    while (1)
    {
        if (n == 0 && m == 0)
            break;
        if (n == 0)
            return false;
        if (m == 0)
            return false;
        char aa = a[n - 1];
        char bb = b[m - 1];
        int qa = 0;
        while (n && a[n - 1] == aa)
        {
            ++qa;
            --n;
        }
        int qb = 0;
        while (m && b[m - 1] == bb)
        {
            ++qb;
            --m;
        }
        if (aa != bb)
            return false;
        if (qa > qb)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
    {
        if (solv())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}