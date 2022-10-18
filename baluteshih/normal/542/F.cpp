#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#endif

struct mode
{
	ll t,v;
	bool operator<(const mode &a)const{
		if(t==a.t) return v<a.v;
		return t>a.t; 
	}
};

priority_queue<mode> pq;

int main()
{
	IOS()
	ll n,t,a,b,ans=0;
	cin >> n >> t;
	while(n--)
		cin >> a >> b,pq.push(mode{a,b});
	while(pq.size()>1)
	{
		mode tmp=pq.top();
		pq.pop();
		if(tmp.t<=t)
			ans=max(ans,tmp.v);
		if(tmp.t!=pq.top().t)
		{
			tmp.t=pq.top().t,pq.push(tmp);
			continue;
		}
		mode tmp2=pq.top();
		pq.pop(),tmp.v+=tmp2.v,++tmp.t;
		pq.push(tmp);
	}
	if(pq.size()&&pq.top().t<=t)
		ans=max(ans,pq.top().v);
	cout << ans << "\n";
}