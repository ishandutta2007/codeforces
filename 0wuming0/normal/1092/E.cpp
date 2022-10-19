#include"bits/stdc++.h"
using namespace std;
vector<int>v[1005];
int vis[1005];
pair<int,int>pr[1005];
int ans[1005];
int nn;
int now;
void solve(int i)
{
    vis[i]=now;
    for(auto j:v[i])if(vis[j]==0)
    {
        solve(j);
        ans[i]=max(ans[j]+1,ans[i]);
    }
}
int anss;
void add(int i)
{
    int sum=-1,sj;
    for(auto j:v[i])if(ans[j]==ans[i]-1)sj=j;
    for(auto j:v[i])if(j!=sj&&ans[j]>sum)sum=ans[j];
    if(sum+2>=ans[i])
    {
        pr[nn++]=make_pair(ans[i],i);
        anss=max(anss,sum+1+ans[i]);
    }
    else
    {
        ans[i]=sum+1;
        add(sj);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)if(vis[i]==0)
    {
        now=i;
        solve(i);
        add(i);
    }
    sort(pr,pr+nn);
    if(nn>=2)anss=max(pr[nn-1].first+pr[nn-2].first+1,anss);
    if(nn>=3)anss=max(pr[nn-2].first+pr[nn-3].first+2,anss);
    cout<<anss<<endl;
    for(int i=1;i<nn;i++)
    {
        printf("%d %d\n",pr[i-1].second,pr[nn-1].second);
    }
    return 0;
}