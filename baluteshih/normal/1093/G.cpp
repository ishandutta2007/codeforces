#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define pb push_back
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define MEM(i,j) memset(i,j,sizeof i)
#define ALL(v) v.begin(),v.end()
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MAXN=200005;
ll k,L;
struct node
{
	ll dt[33];
	node operator+(const node&a)const{
		node re;
		re.dt[32]=0;
		for(int i=0;i<L;++i)
		{
			re.dt[i]=max(dt[i],a.dt[i]);
			re.dt[32]=max({dt[i]+a.dt[i^(L-1)],re.dt[32],dt[32],a.dt[32]});
		}
		return re;
	}
}seg[MAXN*4];

void build(ll l,ll r,ll rt)
{
	if(l==r)
	{
		ll arr[5];
		seg[rt].dt[32]=0;
		for(int i=0;i<k;++i)
			cin >> arr[i];
		for(int i=0;i<L;++i)
			for(int j=0,x=1;j<k;++j,x<<=1)
				if(i&x) seg[rt].dt[i]+=arr[j];
				else seg[rt].dt[i]+=arr[j]*-1;
		//cout << l << " " << r << " : " << seg[rt].dt[32] << "\n";
		//for(int i=0;i<L;++i)
		//	cout << seg[rt].dt[i] << " ";
		//ET;
		return;
	}
	ll m=l+r>>1;
	seg[rt].dt[32]=0;
	build(l,m,rt<<1),build(m+1,r,rt<<1|1);
	seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

node query(ll L,ll R,ll l,ll r,ll rt)
{
	if(L<=l && R>=r) return seg[rt];
	ll m=l+r>>1;
	if(L>m) return query(L,R,m+1,r,rt<<1|1);
	if(R<=m) return query(L,R,l,m,rt<<1);
	return query(L,R,l,m,rt<<1)+query(L,R,m+1,r,rt<<1|1);
}

void modify(ll x,ll l,ll r,ll rt)
{
	if(l==r)
	{
		ll arr[5];
		seg[rt].dt[32]=0;
		for(int i=0;i<k;++i)
			cin >> arr[i];
		for(int i=0;i<L;++i)
		{
			seg[rt].dt[i]=0;
			for(int j=0,x=1;j<k;++j,x<<=1)
				if(i&x) seg[rt].dt[i]+=arr[j];
				else seg[rt].dt[i]+=arr[j]*-1;
		}
		return;
	}
	ll m=l+r>>1;
	if(x<=m) modify(x,l,m,rt<<1);
	else modify(x,m+1,r,rt<<1|1);
	seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

int main()
{jizz
	ll n,t,l,r,q;
	cin >> n >> k,L=1<<k;
	build(1,n,1);
	cin >> q;
	while(q--)
	{
		cin >> t;
		if(t==2)
			cin >> l >> r,cout << query(l,r,1,n,1).dt[32] << "\n";
		else
			cin >> r,modify(r,1,n,1);
	}
}