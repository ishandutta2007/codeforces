#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 9;

int add(int &a, int b)
{
    a += b;
    if(a > mod)
        a -= mod;
    return a;
}

const int maxn = 1001, sigma = 26;
int len[maxn], link[maxn];
int to[maxn][sigma];
int sz = 1;

void add_str(string s)
{
    int v = 0;
    for(auto c: s)
    {
        c -= 'A';
        if(!to[v][c])
            to[v][c] = sz++;
        v = to[v][c];
    }
    len[v] = s.size();
}

void push_links()
{
    int que[sz];
    int st = 0, fi = 1;
    que[0] = 0;
    while(st < fi)
    {
        int v = que[st++];
        int u = link[v];
        if(!len[v])
            len[v] = len[u];
        for(int c = 0; c < sigma; c++)
            if(to[v][c])
            {
                link[to[v][c]] = v ? to[u][c] : 0;
                que[fi++] = to[v][c];
            }
            else
            {
                to[v][c] = to[u][c];
            }
    }
}

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int mlen = 0;
    while(m--)
    {
        string s;
        cin >> s;
        mlen = max(mlen, (int)s.size());
        add_str(s);
    }
    push_links();
    int dp[mlen][sz];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int z = 0; z < n; z++)
    {
        int dp1[mlen][sz];
        memset(dp1, 0, sizeof(dp1));
        for(int i = 0; i < sz; i++)
            for(int j = 0; j < mlen; j++)
                for(int c = 0; c < sigma; c++)
                    if(len[to[i][c]] > j)
                        add(dp1[0][to[i][c]], dp[j][i]);
                    else if(j + 1 < mlen)
                        add(dp1[j + 1][to[i][c]], dp[j][i]);
        memcpy(dp, dp1, sizeof(dp));
    }
    int ans = 0;
    for(int i = 0; i < sz; i++)
        add(ans, dp[0][i]);
    cout << ans << "\n";
}