#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n, k;
int a[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    int q = 0;
    int ans = 0;
    for (int i = 1; i <= k; ++i)
    {
        ans += ((a[i] / 2) * 2);
        if (a[i] % 2 == 1)
            ++q;
    }
    ans += (q / 2);
    if (q % 2 == 1)
        ++ans;
    cout << ans << endl;
    return 0;
}