#include <bits/stdc++.h>
using namespace std;

int lcm(int a,int b)
{
return a/__gcd(a,b)*b;
}

int mx=1e9;
int n, m, ans=1, len;
char a[105][105], kil[105];
bool visit[105];
vector <int> g[55000];

void dfs(int v)
{
    len++;
    visit[v]=true;
    for(int j=0; j<g[v].size(); j++)
    {
        int kuda=g[v][j];
        if(visit[kuda]==false)
        {
            dfs(kuda);
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        kil[x]++;
        g[i].push_back(x);
    }
    for(int i=1; i<=n; i++)
    {
        if(kil[i]!=1)return cout<<-1, 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(visit[i]==false)
        {
            len=0;
            dfs(i);
        }
        if(len%2==0)ans=lcm(ans, len/2);
        else ans=lcm(ans, len);
    }
    cout<< ans;

    return 0;
}