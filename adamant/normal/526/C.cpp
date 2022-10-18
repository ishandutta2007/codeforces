#include <bits/stdc++.h>

using namespace std;

#define int int64_t

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C, Hr, Hb, Wb, Wr;
    cin >> C >> Hr >> Hb >> Wr >> Wb;
    int ans = 0;
    for(int i = 0; i <= 5000000; i++)
    {
        int j;
        if(1LL * i * Wr <= C)
        {
            j = (C - 1LL * i * Wr) / Wb;
            ans = max(ans, i * Hr + j * Hb);
        }
        if(1LL * i * Wb <= C)
        {
            j = (C - 1LL * i * Wb) / Wr;
            ans = max(ans, i * Hb + j * Hr);
        }
    }

    for(int k = -5000000; k <= 5000000; k++)
    {
        int i = C / Wr + k;
        if(i < 0)
            continue;
        int j;
        if(i * Wr <= C)
        {
            j = (C - 1LL * i * Wr) / Wb;
            ans = max(ans, i * Hr + j * Hb);
        }
        if(i * Wb <= C)
        {
            j = (C - 1LL * i * Wb) / Wr;
            ans = max(ans, i * Hb + j * Hr);
        }
    }
    for(int k = -5000000; k <= 5000000; k++)
    {
        int i = C / Wb + k;
        if(i < 0)
            continue;
        int j;
        if(i * Wr <= C)
        {
            j = (C - 1LL * i * Wr) / Wb;
            ans = max(ans, i * Hr + j * Hb);
        }
        if(i * Wb <= C)
        {
            j = (C - 1LL * i * Wb) / Wr;
            ans = max(ans, i * Hb + j * Hr);
        }
    }

    for(int k = 0; k <= min(5000000LL, C); k++)
    {
        int i = C - k;
        int j;
        if(i * Wr <= C)
        {
            j = (C - 1LL * i * Wr) / Wb;
            ans = max(ans, i * Hr + j * Hb);
        }
        if(i * Wb <= C)
        {
            j = (C - 1LL * i * Wb) / Wr;
            ans = max(ans, i * Hb + j * Hr);
        }
    }
    cout << ans << "\n";
    /*
    int n, q;
    cin >> n >> q;
    int a[n];
    for(auto &it: a)
        cin >> it;
    int s[2 * n + 1];
    s[0] = 0;
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i - 1];
    for(int i = 1; i <= n; i++)
        s[i + n] = s[i + n - 1] + a[i - 1];

    int logn = 20;
    while(q--)
    {
        int64_t b;
        cin >> b;
        int cnt[n][logn];
        int space[n][logn];
        for(int i = 0; i < n; i++)
        {
            cnt[i][0] = 1;
            space[i][0] = 0;
            for(int j = (1 << logn); j; j /= 2)
            {
                if(i + space[i][0] + j >= 2 * n + 1)
                    continue;
                if(s[i + space[i][0] + j] - s[i] <= b)
                    space[i][0] += j;
            }
        }
        for(int j = 1; j < logn; j++)
        {
            for(int i = 0; i < n; i++)
            {
                cnt[i][j] = cnt[i][j - 1];
                space[i][j] = space[i][j - 1];

                for(int j = (1 << logn); j; j /= 2)
                {
                    if(i + space[i][0] + j >= 2 * n + 1)
                        continue;
                    if(s[i + space[i][0] + j] - s[i] <= b)
                        space[i][0] += j;
                }
            }
        }
    }*/
    return 0;
}