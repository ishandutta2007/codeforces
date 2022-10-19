#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
int a[N];

bool stg(int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        if (a[i] != a[i - 1] + 1 || a[i] != a[i + 1] - 1)
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = 0;
    a[n + 1] = 1001;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            if (stg(i, j))
                ans = max(ans, j - i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}