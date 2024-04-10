#include <bits/stdc++.h>
using namespace std;
const int N = 100005;

int n, m;
vector<int> a[N];

int t[N];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for (int i = 1; i <= m; ++i)
    {
        if (!a[i].empty())
        {
            sort(a[i].begin(), a[i].end());
            reverse(a[i].begin(), a[i].end());
        }
        int p = 0;
        for (int j = 0; j < a[i].size(); ++j)
        {
            p += a[i][j];
            if (p > 0)
                t[j] += p;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, t[i]);
    cout << ans << endl;
    return 0;
}