#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, x;
int a[N];
int minu[N], maxu[N];

int p[N], s[N];

int pp, ss;

bool stg(int l, int r)
{
    return (l - 1 <= pp && r + 1 >= ss && (p[l - 1] == 0 || s[r + 1] == 0 || maxu[p[l - 1]] <= minu[s[r + 1]]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (minu[a[i]] == 0)
            minu[a[i]] = i;
        maxu[a[i]] = i;
    }
    for (int i = 1; i <= x; ++i)
    {
        if (minu[i])
            p[i] = i;
        else
            p[i] = p[i - 1];
    }
    for (int i = 1; i <= x; ++i)
    {
        if (minu[i])
        {
            if (p[i - 1] == 0 || maxu[p[i - 1]] < minu[i])
                pp = i;
            else
                break;
        }
        else
            pp = i;
    }
    for (int i = x; i >= 1; --i)
    {
        if (maxu[i])
            s[i] = i;
        else
            s[i] = s[i + 1];
    }
    for (int i = x; i >= 1; --i)
    {
        if (maxu[i])
        {
            if (s[i + 1] == 0 || maxu[i] < minu[s[i + 1]])
                ss = i;
            else
                break;
        }
        else
            ss = i;
    }

    long long ans = 0;
    for (int i = 1; i <= x; ++i)
    {
        int l = i, r = x;
        while ((r - l) > 4)
        {
            int m = (l + r) / 2;
            if (stg(i, m))
                r = m;
            else
                l = m;
        }
        for (int m = l; m <= r; ++m)
        {
            if (stg(i, m))
            {
                ans += (x - m + 1);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}