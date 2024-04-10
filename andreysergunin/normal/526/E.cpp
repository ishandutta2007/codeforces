#include <bits/stdc++.h>

using namespace std;
int MAXN = 2100000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    cin >> n >> q;
    int a[MAXN];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }
    long long s0 = 0;
    for (int i = 0; i < n; i++)
        s0 += a[i];
    for (int w = 0; w < q; w++)
    {
        int b;
        cin >> b;
        int r = 1;
        long long s = a[0];
        if (s0 <= b)
        {
            cout << "1\n";
            continue;
        }
        int next[MAXN];
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            while (s <= b)
                s += a[r++];

            next[i] = r - i - 1;
            next[i + n] = r - i - 1;
            s -= a[i];

            if (next[i] < next[m])
                m = i;
        }
        int ans = 1e9;

        for (int i = 0; i <= next[m]; i++)
        {
            int st = (m + i) % n;
            int k = (m + i) % n;
            int l = 0;
            while (k + next[k] < n + st)
            {
                k += next[k];
                l++;
            }
            ans = min (ans, l + 1);
        }
        cout << ans << endl;
    }
    return 0;
}