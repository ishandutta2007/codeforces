#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];
int maxu = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxu = max(maxu, a[i]);
    }
    int ans = 0;
    int yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == maxu)
            ++yans;
        else
        {
            ans = max(ans, yans);
            yans = 0;
        }
    }
    ans = max(ans, yans);
    cout << ans << endl;
    return 0;
}