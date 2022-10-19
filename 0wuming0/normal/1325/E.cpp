#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[1000006];
int prime[1000006];
int pnum[1000006];
int nump[1000006];
//int v[1000][1000];
int vis[1000006];
int visreson[1000006];
int save[1000005],nn;
int ans=1e9;
int ans0=1e9;
int nnow=0;
int savemap[1000006];
vector<int>saveans[205];
#define pmax 1000006
vector<int>v[pmax];
void ko(int now)
{
    for(vector<int>::iterator it=v[now].begin();it!=v[now].end();it++)if(*it!=nnow)
    //for(int j=1;j<=200;j++)if(v[now][j])
    {
        #define j *it
        if(vis[j]==-1)
        {
            if(vis[now]==0)visreson[j]=j;
            else visreson[j]=visreson[now];
            vis[j]=vis[now]+1;
            save[nn++]=j;
            if(savemap[nump[*it]])saveans[nnow].push_back(vis[j]);
        }
        else if(visreson[j]!=visreson[now])
        {//cout<<nnow<<endl;cout<<j<<" "<<now<<" "<<visreson[j]<<endl;
            ans=min(ans,vis[j]+vis[now]+1);
            //cout<<j<<" "<<" "<<now<<" "<<ans<<endl;
            //cout<<j<<":"<<vis[j]<<endl;
        }
        #undef j
    }
}
int main()
{
    int n;
    for(int i=2;i<pmax;i++)if(prime[i]==0)
    {
        for(int j=2;i*j<pmax;j++)prime[i*j]=i;
    }
    int num=1;for(int i=2;i<pmax;i++)if(prime[i]==0)
    {
        nump[num]=i;
        pnum[i]=(num++);//cout<<(num++)<<":"<<i<<endl;
    }
    //cout<<num<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=1000;i++)if(a[i*i])
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=2;i<=1000;i++)
    {
        int j=1;
        while(i*i*j<=1000000)j++;j--;
        for(;j>0;j--)
        {
            a[j]+=a[i*i*j];
            a[i*i*j]=0;
        }
    }
    for(int i=1;i<=1000000;i++)if(a[i]>=2)
    {
        cout<<2<<endl;
        return 0;
    }
    for(int i=1;i<=1000000;i++)if(a[i]&&prime[i])
    {
        v[pnum[prime[i]]].push_back(pnum[i/prime[i]]);
        v[pnum[i/prime[i]]].push_back(pnum[prime[i]]);
        //v[pnum[prime[i]]][pnum[i/prime[i]]]=1;
    }
    for(int i=1;i<=1000000;i++)if(a[i]&&prime[i]==0)
    {
        savemap[i]=1;
    }
    //for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)if(v[i][j])v[j][i]=1;
    //for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)if(v[i][j]==0)v[i][j]=1e9;
    //cout<<"ok"<<endl;
    for(int i=1;i<=200;i++)
    {
        nnow=i;
        //for(int j=1;j<=200;j++)v[j][i]=0;
        ans=1e9;
        for(int j=0;j<1000006;j++)vis[j]=-1;
        vis[i]=0;
        save[0]=i;nn=1;
        for(int j=0;j<nn;j++)ko(save[j]);//cout<<endl;
        ans0=min(ans,ans0);//cout<<i<<" "<<ans0<<endl;
        //for(int j=1;j<=200;j++)v[j][i]=v[i][j];
    }//cout<<ans0<<endl;
    for(int i=1;i<=200;i++)
    {
        if(savemap[nump[i]])
        {
            if(saveans[i].size()>=1)ans0=min(ans0,saveans[i][0]+2);
        }
        else
        {
            if(saveans[i].size()>=2)ans0=min(ans0,saveans[i][0]+saveans[i][1]+2);
        }
    }
    if(ans0==1e9)cout<<"-1"<<endl;
    else cout<<ans0<<endl;
    return 0;
}
/*
5
6 15 10 9934 2121

6
2 5 10 6 21 35

2
6 10
*/