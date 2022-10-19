#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n, m;
int a[N], b[N];

int q[33];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        int j = 0;
        while (a[i])
        {
            if (a[i] % 2 == 1)
                ++q[j];
            a[i] /= 2;
            ++j;
        }
    }
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; ++i)
    {
        if (q[b[i]])
            --q[b[i]];
        else
        {
            int k = -1;
            for (int j = b[i]; j < 33; ++j)
            {
                if (q[j])
                {
                    k = j;
                    break;
                }
            }
            if (k == -1)
            {
                cout << i - 1 << endl;
                return 0;
            }
            q[k]--;
            for (int j = k - 1; j >= b[i]; --j)
            {
                q[j] = 1;
            }
        }
    }
    cout << m << endl;
    return 0;
}