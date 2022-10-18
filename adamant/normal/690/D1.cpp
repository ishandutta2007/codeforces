#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int par[maxn];
int get(int v)
{
    if(par[v] == v)
        return v;
    return par[v] = get(par[v]);
}

int uni(int a, int b)
{
    a = get(a);
    b = get(b);
    if(a == b)
        return 0;
    par[a] = b;
    return 1;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par, par + maxn, 0);
    int n, m;
    cin >> n >> m;
    string s[n + 2];
    s[0] = s[n + 1] = string(m + 2, '.');
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = "." + s[i] + ".";
        for(auto it: s[i])
            ans += it == 'B';
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 0; k < 4; k++)
                if(s[i][j] == 'B' && s[i + dx[k]][j + dy[k]] == 'B')
                    if(uni(i * m + j, (i + dx[k]) * m + (j + dy[k])))
                        ans--;
    cout << ans << "\n";
	return 0;
}