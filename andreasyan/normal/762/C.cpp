#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
char aa[N];
char a[N], b[N];

int p[N], s[N];

int ans;
int ansl, ansr;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> aa;
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];
    cin >> aa;
    m = strlen(aa);
    for (int i = 1; i <= m; ++i)
        b[i] = aa[i - 1];

    for (int i = 1; i <= m; ++i)
    {
        p[i] = p[i - 1];
        if (p[i] == -1)
        {
            continue;
        }
        for (int j = p[i] + 1; j <= n; ++j)
        {
            if (b[i] == a[j])
            {
                p[i] = j;
                break;
            }
        }
        if (p[i] == p[i - 1])
            p[i] = -1;
    }

    s[m + 1] = n + 1;
    for (int i = m; i >= 1; --i)
    {
        s[i] = s[i + 1];
        if (s[i] == -1)
        {
            continue;
        }
        for (int j = s[i] - 1; j >= 1; --j)
        {
            if (b[i] == a[j])
            {
                s[i] = j;
                break;
            }
        }
        if (s[i] == s[i + 1])
            s[i] = -1;
    }

    for (int i = 0; i <= m; ++i)
    {
        if (p[i] == -1)
            break;
        int l = i + 1, r = m + 1;
        while ((r - l) > 3)
        {
            int mid = (l + r) / 2;
            if (s[mid] != -1 && p[i] < s[mid])
                r = mid;
            else
                l = mid;
        }
        for (int mid = l; mid <= r; ++mid)
        {
            if (s[mid] != -1 && p[i] < s[mid])
            {
                if (ans < i + (m - mid + 1))
                {
                    ans = i + (m - mid + 1);
                    ansl = i;
                    ansr = mid;
                }
                break;
            }
        }
    }
    if (ans == 0)
    {
        cout << "-" << endl;
        return 0;
    }
    for (int i = 1; i <= ansl; ++i)
        cout << b[i];
    for (int i = ansr; i <= m; ++i)
        cout << b[i];
    cout << endl;
    return 0;
}