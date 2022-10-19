#pragma GCC optimize("O3")
#include"bits/stdc++.h"
using namespace std;
const int len=320;
int room[100005];
int ml[325],mr[325];
int mn[325],mx[325];
int bg[325][100005];
int ed[325][100005];
int num[325][100005];
int nxt[100005];
int vis[100005];
int pos[100005];
int a[100005];
void mg(int &a,int b,int &c,int d)
{
    if(num[c][d]==0)return;
    else pos[bg[c][d]]=b;
    if(num[a][b]==0)
    {
        swap(num[a][b],num[c][d]);
        swap(bg[a][b],bg[c][d]);
        swap(ed[a][b],ed[c][d]);
        return;
    }
    nxt[ed[a][b]]=bg[c][d];
    ed[a][b]=ed[c][d];
    num[a][b]+=num[c][d];
    bg[c][d]=ed[c][d]=num[c][d]=0;
}
void add(int &i,int &j,int &k)
{
    num[i][j]++;
    if(bg[i][j]==0)
    {
        bg[i][j]=ed[i][j]=k;
    }
    else
    {
        nxt[ed[i][j]]=k;
        ed[i][j]=k;
    }
}
void clr(int &i,int &j)
{
    for(int k=bg[i][j],temp;k;)
    {
        temp=nxt[k];
        nxt[k]=0;
        k=temp;
    }
    num[i][j]=bg[i][j]=ed[i][j]=0;
}
void solve1(int l,int r,int x)
{
    int p=room[l];
    for(int i=ml[p],j;i<=mr[p];i++)
    {
        j=pos[i];
        if(vis[j]==0)
        {
            vis[j]=1;
            for(int k=bg[p][j];k;k=nxt[k])
            {
                a[k]=j-mn[p];
                if(l<=k&&k<=r&&a[k]>x)a[k]-=x;
            }
            clr(p,j);
        }
    }
    for(int i=ml[p],j;i<=mr[p];i++)vis[pos[i]]=0;
    mn[p]=mx[p]=0;
    for(int i=ml[p];i<=mr[p];i++)
    {
        pos[i]=a[i];
        add(p,a[i],i);
        mx[p]=max(mx[p],a[i]);
    }
}
void op1(int l,int r,int x)
{
    if(room[l]==room[r])
    {
        solve1(l,r,x);
        return;
    }
    int a=room[l],b=room[r];
    solve1(l,mr[a],x);
    solve1(ml[b],r,x);
    a++;b--;
    for(int i=a;i<=b;i++)
    {
        int m=(mx[i]-mn[i])/2;
        if(x>m)
        {
            while(mx[i]-mn[i]>x)
            {
                mg(i,mx[i]-x,i,mx[i]);
                mx[i]--;
            }
        }
        else
        {
            for(int j=1;j<=x;j++)
            {
                mg(i,mn[i]+j+x,i,mn[i]+j);
            }
            mn[i]+=x;
        }
    }
}
int solve2(int l,int r,int x)
{
    int p=room[l],ans=0;
    if(mn[p]+x<100005)for(int j=bg[p][mn[p]+x];j;j=nxt[j])
    {
        if(l<=j&&j<=r)ans++;
    }
    return ans;
}
int op2(int l,int r,int x)
{
    int ans=0;
    if(room[l]==room[r])
    {
        return solve2(l,r,x);
    }
    int a=room[l],b=room[r];
    ans+=solve2(l,mr[a],x);
    ans+=solve2(ml[b],r,x);
    a++;b--;
    for(int i=a;i<=b;i++)
    {
        if(mn[i]+x<100005)
        {
            ans+=num[i][mn[i]+x];
        }
    }
    return ans;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        room[i]=(i-1)/len+1;
        mr[room[i]]=i;
        if(ml[room[i]]==0)ml[room[i]]=i;
        scanf("%d",a+i);
        pos[i]=a[i];
        add(room[i],a[i],i);
        mx[room[i]]=max(mx[room[i]],a[i]);
    }
    while(q--)
    {
        int op,l,r,x;
        scanf("%d%d%d%d",&op,&l,&r,&x);
        if(op==1)op1(l,r,x);
        else printf("%d\n",op2(l,r,x));
    }
    return 0;
}