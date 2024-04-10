#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    cin >> n;
    int ans = 2 * n + 2;
    for(int a = 1; a <= 10000; a++)
        for(int b = 1; b <= 10000; b++)
            if(a * b >= n)
                ans = min(ans, 2 * (a + b));
    cout << ans << endl;
    return 0;
}