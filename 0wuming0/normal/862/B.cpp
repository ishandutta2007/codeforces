#include"bits/stdc++.h"
using namespace std;
vector<int>v[100005];
long long num[2];
int vis[100005];
void dfs(int i,int op)
{
    vis[i]=1;
    num[op]++;
    for(auto j:v[i])if(vis[j]==0)
    {
        dfs(j,op^1);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0);
    cout<<num[0]*num[1]-n+1<<endl;
    return 0;
}