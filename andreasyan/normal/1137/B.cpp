#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, m;
char a[N], b[N];
int t[2];

int z[N];

int nn;
char aa[N];

int main()
{
    cin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    for (int i = 0; i < n; ++i)
        t[a[i] - '0']++;
    int mm = m;
    b[mm++] = '#';
    for (int i = 0; i < m; ++i)
        b[mm++] = b[i];
    int r = 0, j;
    for (int i = 1; i < mm; ++i)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - j]);
        }
        while (i + z[i] < mm && b[i + z[i]] == b[z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            r = i + z[i] - 1;
            j = i;
        }
    }
    int u = 0;
    for (int i = m + 2; i < mm; ++i)
    {
        if (i + z[i] == mm)
        {
            u = (mm - i);
            break;
        }
    }
    for (int i = 0; i < m; ++i)
        aa[nn++] = b[i];
    for (int i = u; i < m; ++i)
        aa[nn++] = b[i];
    j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (t[aa[j] - '0'])
        {
            cout << aa[j];
            --t[aa[j] - '0'];
        }
        else
        {
            if (t[0])
            {
                cout << 0;
                --t[0];
            }
            else
            {
                cout << 1;
                --t[1];
            }
        }
        ++j;
        if (j == nn)
            j = u;
    }
    cout << endl;
    return 0;
}