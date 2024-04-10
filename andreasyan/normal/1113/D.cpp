#include <bits/stdc++.h>
using namespace std;
const int N = 5003;

int n;
char aa[N], a[N];

bool pal(const string& s)
{
    for (int i = 0, j = n - 1; i < n; ++i, --j)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

bool chhav(const string& s)
{
    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] != a[i])
            return true;
    }
    return false;
}

int main()
{
    cin >> aa;
    n = strlen(aa);
    for (int i = 1; i <= n; ++i)
        a[i] = aa[i - 1];

    bool z = false;
    for (int i = 1; i <= n / 2; ++i)
    {
        if (a[i] != a[1])
        {
            z = true;
            break;
        }
    }
    if (!z)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    for (int i = 1; i <= n - 1; ++i)
    {
        string s;
        for (int j = i + 1; j <= n; ++j)
            s += a[j];
        for (int j = 1; j <= i; ++j)
            s += a[j];
        if (pal(s) && chhav(s))
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 2 << endl;
    return 0;
}