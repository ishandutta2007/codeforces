#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42, sigma = 26;

int to[maxn][sigma];
int link[maxn];
int num[maxn];
int len[maxn];
string t[maxn];
int sz = 1;

void add_str(string s, int i)
{
    int v = 0;
    for(auto c: s)
    {
        c = tolower(c);
        c -= 'a';
        if(!to[v][c])
            to[v][c] = sz++;
        len[to[v][c]] = len[v] + 1;
        v = to[v][c];
    }
    num[v] = i;
}

int que[maxn];
void push_links()
{
    int st = 0, fi = 1;
    que[0] = 0;
    while(st < fi)
    {
        int v = que[st++];
        int u = link[v];
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

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(num, -1, sizeof(num));
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> t[i];
        reverse(t[i].begin(), t[i].end());
        add_str(t[i], i);
    }
    push_links();
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int v = 0;
    for(int i = 1; i <= n; i++)
    {
        int c = s[i - 1] - 'a';
        v = to[v][c];
        for(int u = v; len[u] > 0; u = link[u])
            if(dp[i - len[u]] != -1 && num[u] != -1)
                dp[i] = num[u];
    }
    int pos = n;
    vector<string> ans;
    while(pos > 0)
    {
        string kk = t[dp[pos]];
        pos -= kk.size();
        ans.push_back(kk);
    }
    reverse(ans.begin(), ans.end());
    for(auto it: ans)
    {
        reverse(it.begin(), it.end());
        cout << it << ' ';
    }
}