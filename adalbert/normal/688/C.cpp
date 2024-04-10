#include <bits/stdc++.h>


using namespace std;
long long n,m,k1,k2,use[1000000],q,u,v,g;
vector <long long> vec[10000000];

string s,st;
void dfs(long long u,long long r)
{
    use[u]=r;
    for (int i=0; i< vec[u].size() ; i++)
    if (use[vec[u][i]]==0&&r==2) dfs(vec[u][i],1); else
    if (use[vec[u][i]]==0&&r==1) dfs(vec[u][i],2); else
    if (use[vec[u][i]]==r) q=9;
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
    if (use[i]==0)
    dfs(i,1);
    if (g==9) cout<<-1;

    for (int i=1;i<=n;i++)
    if (use[i]==1) k1++;
    for (int i=1;i<=n;i++)
    if (use[i]==2) k2++;
    if (q==9) 
    {
    	cout<<-1;
    	return(0);
    }
    cout<<k1<<'\n';
    for (int i=1;i<=n;i++)
    if (use[i]==1) cout<<i<<' ';
    cout<<'\n';
    cout<<k2<<'\n';
    for (int i=1;i<=n;i++)
    if (use[i]==2) cout<<i<<' ';
}