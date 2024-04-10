#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
	ll l,r,w;
};

ll ans[1000005],arr[1000005];
vector<mode> st;

void pls(ll l,ll r,ll w)
{
	if(l>r) return;
	ans[l]+=w,ans[r+1]-=w;
}

int main()
{
	IOS()
	ll n,w,k,x;
	cin >> n >> w;
	for(int i=0;i<n;++i)
	{
		cin >> k,st.clear();
		if(k<w)
			st.pb(mode{0,w-k-1,0});
		for(int j=0;j<k;++j)
		{
			cin >> x;
			ll l=j,r=w-k+j,bk;
			if(st.empty()) bk=0;
			else bk=st.back().r+1;
			while(!st.empty()&&l<=st.back().l&&st.back().w<=x)
				pls(st.back().l,st.back().r,x-st.back().w),st.pop_back();
			if(!st.empty())
				if(st.back().w<=x)
					pls(l,st.back().r,x-st.back().w),st.back().r=l-1;
				else
					l=st.back().r+1;
			pls(bk,r,x),st.pb(mode{l,r,x});
		}
		if(k<w)
		{
			ll l=k,r=w-1,x=0;
			while(!st.empty()&&l<=st.back().l&&st.back().w<=x)
				pls(st.back().l,st.back().r,x-st.back().w),st.pop_back();
			if(!st.empty())
				if(st.back().w<=x)
					pls(l,st.back().r,x-st.back().w),st.back().r=l-1;
				else
					l=st.back().r+1;
		}
	}
	cout << ans[0];
	for(int i=1;i<w;++i)
		ans[i]+=ans[i-1],cout << " " << ans[i];
	ET;
}