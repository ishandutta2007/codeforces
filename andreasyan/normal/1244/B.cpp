#include <bits/stdc++.h>
using namespace std;
const int N = 1003;

int n;
char a[N];

void solv()
{
    cin >> n;
    cin >> a;
    int ans = n;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '1')
            ans = max(ans, max(i + 1, n - i) * 2);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}