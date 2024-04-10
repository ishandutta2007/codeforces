#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct node
{
	ll area,sum;
	ll lazy=-1,cover;
}seg[2400005];

struct mode
{
	ll p,t,i;
	bool operator<(const mode &a)const{
		if(p==a.p) return t>a.t;
		return p<a.p;
	}
};

vector<ll> v;
vector<pll> fixs[300005];
set<mode> s;
pll arr[300005];
ll n,hav[300005];

void up(int l,int r,int rt)
{
	int m=l+r>>1;
	seg[rt].area=seg[rt].sum=0;
	if(seg[rt<<1].cover)
		seg[rt].area+=v[m]-v[l];
	else
		seg[rt].sum+=seg[rt<<1].sum,seg[rt].area+=seg[rt<<1].area;
	if(seg[rt<<1|1].cover)
		seg[rt].area+=v[r]-v[m];
	else
		seg[rt].sum+=seg[rt<<1|1].sum,seg[rt].area+=seg[rt<<1|1].area;
}

void down(int l,int r,int rt)
{
	if(!~seg[rt].lazy) return;
	int m=l+r>>1;
	seg[rt<<1].sum=seg[rt].lazy*(v[m]-v[l]-seg[rt<<1].area);
	seg[rt<<1|1].sum=seg[rt].lazy*(v[r]-v[m]-seg[rt<<1|1].area);
	seg[rt<<1].lazy=seg[rt].lazy,seg[rt<<1|1].lazy=seg[rt].lazy;
	seg[rt].lazy=-1;
}

void build(int l,int r,int rt)
{
	seg[rt].area=0,seg[rt].cover=0,seg[rt].lazy=-1,seg[rt].sum=0;
	if(r-l<=1) return;
	int m=l+r>>1;
	build(l,m,rt<<1),build(m,r,rt<<1|1);
}

void modify(int L,int R,int l,int r,int rt,ll val)
{
	if(r-l>1) down(l,r,rt);
	if(L<=l&&R>=r)
		return seg[rt].cover+=val,void();
	int m=l+r>>1;
	if(L<m) modify(L,R,l,m,rt<<1,val);
	if(R>m) modify(L,R,m,r,rt<<1|1,val);
	up(l,r,rt);
}

void modify2(int L,int R,int l,int r,int rt,ll val)
{
	if(r-l>1) down(l,r,rt);
	if(L<=l&&R>=r)
		return seg[rt].sum=val*(v[r]-v[l]-seg[rt].area),seg[rt].lazy=val,void();
	int m=l+r>>1;
	if(L<m) modify2(L,R,l,m,rt<<1,val);
	if(R>m) modify2(L,R,m,r,rt<<1|1,val);
	up(l,r,rt);
}

void mdfy(int l,int r,ll val)
{
	modify(l,r,0,v.size()-1,1,val);
}

void mdfy2(int l,int r,ll val)
{
	modify2(l,r,0,v.size()-1,1,val);
}

ll gcover()
{
	if(seg[1].cover) return v.back()-v[0];
	return seg[1].area;
}

ll gval()
{
	if(seg[1].cover) return 0;
	return seg[1].sum;
}

pll cal(ll x)
{
	build(0,v.size()-1,1);
	pll re=MP(0,0);
	for(int i=n,r=n;i>0;--i)
	{
		mdfy(arr[i].F,arr[i].S,1);
		while(r>=i&&gcover()>=x)
			mdfy(arr[r].F,arr[r].S,-1),mdfy2(arr[r].F,arr[r].S,n-r+1),--r;
		re.F+=n-r,re.S+=gcover()*(n-r)+gval();
	}
	return re;
}

ll check(ll x)
{
	ll re=0,nw=0;
	for(int i=1;i<=n;++i)
		hav[i]=arr[i].S-arr[i].F;
	for(int i=1,j=1;i<=n;re+=n-j+1+(nw>=x),nw-=hav[i++])
		for(;j<=n&&nw<x;nw+=hav[j++])
			for(auto t:fixs[j])
				if(t.F>=i)
					nw-=t.S,hav[t.F]-=t.S;
	return re;
}

int main()
{jizz
	ll l=0,r=1000000001,k;
	cin >> n >> k;
	for(int i=1;i<=n;++i)
		cin >> arr[i].F >> arr[i].S,v.pb(arr[i].F),v.pb(arr[i].S);
	for(int i=1;i<=n;++i)
	{
		auto p=s.lower_bound(mode{arr[i].F,0,i});
		if(p==s.end()||(p->p>=arr[i].S&&p->t!=1));
		else if(p->p>arr[i].S)
			s.insert(mode{arr[i].F,1,p->i}),s.insert(mode{arr[i].S,0,p->i}),fixs[i].pb(MP(p->i,arr[i].S-arr[i].F));
		else
		{
			if(p->t==1)
				fixs[i].pb(MP(p->i,p->p-arr[i].F)),s.insert(mode{arr[i].F,1,p->i}),p=s.erase(p);
			pll ls;
			while(p!=s.end()&&(p->p<arr[i].S||(p->p==arr[i].S&&p->t==1)))
				if(p->t==0)
					ls=MP(p->p,p->i),p=s.erase(p);
				else
					fixs[i].pb(MP(p->i,p->p-ls.F)),p=s.erase(p);
			if(p!=s.end()&&p->t==1)
				fixs[i].pb(MP(ls.S,arr[i].S-ls.F)),s.insert(mode{arr[i].S,0,ls.S});
		}
		s.insert(mode{arr[i].F,0,i}),s.insert(mode{arr[i].S,1,i});
	}
	while(l<r)
	{
		ll mid=l+r>>1;
		if(check(mid)>k) l=mid+1;
		else r=mid;
	}
	sort(ALL(v)),v.resize(unique(ALL(v))-v.begin());
	for(int i=1;i<=n;++i)
		arr[i].F=lower_bound(ALL(v),arr[i].F)-v.begin(),arr[i].S=lower_bound(ALL(v),arr[i].S)-v.begin();
	auto tmp=cal(l);
	cout << tmp.S+(k-tmp.F)*(l-1) << "\n";
}