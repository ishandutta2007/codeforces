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
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << max(*max_element(a, a + n) - 25, (int)0) << endl;
    return 0;
}