#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 300005;
vector < vector < pair < int, string > > > g;
int pr[maxn];
char temp[maxn]; 
int tlen;
int n;
long long ans = 0;
int curr_pos = 0;

int add(int pos, const string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        int j = pr[pos+i-1];
        
        while (j > 0 && str[i] != temp[j]) 
            j = pr[j-1];
            
        if (temp[j] == str[i])
            j++;
            
        pr[i+pos] = j;
        
        if (j == tlen)
            ans++;
    }
    
    return pos + str.size();
}

void dfs(int v)
{
    for (int i = 0; i < g[v].size(); i++)
    {
        int prev = curr_pos;
        curr_pos = add(curr_pos, g[v][i].second);
        dfs(g[v][i].first);
        curr_pos = prev;
    }
}

int main()
{
    /*freopen("E.in", "w", stdout);
    printf("3\n");
    for (int i = 1; i < 3; i++)
    {
        if (i&1)
        printf("%d abc\n", i);
        else
        printf("%d dbc\n", i);
    }
    printf("bcabc\n");
    return 0;
    
    freopen("E.in", "r", stdin);*/
    
    scanf("%d\n", &n);
    g.resize(n);
    
    for (int i = 1; i < n; i++)
    {
        int p;
        scanf("%d ", &p);
        p--;
        gets(temp);
        g[p].push_back(make_pair(i, string(temp)));
    }
    gets(temp);
    tlen = strlen(temp);
    string t = string(temp+1) + '#';
    curr_pos = add(1, t);
    dfs(0);
    printf("%I64d", ans);
}