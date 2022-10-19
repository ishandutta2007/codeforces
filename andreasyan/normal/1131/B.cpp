#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int hat(int l1, int r1, int l2, int r2)
{
    if (l1 > l2)
    {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (r2 <= r1)
        return (r2 - l2 + 1);
    if (r1 < l2)
        return 0;
    return (r1 - l2 + 1);
}

int n;
int x[N], y[N];

int main()
{
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i];
        ans += hat(x[i - 1], x[i], y[i - 1], y[i]) - (x[i - 1] == y[i - 1]);
    }
    cout << ans << endl;
    return 0;
}