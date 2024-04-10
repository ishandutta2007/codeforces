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
#define DB(a,s,e) {for(int _i=s;_i<e;++_i) cerr << a[_i] << " ";cerr << "\n";}
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#define DB(a,s,e) 
#endif

int main()
{
	IOS()
	int t,a,b,n,tmp;
	const int C=10;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> n;
		for(int i=0;n&&i<C;++i,--n)
			tmp=a,a=b,b=tmp^a;
		if(!n)
			cout << a << "\n";
		else
		{
			n%=3;
			for(int i=0;n;--n)
				tmp=a,a=b,b=tmp^a;
			cout << a << "\n";
		}
	}
}