#include <bits/stdc++.h>
using namespace std;
const int N = 400005;

int n;
int a[N], b[N];

int h[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    int k = n + 1;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 1)
        {
            bool z = true;
            for (int j = i + 1; j <= n; ++j)
            {
                if (b[j] != b[j - 1] + 1)
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                k = i;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        h[b[i]] = i;
    }

    bool z = true;
    for (int i = n - k + 1 + 1, j = 0; i <= n; ++i, ++j)
    {
        if (h[i] > j)
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        cout << k - 1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, h[i] - i + 1);

    cout << ans + n << endl;
    return 0;
}