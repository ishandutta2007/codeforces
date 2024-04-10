#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("../input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int c[n];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    set<int> unused;
    for(int i = k + 1; i < 3 * n; i++)
        unused.insert(i);
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int x, int y){return c[x] > c[y];});
    int ans[n];
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        auto it = *unused.lower_bound(p[i] + 1);
        cnt += c[p[i]] * (it - p[i] - 1);
        ans[p[i]] = it;
        unused.erase(it);
    }
    cout << cnt << endl;
    for(auto it: ans)
        cout << it << ' ';
    return 0;
}