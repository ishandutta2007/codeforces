#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 100009;
int pr[MAX_N];
int h[MAX_N];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n >> s;
    if (s > (n + 1) * n / 2 || s < 2 * n - 1)
    {
        cout << "No";
        return 0;
    }
    int left = 0;
    int right = n;
    while (right - left > 1)
    {
        int m = (left + right) / 2;
        int cur = 0;
        int p = 1;
        int t = 1;
        int u = n;
        while (u > 0)
        {
            cur += min(u, p) * t;
            u -= min(u, p);
            t++;
            p *= m;
        }
        if (cur <= s)
            right = m;
        else
            left = m;
    }
    int k = right;
    int cur = 0;
    int p = 1;
    int t = 1;
    int u = n;
    while (u > 0)
    {
        cur += min(u, p) * t;
        u -= min(u, p);
        t++;
        p *= k;
    }
    h[1] = 1;
    int pr_v = 1;
    int cur_cnt = 0;
    int cur_pr = 1;
    for (int i = 2; i <= n; i++)
    {
        pr[i] = cur_pr;
        cur_cnt++;
        if (cur_cnt == k)
        {
            cur_cnt = 0;
            cur_pr++;
        }
        h[i] = h[pr[i]] + 1;
        if (h[i] > h[i - 1])
            pr_v = i;
    }
    int cur_h = t;
    int i = n;
    int cur_used = pr_v;
    while (cur < s)
    {
        if (i == cur_used)
        {
            cur_used = pr[cur_used];
            i--;
            continue;
        }
        if (cur_h - h[i] <= s - cur)
        {
            pr[i] = pr_v;
            pr_v = i;
            cur += cur_h - h[i];
            cur_h++;
        }
        else
        {
            while (cur_h - h[i] > s - cur)
            {
                pr_v = pr[pr_v];
                cur_h--;
            }
            pr[i] = pr_v;
            pr_v = i;
            cur += cur_h - h[i];
            cur_h++;
        }
        i--;
    }
    cout << "Yes\n";
    for (int i = 2; i <= n; i++)
        cout << pr[i] << " ";
}