#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int ans;

bool stg(int ll, int rr, int l, int r)
{
    if ((r - l) > (rr - ll))
        return false;
    for (int i = ll; i <= (rr - (r - l + 1)) + 1; ++i)
    {
        int j = (i + (r - l + 1) - 1);
        bool z = true;
        for (int ii = i, jj = l; ii <= j && jj <= r; ++ii, ++jj)
        {
            if (a[ii] != a[jj])
            {
                z = false;
                break;
            }
        }
        if (z)
            return true;
    }
    return false;
}

int main()
{
    cin >> n >> a;
    ans = n;
    for (int i = 1; i < n; ++i)
    {
        int l = i, r = n - 1;
        while ((r - l) > 4)
        {
            int m = (l + r) / 2;
            if (stg(0, i - 1, i, m))
                l = m;
            else
                r = m;
        }
        for (int m = r; m >= l; --m)
            if (stg(0, i - 1, i, m))
            {
                if ((m - i + 1) == i)
                ans = min(ans, n - (m - i + 1) + 1);
            }
    }
    cout << ans << endl;
    return 0;
}