#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n + 2];
    a[0] = a[n + 1] = -inf;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ans[n + 1];
    int l[n + 1], r[n + 1];
    vector<int> elem;
    elem.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        while(a[elem.back()] >= a[i])
            elem.pop_back();
        l[i] = elem.back();
        elem.push_back(i);
    }
    elem.clear();
    elem.push_back(n + 1);
    for(int i = n; i >= 1; i--)
    {
        while(a[elem.back()] >= a[i])
            elem.pop_back();
        r[i] = elem.back();
        elem.push_back(i);
    }
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++)
        ans[r[i] - l[i] - 1] = max(ans[r[i] - l[i] - 1], a[i]);
    for(int i = n - 1; i >= 1; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}