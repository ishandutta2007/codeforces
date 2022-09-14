#include <bits/stdc++.h>

using namespace std;
const int MAXN = 300000;
const int MAXK = 30;
map<int, int> m;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q, k;
    cin >> n >> k;
    int a[MAXN];
    int x[MAXK];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    for (int i = 0; i < q; i++)
        cin >> x[i];

    for (int i = 0; i < n; i++)
        for (int j = 1; j <= k; j++)
            m[a[i] * j] = j;

    for (int i = 0; i < q; i++)
    {
        int ans = 100;
        for (int j = 0; j < n; j++)
            for (int l = 1; l <= k; l++)
            {
                if (x[i] - l * a[j] < 0)
                    continue;
                if (x[i] - l * a[j] == 0)
                {
                    ans = min (ans, l);
                    continue;
                }
                if (m[x[i] - l * a[j]] > 0 && m[x[i] - l * a[j]] + l <= k)
                    ans = min (ans, m[x[i] - l * a[j]] + l);
            }
        if (ans == 100)
            cout << - 1 << endl;
        else
            cout << ans << endl;
    }
}