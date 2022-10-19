#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n, m;
char s[N], t[N];

int pp[N], ss[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    n = strlen(s);
    m = strlen(t);
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (j < m && s[i] == t[j])
            ++j;
        pp[i] = j - 1;
    }
    j = m - 1;
    ss[n] = j + 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (j >= 0 && s[i] == t[j])
            --j;
        ss[i] = j + 1;
    }
    int ans = 0;
    for (int i = -1; i < n; ++i)
    {
        int l = i + 1, r = n;
        int ppp;
        if (i == -1)
            ppp = -1;
        else
            ppp = pp[i];
        while ((r - l) > 3)
        {
            int m = (l + r) / 2;
            if (ppp + 1 >= ss[m])
                l = m;
            else
                r = m;
        }
        for (int m = r; m >= l; --m)
        {
            if (ppp + 1 >= ss[m])
            {
                ans = max(ans, m - i - 1);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}