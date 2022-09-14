#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    long long p = 1;
    while (p * p < c)
        p++;
    long long ans = 0;
    if (wr > p)
    {
        for (long long i = 0; i * wr <= c; i ++)
        {
            long long j = (c - i * wr) / wb;
            ans = max(ans, i * hr + j * hb);
        }
        cout << ans;
        return 0;
    }

    if (wb > p)
    {
        for (long long j = 0; j * wb <= c; j ++)
        {
            long long i = (c - j * wb) / wr;
            ans = max(ans, i * hr + j * hb);
        }
        cout << ans;
        return 0;
    }

    for (long long i = 0; i <= wb && i * wr <= c; i ++)
    {
        long long j = (c - i * wr) / wb;
        ans = max(ans, i * hr + j * hb);
    }

    for (long long j = 0; j <= wr && j * wb <= c; j ++)
    {
        long long i = (c - j * wb) / wr;
        ans = max(ans, i * hr + j * hb);
    }
    cout << ans;
    return 0;
}