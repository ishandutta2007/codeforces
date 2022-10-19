#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n;
int a[N];

char ans[N];
int px[N];
long long sum[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ans[n - 1] = '+';
    sum[n - 1] = a[n - 1];

    for (int i = n - 2; i >= 0; --i)
    {
        if (0 <= sum[i + 1] && sum[i + 1] <= a[i])
        {
            px[i + 1] = 1;
            ans[i] = '+';
            sum[i] = -sum[i + 1] + a[i];
        }
        else if (a[i] < sum[i + 1] && sum[i + 1] <= 2 * a[i])
        {
            ans[i] = '-';
            sum[i] = sum[i + 1] - a[i];
        }
    }

    int ypx = 0;
    for (int i = 0; i < n; ++i)
    {
        ypx ^= px[i];
        if (ypx == 1 && ans[i] == '+')
            ans[i] = '-';
        else if (ypx == 1 && ans[i] == '-')
            ans[i] = '+';
    }
    cout << ans << endl;
    return 0;
}