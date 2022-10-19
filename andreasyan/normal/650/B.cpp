#include <bits/stdc++.h>
using namespace std;
const int N = 500005;

int n, aa, bb, tt;
char a[N];

int p[N], s[N];
int main()
{
    cin >> n >> aa >> bb >> tt;
    cin >> a;
    for (int i = 0; i < n; ++i)
    {
        if (i)
            p[i] = p[i - 1] + aa;
        if (a[i] == 'w')
            p[i] += bb;
        p[i]++;
    }
    for (int i = n - 1; i >= 0; --i)
    {
        s[i] = s[i + 1] + aa;
        if (a[i] == 'w')
            s[i] += bb;
        s[i]++;
    }

    int ans = 0;

    int j = n;
    for (int i = n - 1; i >= 0; --i)
    {
        while (j - 1 != i && p[i] + s[j - 1] + i * aa <= tt)
            --j;
        if (p[i] + s[j] + i * aa <= tt)
            ans = max(ans, i + 1 + n - j);
    }

    j = n;
    for (int i = n - 1; i >= 0; --i)
    {
        while (j - 1 != i && p[i] + s[j - 1] + (n - j) * aa <= tt)
            --j;
        if (p[i] + s[j] + (n - j) * aa <= tt)
            ans = max(ans, i + 1 + n - j);
    }

    cout << ans << endl;
    return 0;
}