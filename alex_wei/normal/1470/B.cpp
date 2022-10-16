/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)

//using int = long long
//using i128 = __int128;

#define fi first
#define se second
#define pb emplace_back
#define all(x) (x).begin(),(x).end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define Time 1.0*clock()/CLOCKS_PER_SEC

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;

namespace IO{
	char buf[1<<25],*p1=buf,*p2=buf,obuf[1<<25],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)
	inline ll read(){
		ll x=0; bool sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	} inline void print(ll x){if(x>9)print(x/10); pc(x%10+'0');}
	inline void print(string s){for(int it:s)pc(it); pc('\n');};
}

const int mod=998244353;
const long double Pi=acos(-1);

namespace math{
	const int MAXN=1e6+5;
	ll ksm(ll a,ll b){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}
	ll fc[MAXN],ifc[MAXN];
	void init(){
		fc[0]=1; for(int i=1;i<MAXN;i++)fc[i]=fc[i-1]*i%mod;
		ifc[MAXN-1]=inv(fc[MAXN-1]);
		for(int i=MAXN-2;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// Please give me more points.

using namespace IO;
//using namespace math;

const int N=3e5+5;

bool f(int &x,int v){
	bool b=0;
	while(x%v==0)x/=v,b^=1;
	return b;
}
void solve(){
	map <vector <int>,int> mp;
	int n,a=0,b=0,q; cin>>n;
	for(int i=1;i<=n;i++){
		int v; cin>>v;
		vector <int> c;
		if(f(v,2))c.pb(2);
		for(int i=3;i*i<=v;i+=2)if(f(v,i))c.pb(i);
		if(v>1)c.pb(v); mp[c]++;
	} for(auto it:mp){
		a=max(a,it.se);
		if((it.se&1)==0||it.fi.size()==0)b+=it.se;
	} cin>>q; while(q--){
		ll v; cin>>v;
		cout<<(v==0?a:max(a,b))<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int t=1;
	cin>>t;
	while(t--)solve();
	return flush(),0;
}