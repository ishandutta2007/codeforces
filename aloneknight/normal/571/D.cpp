#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
#define db long double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline ll rd()
{
	ll x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=500005;
int n,m,a[N],b[N];char o[N];ll bit[N],ans[N];
map<int,int>S;vector<pii>q[N];
struct Tree
{
	int tt,dl[N],dr[N],fa[N];vi e[N];
	inline void add(int u,int v){e[u].pb(v);fa[v]=u;}
	void dfs(int x){dl[x]=dr[x]=++tt;for(int y:e[x])dfs(y);}
	inline void init(){rep(i,1,n)if(!fa[i])dfs(i);}
}U,M;
inline void upd(int x,int v){for(;x<=n;x+=x&-x)bit[x]+=v;}
inline ll qry(int x){ll s=0;for(;x;x-=x&-x)s+=bit[x];return s;}
int main()
{
	n=rd();m=rd();
	rep(i,1,m)
	{
		while(!isalpha(o[i]=gc()));a[i]=rd();
		if(o[i]=='U')b[i]=rd(),U.add(a[i],b[i]);
		if(o[i]=='M')b[i]=rd(),M.add(a[i],b[i]);
	}
	U.init();M.init();S[n]=0;
	rep(i,1,m)if(o[i]!='U'&&o[i]!='A')
	{
		if(o[i]=='M'){M.dr[a[i]]=M.dr[b[i]];continue;}
		map<int,int>::iterator it=S.lower_bound(M.dl[a[i]]); 
		if(o[i]=='Z')
		{
			map<int,int>::iterator it2=it;int p=M.dl[a[i]]-1;
			if(it==S.begin()||(--it2)->X<p)S[p]=it->Y;
			while(it!=S.end()&&it->X<=M.dr[a[i]])S.erase(it++);
			S[M.dr[a[i]]]=i;
		}
		if(o[i]=='Q'){int p=U.dl[a[i]];q[i].pb(mp(p,i));q[it->Y].pb(mp(p,-i));}
	}
	rep(i,1,m)
	{
		if(o[i]=='U')U.dr[a[i]]=U.dr[b[i]];
		if(o[i]=='A'){int l=U.dl[a[i]],r=U.dr[a[i]],w=r-l+1;upd(l,w);upd(r+1,-w);}
		for(pii t:q[i])ans[abs(t.Y)]+=(t.Y>0?1:-1)*qry(t.X);
	}
	rep(i,1,m)if(o[i]=='Q')printf("%lld\n",ans[i]);return 0;
}