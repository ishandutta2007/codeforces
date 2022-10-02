#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long ll;
template<unsigned N,unsigned M> struct Maxflow
{
    int const inf=1e14;
    int maxflow,s,t,tot=1,target[M],pre[M],last[N],
    cap[M],deep[N],cur[N];
    queue<int>q;
    void add(int x,int y,int z)
    {
        target[++tot]=y;
        pre[tot]=last[x];
        last[x]=tot;
        cap[tot]=z;
        target[++tot]=x;
        pre[tot]=last[y];
        last[y]=tot;
        cap[tot]=0;
    }
    bool bfs()
    {
        for(int i=s;i<=t;i++)deep[i]=0,cur[i]=last[i];
        q.push(s);
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int i=last[now];i;i=pre[i])
            {
                int tar=target[i];
                if(tar!=s&&cap[i]&&(!deep[tar]))
                    deep[tar]=deep[now]+1,q.push(tar);
            }
        }
        return deep[t];
    }
    int dfs(int x,int lim)
    {
        if((!lim)||x==t)return lim;
        int flow=0;
        for(int &i=cur[x];i;i=pre[i])
        {
            int tar=target[i];
            if(cap[i]&&deep[tar]==deep[x]+1)
            {
                int d=dfs(tar,min(lim,cap[i]));
                cap[i]-=d;
                cap[i^1]+=d;
                lim-=d;
                flow+=d;
                if(!lim)break;
            }
        }
        return flow;
    }
    void dinic(){while(bfs())maxflow+=dfs(s,inf);}
    void init(int n)
    {
        for(int i=0;i<n+5;i++)last[i]=0;
        tot=1;maxflow=0;
    }
};
struct BASE
{
    ll b[65],id[65];
    void insert(ll x,ll &y)
    {
        for(int i=63;i>=0;i--)
            if(x&(1ull<<i))
            {
                if(!b[i]){b[i]=x;id[i]=y;return;}
                x^=b[i],y^=id[i];
            }
    }
}B1,B2;
typedef vector<int> vec;
Maxflow<1005,1100005>g;
ll c[1005];
int n,m,a[65],b[65],delta[1005],w[1005],id[1005],res,ANS[1005];
bool vis1[1005],vis2[1005],lk[1005][1005];
inline int W(int x,int y)
{
	return max(x,y)-min(x,y);
}
void solve(vec v,int l,int r)
{
    if(!v.size())return;
    if(r==l+1)
    {
        int cnt=0;
        g.init(v.size());
        g.t=v.size()+1;
        for(auto i:v)
        {
            id[i]=++cnt;
            delta[i]=(w[i]-r)-(w[i]-l);
            if(delta[i]<0)g.add(0,cnt,-delta[i]);
            else g.add(cnt,g.t,delta[i]);
        }
        for(auto i:v)
            for(auto j:v)
                if(lk[i][j])g.add(id[j],id[i],1e9);
        g.dinic();
        for(auto i:v)
		{
			if(g.deep[id[i]]) ANS[i]=r;
			else ANS[i]=l;
			res+=g.deep[id[i]]?((w[i]-r)):((w[i]-l));
		}
        return;
    }
    int mid=(l+r)>>1,cnt=0;
    g.init(v.size());
    g.t=v.size()+1;
    for(auto i:v)
    {
        id[i]=++cnt;
        delta[i]=W(mid+1,w[i])-W(mid,w[i]);//2*(mid-w[i]);
        if(delta[i]<0)g.add(0,cnt,-delta[i]);
        else g.add(cnt,g.t,delta[i]);
    }
    for(auto i:v)
        for(auto j:v)
            if(lk[i][j])g.add(id[j],id[i],1e9);
    g.dinic();
    vec vl,vr;
    for(auto i:v)(g.deep[id[i]]?vr:vl).push_back(i);
    solve(vl,l,mid),solve(vr,mid,r);
}
/*void solve(vec v,int l,int r)
{
    if(!v.size())return;
    if(r==l+1)
    {
        int cnt=0;
        g.init(v.size());
        g.t=v.size()+1;
        for(auto i:v)
        {
            id[i]=++cnt;
            delta[i]=(w[i]-r)*(w[i]-r)-(w[i]-l)*(w[i]-l);
            if(delta[i]<0)g.add(0,cnt,-delta[i]);
            else g.add(cnt,g.t,delta[i]);
        }
        for(auto i:v)
            for(auto j:v)
                if(lk[i][j])g.add(id[j],id[i],1e9);
        g.dinic();
        for(auto i:v)
		{
			if(g.deep[id[i]]) ANS[i]=r;
			else ANS[i]=l;
			res+=g.deep[id[i]]?((w[i]-r)*(w[i]-r)):((w[i]-l)*(w[i]-l));
		}
        return;
    }
    int mid=(l+r)>>1,cnt=0;
    g.init(v.size());
    g.t=v.size()+1;
    for(auto i:v)
    {
        id[i]=++cnt;
        delta[i]=2*(mid-w[i]);
        if(delta[i]<0)g.add(0,cnt,-delta[i]);
        else g.add(cnt,g.t,delta[i]);
    }
    for(auto i:v)
        for(auto j:v)
            if(lk[i][j])g.add(id[j],id[i],1e9);
    g.dinic();
    vec vl,vr;
    for(auto i:v)(g.deep[id[i]]?vr:vl).push_back(i);
    solve(vl,l,mid),solve(vr,mid,r);
}*/
signed main()
{
    scanf("%lld%lld",&n,&m);
   // for(int i=1;i<=n;i++)scanf("%llu",&c[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
   // ll tmp;
 //   for(int i=0;i<m;i++)scanf("%lld",&a[i]),vis1[a[i]]=1,B1.insert(c[a[i]],tmp=1ull<<i);
   // for(int i=0;i<m;i++)scanf("%lld",&b[i]),vis2[b[i]]=1,B2.insert(c[b[i]],tmp=1ull<<i);
  /*  for(int i=1;i<=n;i++)
        if(!vis1[i])
        {
            ll id=0;
            B1.insert(c[i],id);
            for(int j=0;j<m;j++)if(id&(1ull<<j))lk[i][a[j]]=1;//if i should be greater than a[j]
        }*/
    for(int i=1;i<=m;i++)
    {
    	int x,y;
    	cin >> x >> y;
    	lk[y][x]=1;
	}
/*    for(int i=1;i<=n;i++)
        if(!vis2[i])
        {
            ll id=0;
            B2.insert(c[i],id);
            for(int j=0;j<m;j++)if(id&(1ull<<j))lk[b[j]][i]=1;
        }*/
    vec v;
    for(int i=1;i<=n;i++) v.push_back(i);
    solve(v,0,1e9);
   // cout<<res;
   for(int i=1;i<=n;i++) cout << ANS[i]<< " ";
    return 0;
}