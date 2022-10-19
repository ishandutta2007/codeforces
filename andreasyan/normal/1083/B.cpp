#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;

int n, k;
char a[N];
char b[N];

int t[N];
int32_t main()
{
    cin >> n >> k;
    cin >> a >> b;
    bool z = true;
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (z)
        {
            if (a[i] == b[i])
            {
                t[i] = 1;
            }
            else
            {
                z = false;
                t[i] = 2;
            }
        }
        else
        {
            t[i] = (t[i - 1] - 2) * 2 + 2;
            if (a[i] == 'a')
                t[i]++;
            if (b[i] == 'b')
                t[i]++;
            t[i] = min(t[i], k);
            t[i] = max(t[i], 2LL);
        }
        ans += min(k, t[i]);
    }
    cout << ans << endl;
    return 0;
}