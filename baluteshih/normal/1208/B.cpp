#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ll;
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

int arr[2005],n;
bitset<2005> vis;
vector<int> v;

bool check(int x)
{
	for(int i=0;i+x<=n;++i)
	{
		int flag=1;
		vis.reset();
		for(int j=0;j<n;++j)
			if(j<i||j>=i+x)
				if(vis[arr[j]]) flag=0;
				else vis[arr[j]]=1;
		if(flag) return 1;
	}
	return 0;
}

int main()
{
	IOS()
	int l,r;
	cin >> n,l=0,r=n;
	for(int i=0;i<n;++i)
		cin >> arr[i],v.pb(arr[i]);
	sort(ALL(v)),v.resize(unique(ALL(v))-v.begin());
	for(int i=0;i<n;++i)
		arr[i]=lower_bound(ALL(v),arr[i])-v.begin();
	while(l<r)
	{
		int m=l+r>>1;
		if(check(m)) r=m;
		else l=m+1;
	}
	cout << l << "\n";
}