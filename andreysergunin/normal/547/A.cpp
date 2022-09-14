#include <bits/stdc++.h>
#define fs first
#define sc second

using namespace std;

const int MAXN = 2000000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long m;
    long long h1, a1, x1, y1;
    long long h2, a2, x2, y2;
    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;
    long long a[MAXN], b[MAXN];
    for (long long i = 0; i < m; i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    long long p1 = -1;
    long long p2 = -1;
    long long ans = 0;
    a[h1] = 1;
    b[h2] = 1;
    for (long long i = 0; i < m; i++)
    {
        ans++;
        h1 = (h1 * x1 + y1) % m;
        h2 = (h2 * x2 + y2) % m;
        if (h1 == a1 && h2 == a2)
        {
            cout << ans;
            return 0;
        }
        if (a[h1] == 0)
            a[h1] = ans + 1;
        else
        {
            if (p1 == -1)
                p1 = ans - a[h1] + 1;
        }

        if (b[h2] == 0)
            b[h2] = ans + 1;
        else
        {
            if (p2 == -1)
                p2 = ans - b[h2] + 1;
        }

    }
    //cout << p1 << ' ' << p2 << endl;
    long long h10 = h1;
    long long t1 = 0;
    for (long long i = 0; i < p1; i++)
    {
        if (h10 == a1)
            break;
        h10 = (h10 * x1 + y1) % m;
        t1++;
    }
    if (p1 == t1)
    {
        cout << -1;
        return 0;
    }
    long long h20 = h2;
    long long t2 = 0;
    for (long long i = 0; i < p2; i++)
    {
        if (h20 == a2)
            break;
        h20 = (h20 * x2 + y2) % m;
        t2++;
    }
    if (p2 == t2)
    {
        cout << -1;
        return 0;
    }
    for (long long i = 0; i < p2; i++)
    {
        long long k = t1 + p1 * i;
        if (k % p2 == t2)
        {
            cout << ans + k;
            return 0;
        }
    }

    cout << -1;
    return 0;
}