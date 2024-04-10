#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define F first
#define S second
#define MEM(i,j) memset(i,j,sizeof i)
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct segment_tree{
	struct mode{
		ll ans,sum,L,R;
		mode operator+(const mode &a)const{
			return mode{max({ans,a.ans,R+a.L}),sum+a.sum,max(L,sum+a.L),max(R+a.sum,a.R)};
		}
	};
	vector<mode> seg;
	ll n;
	void init(ll _n){
		seg.resize(4*(_n+1)),n=_n;
	}
	void mdfy(ll x,ll v1,ll v2,ll v3,ll l,ll r,ll rt){//v1 oth_ans, v2 fw, v3 max_hei
		if(l==r)
			return seg[rt]=mode{max(v1,v2+v3),v2,v2+v3,v3},void();
		ll m=l+r>>1;
		if(x<=m) mdfy(x,v1,v2,v3,l,m,rt<<1);
		else mdfy(x,v1,v2,v3,m+1,r,rt<<1|1);
		seg[rt]=seg[rt<<1]+seg[rt<<1|1];
	}
	void modify(ll x,ll v1,ll v2,ll v3){mdfy(x,v1,v2,v3,0,n,1);}
}link[100005];

ll wei[100005],fw[100005],pa[100005],w[100005],where[100005],oth_ans[100005];
ll mxson[100005],pl[100005],boss[100005],num[100005],ltp;
vector<pll> G[100005];
multiset<ll> hei[100005],oth[100005];

void dfs(ll u,ll f,ll e)
{
	if(~e) fw[u]=wei[e],where[e]=u;
	else fw[u]=0;
	pa[u]=f,w[u]=1,mxson[u]=-1;
	for(pll i:G[u])
		if(i.F!=f)
		{
			dfs(i.F,u,i.S),w[u]+=w[i.F];
			if(!~mxson[u]||w[mxson[u]]<w[i.F])
				mxson[u]=i.F;
		}
}

void cut(ll u,ll bs,ll p,ll n)
{
	boss[u]=bs,pl[u]=p,num[u]=n;
	oth[u].insert(0),hei[u].insert(0),hei[u].insert(0);
	if(~mxson[u])
		cut(mxson[u],bs,p+1,n);
	else
		link[num[u]].init(p);
	for(pll i:G[u])
		if(i.F!=pa[u]&&i.F!=mxson[u])
			cut(i.F,i.F,0,ltp++),oth[u].insert(link[num[i.F]].seg[1].ans),hei[u].insert(link[num[i.F]].seg[1].L);
	oth_ans[u]=max(*oth[u].rbegin(),*hei[u].rbegin()+*next(hei[u].rbegin()));
	link[num[u]].modify(pl[u],oth_ans[u],fw[u],*hei[u].rbegin());
}

void update(ll a,pll org)
{
	a=boss[a];
	while(a!=1)
	{
		ll u=pa[a];
		pll tmp=MP(link[num[boss[u]]].seg[1].ans,link[num[boss[u]]].seg[1].L);
		oth[u].erase(oth[u].find(org.F)),hei[u].erase(hei[u].find(org.S));
		oth[u].insert(link[num[a]].seg[1].ans),hei[u].insert(link[num[a]].seg[1].L);
		oth_ans[u]=max(*oth[u].rbegin(),*hei[u].rbegin()+*next(hei[u].rbegin()));
		link[num[u]].modify(pl[u],oth_ans[u],fw[u],*hei[u].rbegin());
		a=boss[u],org=tmp;
	}
}

int main()
{jizz
	ll n,q,W,ls=0,a,b;
	pll org;
	cin >> n >> q >> W;
	for(int i=0;i+1<n;++i)
		cin >> a >> b >> wei[i],G[a].pb(MP(b,i)),G[b].pb(MP(a,i));
	dfs(1,1,-1),cut(1,1,0,ltp++);
	while(q--)
	{
		cin >> a >> b,a=(a+ls)%(n-1),b=(b+ls)%W;
		a=where[a];
		org=MP(link[num[boss[a]]].seg[1].ans,link[num[boss[a]]].seg[1].L),fw[a]=b;
		link[num[a]].modify(pl[a],oth_ans[a],fw[a],*hei[a].rbegin());
		update(a,org);
		cout << (ls=link[num[1]].seg[1].ans) << "\n";
	}
}