#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 522, sigma = 26;
int a[maxn];

int to[maxn][sigma];
int link[maxn], cost[maxn];
int sz = 1;
void add_str(string s, int n)
{
    int v = 0;
    for(auto c: s)
    {
        c -= 'a';
        if(!to[v][c])
            to[v][c] = sz++;
        v = to[v][c];
    }
    cost[v] += a[n];
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
        cost[v] += cost[u];
        for(int c = 0; c < sigma; c++)
        {
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
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        add_str(s, i);
    }
    push_links();
    const int logn = 50;
    int best[logn][sz][sz];
    memset(best, -1, sizeof(best));
    for(int i = 0; i < sz; i++)
        for(int c = 0; c < sigma; c++)
            best[0][i][to[i][c]] = cost[to[i][c]];
    for(int z = 1; z < logn; z++)
        for(int k = 0; k < sz; k++)
            for(int i = 0; i < sz; i++)
                for(int j = 0; j < sz; j++)
                    if(best[z - 1][i][k] != -1 && best[z - 1][k][j] != -1)
                        best[z][i][j] = max(best[z][i][j], best[z - 1][i][k] + best[z - 1][k][j]);
    int ans[sz][sz];
    memset(ans, -1, sizeof(ans));
    for(int i = 0; i < sz; i++)
        ans[i][i] = 0;
    for(int z = 0; z < logn; z++)
    {
        if((l >> z) & 1)
        {
            int tmp[sz][sz];
            memset(tmp, -1, sizeof(tmp));
            for(int k = 0; k < sz; k++)
                for(int i = 0; i < sz; i++)
                    for(int j = 0; j < sz; j++)
                        if(ans[i][k] != -1 && best[z][k][j] != -1)
                            tmp[i][j] = max(tmp[i][j], ans[i][k] + best[z][k][j]);
            memcpy(ans, tmp, sizeof(ans));
        }
    }
    int out = 0;
    for(int i = 0; i < sz; i++)
        out = max(out, ans[0][i]);
    cout << out << "\n";
	return 0;
}