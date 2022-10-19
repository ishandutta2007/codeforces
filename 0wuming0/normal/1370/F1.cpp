#include"bits/stdc++.h"
using namespace std;
vector<int>v[1005];
int vis1[1005],vis2[1005];
int dis1[1005],dis2[1005];
int l,r,ans;
void solve(int i,int d,int dis[],int vis[])
{
    vis[i]=1;
    dis[i]=d;
    for(auto j:v[i])
    {
        if(vis[j]==0)solve(j,d+1,dis,vis);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cout<<"? "<<n;
        for(int i=1;i<=n;i++)cout<<" "<<i;
        cout<<endl;
        cin>>l>>ans;
        r=l;
        for(int i=1;i<=n;i++)vis1[i]=vis2[i]=0;
        solve(l,0,dis1,vis1);
        vector<int>save;
        for(int i=1;i<=n;i++)if(dis1[i]>=(ans+1)/2)save.push_back(i);
        while(1)
        {
            cout<<"? "<<save.size();
            for(auto i:save)cout<<" "<<i;
            cout<<endl;
            save.clear();
            int a1,a2;
            cin>>a1>>a2;
            if(vis1[a1]==1)
            {
                ans-=dis1[a1];
                l=a1;
            }
            else
            {
                ans-=dis2[a1];
                r=a1;
            }
            if(ans==0)break;
            for(int i=1;i<=n;i++)vis1[i]=vis2[i]=0;
            vis1[r]=1;vis2[l]=1;
            solve(l,0,dis1,vis1);
            solve(r,0,dis2,vis2);
            for(int i=1;i<=n;i++)
            {
                if(vis2[i]==0&&dis1[i]>=(ans+1)/2)save.push_back(i);
                else if(vis1[i]==0&&dis2[i]>=(ans+1)/2)save.push_back(i);
            }
        }
        if(l>r)swap(l,r);
        cout<<"! "<<l<<" "<<r<<endl;
        string s;
        cin>>s;
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}