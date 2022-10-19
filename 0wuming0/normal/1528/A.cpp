#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll l[200005],r[200005];
ll dpl[200005],dpr[200005];
int vis[200005];
vector<int>v[200005];
void cal(int i)
{
    vis[i]=1;
    for(auto a:v[i])if(vis[a]==0)
    {
        cal(a);
        dpl[i]+=max(dpl[a]+abs(l[a]-l[i]),dpr[a]+abs(r[a]-l[i]));
        dpr[i]+=max(dpl[a]+abs(l[a]-r[i]),dpr[a]+abs(r[a]-r[i]));
    }
    //cout<<"<<"<<i<<" "<<dpl[i]<<" "<<dpr[i]<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
        {vis[i]=0;v[i].clear();dpl[i]=dpr[i]=0;
        }
        for(int i=1;i<=n;i++)scanf("%lld%lld",l+i,r+i);
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cal(1);
        cout<<max(dpr[1],dpl[1])<<endl;
    }
    return 0;
}