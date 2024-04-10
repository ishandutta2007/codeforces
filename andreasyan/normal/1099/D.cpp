#include <bits/stdc++.h>
using namespace std;
const int N = 100005, INF = 1000000007;

int n;
int p[N];
vector<int> a[N];
int s[N];

long long ans;

void dfs(int x)
{
    long long t = INF;
    for (int i = 0; i < a[x].size(); ++i)
    {
        int h = a[x][i];
        dfs(h);
        long long g = s[h] - s[p[x]];
        if (s[x] == -1)
        {
            t = min(t, g);
            ans += g;
        }
    }
    if (t < 0)
    {
        cout << -1 << endl;
        exit(0);
    }
    if (s[x] == -1)
    {
        if (!a[x].empty())
            ans -= ((a[x].size() - 1) * t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
    {
        a[p[i]].push_back(i);
        cin >> s[i];
    }
    ans = s[1];
    dfs(1);
    cout << ans << endl;
    return 0;
}