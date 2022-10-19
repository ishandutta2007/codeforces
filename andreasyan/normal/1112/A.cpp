#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n, m, k;

int a[N];
int d[N];

int maxu[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
        maxu[d[i]] = max(maxu[d[i]], a[i]);
    }
    int ans = 0;
    while (k--)
    {
        int x;
        cin >> x;
        if (a[x] < maxu[d[x]])
            ++ans;
    }
    cout << ans << endl;
    return 0;
}