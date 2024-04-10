#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct ban
{
    long long i, c;
};
bool operator<(const ban& a, const ban& b)
{
    if (a.c < b.c)
        return true;
    if (a.c > b.c)
        return false;
    return a.i < b.i;
}

int n, m;
long long a[N];
long long c[N];

ban t[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        t[i].i = i;
        t[i].c = c[i];
    }
    sort(t + 1, t + n + 1);
    int j = 1;
    while (m--)
    {
        long long x, q;
        cin >> x >> q;
        long long ans = 0;
        if (a[x] >= q)
        {
            ans += (q * c[x]);
            a[x] -= q;
            q = 0;
            cout << ans << endl;
            continue;
        }
        ans += (a[x] * c[x]);
        q -= a[x];
        a[x] = 0;
        while (j != n + 1)
        {
            x = t[j].i;
            if (a[x] >= q)
            {
                ans += (q * c[x]);
                a[x] -= q;
                q = 0;
                break;
            }
            ans += (a[x] * c[x]);
            q -= a[x];
            a[x] = 0;
            ++j;
        }
        if (q == 0)
            cout << ans << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}