#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
const long long INF = 2000000000000000007;

int n, rr;
long long k;
long long a[N];

vector<long long> pl[N], mn[N];

bool stg(long long x)
{
    if (x == 6)
        cout << "";
    for (int i = 1; i <= n + 1; ++i)
    {
        mn[i].clear();
    }
    long long kk = k;
    long long ad = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < mn[i].size(); ++j)
            ad -= mn[i][j];
        if (a[i] + ad < x)
        {
            if (kk < x - (a[i] + ad))
                return false;
            kk -= (x - (a[i] + ad));
            mn[min(n + 1, i + rr + rr + 1)].push_back(x - (a[i] + ad));
            ad += (x - (a[i] + ad));
        }
    }
    return true;
}

long long byn()
{
    long long l = 0, r = INF;
    while ((r - l) > 4)
    {
        long long m = (l + r) / 2;
        if (stg(m))
            l = m;
        else
            r = m;
    }
    for (long long m = r; m >= l; --m)
        if (stg(m))
            return m;
}

int main()
{
    scanf("%d%d%lld", &n, &rr, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        int l = max(1, i - rr);
        int r = min(n, i + rr);
        pl[l].push_back(a[i]);
        mn[r + 1].push_back(a[i]);
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < pl[i].size(); ++j)
            sum += pl[i][j];
        for (int j = 0; j < mn[i].size(); ++j)
            sum -= mn[i][j];
        a[i] = sum;
    }
    cout << byn() << endl;
    return 0;
}