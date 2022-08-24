#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 1;
const int M = 1e9 + 7;
vector <int> g[N];

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int sz = 1;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
    }
    sort(g + 1, g + m + 1);
    int cur = 0;
    for (int i = 1; i <= m; i++)
    {
        if (g[i] != g[i - 1])
        {
            cur = 0;
        }
        cur++;
        ans = (ans * (ll) cur) % M;
    }
    cout << ans << '\n';
}