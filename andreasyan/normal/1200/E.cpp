#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
char a[N];

int m;
char b[N];

int z[N];
void ave()
{
    b[m++] = '#';
    for (int i = max(0, n - m); i < n; ++i)
        b[m++] = a[i];
    b[m] = '\0';
    int l = 0;
    int r = -1;
    for (int i = 1; i < m; ++i)
    {
        z[i] = 0;
        if (i <= r)
        {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (b[z[i]] == b[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            l = i;
        }
        if (i + z[i] == m)
        {
            for (int j = z[i]; ; ++j)
            {
                if (b[j] == '#')
                    break;
                a[n++] = b[j];
            }
            return;
        }
    }
    for (int j = 0; ; ++j)
    {
        if (b[j] == '#')
            break;
        a[n++] = b[j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        if (i == 0)
        {
            cin >> a;
            n = strlen(a);
        }
        else
        {
            cin >> b;
            m = strlen(b);
            ave();
        }
    }
    cout << a << endl;
    return 0;
}