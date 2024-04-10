#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
char a[N];

int q;
int l[N], r[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'S')
            l[i] = 0;
        else
            l[i] = l[i - 1] + 1;
    }
    for (int i = n; i >= 1; --i)
    {
        if (a[i] == 'S')
            r[i] = 0;
        else
            r[i] = r[i + 1] + 1;
    }
    for (int i = 1; i <= n; ++i)
        if (a[i] == 'G' && a[i - 1] != 'G')
            ++q;
    if (q == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    bool z = true;
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 'S')
        {
            z = false;
            if (l[i - 1] && r[i + 1])
            {
                if (q > 2)
                    ans = max(ans, l[i - 1] + r[i + 1] + 1);
                else
                    ans = max(ans, l[i - 1] + r[i + 1]);
            }
            else if (l[i - 1])
            {
                if (q > 1)
                    ans = max(ans, l[i - 1] + 1);
                else
                    ans = max(ans, l[i - 1]);
            }
            else if (r[i + 1])
            {
                if (q > 1)
                    ans = max(ans, r[i + 1] + 1);
                else
                    ans = max(ans, r[i + 1]);
            }
        }
    }
    if (z)
    {
        cout << n << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}