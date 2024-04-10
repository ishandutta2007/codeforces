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

vector<int> modifyr[100005],modifyl[100005];
int seg[400005],lazy[400005],arr[100005];
pii inter[305];
vector<int> anss;

void build(int l,int r,int rt)
{
	if(l==r)
		return seg[rt]=arr[l],lazy[rt]=0,void();
	int m=l+r>>1;
	build(l,m,rt<<1),build(m+1,r,rt<<1|1);
	seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
	lazy[rt]=0;
}

void push(int rt)
{
	lazy[rt<<1]+=lazy[rt],lazy[rt<<1|1]+=lazy[rt];
	seg[rt<<1]-=lazy[rt],seg[rt<<1|1]-=lazy[rt];
	lazy[rt]=0;
}

void modify(int L,int R,int l,int r,int rt)
{
	if(l!=r&&lazy[rt]) push(rt);
	if(L<=l&&R>=r)
		return --seg[rt],++lazy[rt],void();
	int m=l+r>>1;
	if(L<=m) modify(L,R,l,m,rt<<1);
	if(R>m) modify(L,R,m+1,r,rt<<1|1);
	seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}

int main()
{jizz
	int n,m,ans=0,l,r;
	pii out=MP(0,0);
	cin >> n >> m;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=1;i<=m;++i)
		cin >> l >> r,modifyr[r].pb(l),modifyl[l].pb(r),inter[i]=MP(l,r);
	build(1,n,1);
	for(int i=1;i<=n;++i)
	{
		if(arr[i]-seg[1]>=ans) ans=arr[i]-seg[1],out=MP(0,i);
		for(auto j:modifyr[i])
			modify(j,i,1,n,1); 
	}
	build(1,n,1);
	for(int i=n;i>=1;--i)
	{
		if(arr[i]-seg[1]>=ans) ans=arr[i]-seg[1],out=MP(1,i);
		for(auto j:modifyl[i])
			modify(i,j,1,n,1); 
	}
	for(int i=1;i<=m;++i)
		if(out.F==0&&inter[i].S<out.S) anss.pb(i);
		else if(out.F==1&&inter[i].F>out.S) anss.pb(i);
	cout << ans << "\n" << anss.size() << "\n";
	for(auto i:anss)
		cout << i << " ";
	ET;
}