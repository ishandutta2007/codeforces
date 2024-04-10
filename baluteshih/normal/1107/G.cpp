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

struct mode
{
	ll d,x,v;
};

stack<mode> st;
ll d[300005],c[300005],seg[1200005];
const ll INF=1e18;

void build(int l,int r,int rt)
{
	if(l==r)
		return seg[rt]=INF,void();
	int m=l+r>>1;
	build(l,m,rt<<1),build(m+1,r,rt<<1|1);
	seg[rt]=INF;
}

void modify(int x,int l,int r,int rt,ll v)
{
	if(l==r)
		return seg[rt]=min(seg[rt],v),void();
	int m=l+r>>1;
	if(x<=m) modify(x,l,m,rt<<1,v);
	if(x>m) modify(x,m+1,r,rt<<1|1,v);
	seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}

ll query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&R>=r) return seg[rt];
	int m=l+r>>1;
	if(R<=m) return query(L,R,l,m,rt<<1);
	if(L>m) return query(L,R,m+1,r,rt<<1|1);
	return min(query(L,R,l,m,rt<<1),query(L,R,m+1,r,rt<<1|1));
}

multiset<ll> s;

int main()
{jizz
	ll n,a,ans=0,tmp,t;
	cin >> n >> a;
	build(0,n,1),modify(0,0,n,1,0);
	cin >> d[1] >> c[1];
	c[1]=a-c[1],ans=max(ans,c[1]);
	modify(1,0,n,1,c[1]);
	for(int i=2;i<=n;++i)
	{
		cin >> d[i] >> c[i];
		c[i]=a-c[i],ans=max(ans,c[i]),c[i]+=c[i-1];
		modify(i,0,n,1,c[i]);
		tmp=(d[i]-d[i-1])*(d[i]-d[i-1]);
		while(!st.empty()&&tmp>=st.top().d) 
			s.erase(s.find(st.top().v)),st.pop();
		if(st.empty())
			t=tmp+query(0,i-1,0,n,1);
		else
			t=tmp+query(st.top().x-1,i-1,0,n,1);
		s.insert(t),st.push(mode{tmp,i,t});
		if(!s.empty()) ans=max(ans,c[i]-*s.begin());
	}
	cout << ans << "\n";
}