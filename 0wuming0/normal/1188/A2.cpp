#include"bits/stdc++.h"
using namespace std;
int sum[1005];
vector<int>v[1005];
int m[1005][1005];
int now;
int vis[1005];
int ns,save[1005];
int flag;
int t1,t2;
int ans[100005][3],nn;
int solve2(int i)
{
    if(v[i].size()==1)return i;
    vis[i]=1;
    for(auto tt:v[i])if(vis[tt]==0)
    {
        m[i][tt]-=now;
        m[tt][i]-=now;
        int c=solve2(tt);
        vis[i]=0;
        return c;
    }
}
void solve3(int i,int j,int k)
{//cout<<j<<" "<<k<<" "<<save[j]<<" "<<save[k]<<endl;
    m[i][save[k]]-=now;
    m[save[k]][i]-=now;
    m[i][save[j]]-=now;
    m[save[j]][i]-=now;//for(int i=1;i<=6;i++)printf("%d%c",vis[i]," \n"[i==6]);
    int k1=solve2(save[k]);
    int k2=solve2(save[j]);
    if(flag)
    {
        t1=k1;
        t2=k2;
    }
    ans[nn][0]=k1;
    ans[nn][1]=k2;
    ans[nn++][2]=now;
}
void solve4(int i,int j,int ss)
{//cout<<j<<" "<<k<<" "<<save[j]<<" "<<save[k]<<endl;
    m[i][save[j]]-=now;
    m[save[j]][i]-=now;//for(int i=1;i<=6;i++)printf("%d%c",vis[i]," \n"[i==6]);
    int k2=solve2(save[j]);
    ans[nn][0]=ss;
    ans[nn][1]=k2;
    ans[nn++][2]=now;
}
void solve(int i,int ss)
{//cout<<"<<<<"<<i<<endl;
    flag=0;
    vis[i]=1;
    if(v[i].size()==1)return;
    ns=0;
    for(auto tt:v[i])if(vis[tt]==0)
    {
        save[ns++]=tt;
    }//cout<<"<<<"<<i<<" "<<ns<<endl;
    for(int j=1;j<ns;j++)
    {
        if(j==1)flag=1;
        now=m[i][save[j]];//cout<<"<<<"<<i<<" "<<j<<" "<<now<<endl;
        solve3(i,j,0);
        if(j==1)flag=0;
    }
    int b=m[i][save[0]]/2;//cout<<"<<<"<<b<<endl;
    if(ns>=3)
    {
        now=b;
        solve3(i,0,1);
        solve3(i,0,2);
        now=-b;
        solve3(i,1,2);
    }
    else
    {
        now=b;
        solve3(i,0,1);
        solve4(i,0,ss);
        now=-b;
        solve4(i,1,ss);
    }
    int t11=t1,t22=t2;
    int nnk=0;
    for(auto tt:v[i])if(vis[tt]==0)
    {
        if(nnk==0)solve(tt,t22);
        else solve(tt,t11);
        nnk++;
    }
    //solve2()
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        sum[a]++;
        sum[b]++;
        m[a][b]=m[b][a]=c;
        v[a].push_back(b);
        v[b].push_back(a);
    }//cout<<v[1][0].first<<endl;
    for(int i=1;i<=n;i++)
    {
        if(sum[i]==2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    if(n==2)
    {
        cout<<1<<endl;
        printf("%d %d %d\n",1,2,m[1][2]);
        return 0;
    }
    for(int i=1;i<=n;i++)if(sum[i]!=1)
    {
        solve(i,0);
        break;
    }
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)
    {
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}
/*
2
1 2 200

8
1 2 6
1 3 8
1 4 12
2 5 2
2 6 4
3 7 1000
3 8 1002
*/