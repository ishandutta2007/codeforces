#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=998244353;
map<pair<int,int>,int>mp;
int a,b;
int l[1000005][2];
int cl;
int wl;
int r[1000005][2];
int cr;
int wr;
void del(int x,int y)
{
    auto it=mp.find(make_pair(x,y));
    if(it==mp.end())return;
    int op=it->second;
    if(((x^y)&1)^op)a--;
    else b--;
    l[x][((y&1)^op)]--;
    if(l[x][((y&1)^op)]==0)
    {
        if(l[x][((y&1)^op)^1]==0)cl--;
        else wl--;
    }
    r[y][((x&1)^op)]--;
    if(r[y][((x&1)^op)]==0)
    {
        if(r[y][((x&1)^op)^1]==0)cr--;
        else wr--;
    }
    mp.erase(it);
}
void ins(int x,int y,int op)
{
    del(x,y);
    mp[make_pair(x,y)]=op;
    if(((x^y)&1)^op)a++;
    else b++;
    l[x][((y&1)^op)]++;
    if(l[x][((y&1)^op)]==1)
    {
        if(l[x][((y&1)^op)^1]==0)cl++;
        else wl++;
    }
    r[y][((x&1)^op)]++;
    if(r[y][((x&1)^op)]==1)
    {
        if(r[y][((x&1)^op)^1]==0)cr++;
        else wr++;
    }
}
ll _2[2000006];
int n,m,k;
ll cal()
{
    ll ans=0;
    if(a==0)ans+=mod-1;
    if(b==0)ans+=mod-1;//cout<<"<<"<<ans<<endl;
    if(wl==0)
    {
        ans+=_2[n-cl];//cout<<"<<"<<ans<<endl;
    }
    if(wr==0)
    {
        ans+=_2[m-cr];//cout<<"<<"<<ans<<endl;
    }
    return ans%mod;
}
int main()
{
    _2[0]=1;
    for(int i=1;i<2000006;i++)_2[i]=_2[i-1]*2%mod;
    cin>>n>>m>>k;
    while(k--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c==-1)
        {
            del(a,b);
        }
        else
        {
            ins(a,b,c);
        }
        printf("%lld\n",cal());
    }
    return 0;
}