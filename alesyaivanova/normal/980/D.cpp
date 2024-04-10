#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
    {
        a[i].second = i;
        for (int d = 2; d * d <= abs(a[i].first); d++)
        {
            int q = d * d;
            bool t = true;
            while (t)
            {
                int e = a[i].first / q;
                if (e * q == a[i].first)
                    a[i].first = e;
                else
                    t = false;
            }
        }
    }
    sort(a, a + n);
    int pr = -1000000000;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first == pr)
            a[i].first = num;
        else if (a[i].first != 0)
        {
            pr = a[i].first;
            num++;
            a[i].first = num;
        }
    }
    num++;
    sort(a, a + n, cmp);
    int ans[n + 1] = {};
    for (int i = 0; i < n; i++)
    {
        bool used[num] = {};
        int k = 0;
        for (int e = i; e < n; e++)
        {
            if (a[e].first != 0 && !used[a[e].first])
            {
                used[a[e].first] = true;
                k++;
            }
            ans[max(k, 1)]++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}