#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void rec(int m, vector<int> &x, int k, int l, int r)
{
    if(r - l == 1)
    {
        x[l] = k;
        return;
    }
    int z = 1LL << ((r - l) - 2);
    if(z < m)
    {
        x[r - 1] = k;
        rec(m - z, x, k + 1, l, r - 1);
    }
    else
    {
        x[l] = k;
        rec(m, x, k + 1, l + 1, r);
    }
}

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    rec(m, ans, 1, 0, n);
    for(auto it: ans)
        cout << it << ' ';
    return 0;
}