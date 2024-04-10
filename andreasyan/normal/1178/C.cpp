#include <bits/stdc++.h>
using namespace std;
const int M = 998244353;

int n, m;

int main()
{
    cin >> n >> m;
    int ans = 1;
    for (int i = 1; i <= n + m; ++i)
    {
        ans = (ans * 2) % M;
    }
    cout << ans << endl;
    return 0;
}