#include <bits/stdc++.h>
using namespace std;
const int N = 10004;

int n;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int i = 1;
    int ans = 0;
    while (1)
    {
        if (i == n + 1)
            break;
        ++ans;
        int maxu = a[i];
        ++i;
        for (; i <= n; ++i)
        {
            if (i > maxu)
                break;
            maxu = max(maxu, a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}