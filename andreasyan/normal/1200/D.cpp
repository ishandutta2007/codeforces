#include <bits/stdc++.h>
using namespace std;
const int N = 2003;

int n, k;
char a[N][N];

int lt[N], rt[N], ls[N], rs[N];

int u[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int pans = 0;
    for (int i = 0; i < n; ++i)
    {
        lt[i] = -1;
        rt[i] = -1;
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 'B')
            {
                if (lt[i] == -1)
                    lt[i] = j;
                rt[i] = j;
            }
        }
        if (lt[i] == -1)
            pans++;
    }
    for (int j = 0; j < n; ++j)
    {
        ls[j] = -1;
        rs[j] = -1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i][j] == 'B')
            {
                if (ls[j] == -1)
                    ls[j] = i;
                rs[j] = i;
            }
        }
        if (ls[j] == -1)
            pans++;
    }
    for (int i = 0; i < k; ++i)
    {
        int l = lt[i], r = rt[i];
        if (l != -1)
        {
            if ((r - l + 1) <= k)
            {
                u[max(0, r - k + 1)]++;
                u[l + 1]--;
            }
        }
    }
    int ans = pans;
    for (int i = 0; i <= n - k; ++i)
    {
        int ppans = 0;
        for (int j = 0; j < k; ++j)
        {
            if (i <= ls[j] && rs[j] <= i + k - 1)
                ++ppans;
        }
        for (int j = 0; j <= n - k; ++j)
        {
            ppans += u[j];
            ans = max(ans, pans + ppans);
            if (i <= ls[j] && rs[j] <= i + k - 1)
                --ppans;
            if (i <= ls[j + k] && rs[j + k] <= i + k - 1)
                ++ppans;
        }
        int l = lt[i], r = rt[i];
        if (l != -1)
        {
            if ((r - l + 1) <= k)
            {
                u[max(0, r - k + 1)]--;
                u[l + 1]++;
            }
        }
        l = lt[i + k], r = rt[i + k];
        if (l != -1)
        {
            if ((r - l + 1) <= k)
            {
                u[max(0, r - k + 1)]++;
                u[l + 1]--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}