#include"bits/stdc++.h"
using namespace std;
vector<int>v[200005];
map<int,int>mp;
int ans[200005];
int nn;
int vis[200005];
void solve(int i)
{//cout<<"ok"<<endl;
    if(vis[i])return;
    vis[i]=nn;
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)
    {
        solve(*it);
        //vis[*it]=nn;
    }
}
void solve2(int i)
{
    for(vector<int>::iterator it=v[i].begin();it!=v[i].end();it++)if(!vis[*it])
    {
        printf("%d %d\n",*it,i);
        vis[*it]=1;
        solve2(*it);
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==1)v[1].push_back(b);
        else if(b==1)v[1].push_back(a);
        else
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }
    nn=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            solve(i);
            //vis[i]=nn;
            nn++;
        }
    }
    for(vector<int>::iterator it=v[1].begin();it!=v[1].end();++it)
    {
        ans[vis[*it]]=*it;
    }
    for(int i=1;i<nn;i++)if(ans[i]==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(k>v[1].size()||k<nn-1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<=n;i++)vis[i]=0;
    vis[1]=1;
    for(int i=1;i<nn;i++)
    {
        printf("%d %d\n",1,ans[i]);
        vis[ans[i]]=1;
    }
    {
        vector<int>::iterator it=v[1].begin();
        int num=nn-1;
        while(num<k)
        {
            while(vis[*it])it++;
            printf("%d %d\n",1,*it);
            vis[*it]=1;
            num++;
        }
    }
    for(int i=2;i<=n;i++)if(vis[i])
    {
        solve2(i);
    }
    return 0;
}
/*
5 5 3
1 2
1 3
1 4
3 5
1 5
*/