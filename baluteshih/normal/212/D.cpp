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

ll ans[2000005],ans1[2000005],ans2[2000005],L[1000005],R[1000005],arr[1000005];
vector<ll> st;
 
int main()
{
	IOS()
	ll n,q,k;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> arr[i];
	for(int i=1;i<=n;++i)
	{
		while(!st.empty()&&arr[i]<=arr[st.back()])
			st.pop_back();
		if(st.empty()) L[i]=0;
		else L[i]=st.back();
		st.pb(i);
	}
	st.clear();
	for(int i=n;i>0;--i)
	{
		while(!st.empty()&&arr[i]<arr[st.back()])
			st.pop_back();
		if(st.empty()) R[i]=n+1;
		else R[i]=st.back();
		st.pb(i);
	}
	for(int i=1;i<=n;++i)
	{
		ll l=min(i-L[i],R[i]-i),r=max(i-L[i],R[i]-i);
		ans[l]+=l*arr[i],ans[r+1]-=l*arr[i];
		ans1[1]+=arr[i],ans1[l]-=l*arr[i],ans1[l+1]+=(l-1)*arr[i];
		ans2[r+l-1]+=arr[i],ans2[r]-=l*arr[i],ans2[r-1]+=(l-1)*arr[i];
	}
	for(int i=1;i<=n;++i)
		ans[i]+=ans[i-1],ans1[i]+=ans1[i-1];
	for(int i=1;i<=n;++i)
		ans1[i]+=ans1[i-1];
	for(int i=n;i>=1;--i)
		ans2[i]+=ans2[i+1];
	for(int i=n;i>=1;--i)
		ans2[i]+=ans2[i+1];
	cin >> q;
	while(q--)
	{
		cin >> k;
		cout << fixed << setprecision(15) << (double)(ans[k]+ans1[k]+ans2[k])/(double)(n-k+1) << "\n";
	}
}