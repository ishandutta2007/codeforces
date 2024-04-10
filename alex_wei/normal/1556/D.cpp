/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)

//using int = long long
//using i128 = __int128;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;
using vint = vector <int>;
using vpii = vector <pii>;

#define fi first
#define se second
#define pb emplace_back
#define mpi make_pair
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(y))
#define Time 1.0*clock()/CLOCKS_PER_SEC

pii operator + (pii a,pii b){return {a.fi+b.fi,a.se+b.se};}
pll operator + (pll a,pll b){return {a.fi+b.fi,a.se+b.se};}

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<24],*O=obuf;
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
	}
	inline void print(ll x){
		if(x<0)pc('-'),print(-x);
		else{
			if(x>9)print(x/10);
			pc(x%10+'0');
		}
	}
}

const int mod=998244353;
const long double Pi=acos(-1);

namespace math{
	const int MAXN=2e6+5;

	ll ksm(ll a,ll b,ll p){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%p;
			m=m*m%p,b>>=1;
		} return s;
	}
	ll ksm(ll a,ll b){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[MAXN],ifc[MAXN];
	void init(int n){
		assert(n<MAXN);
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

using namespace IO;
//using namespace math;

const int N=1e4+5;

ll n,k;
struct index{
	ll res,id;
	bool operator < (const index &v) const {
		return res<v.res;
	}
}c[N];
ll OR(int x,int y){
	ll res=0;
	cout<<"or "<<x<<" "<<y<<endl;
	cin>>res; return res;
}
ll AND(int x,int y){
	ll res=0;
	cout<<"and "<<x<<" "<<y<<endl;
	cin>>res; return res;
}
void solve(){
	cin>>n>>k;
	for(int i=2;i<=n;i++)c[i].id=i,c[i].res=AND(1,i)+OR(1,i);
	sort(c+2,c+n+1);
	if(k==1){
		ll res=OR(c[2].id,c[3].id)+AND(c[2].id,c[3].id);
		ll sum=(res+c[2].res+c[3].res)/2;
		if(c[3].res<=res)cout<<"finish "<<sum-res<<endl;
		else cout<<"finish "<<sum-c[3].res<<endl;
	}
	else if(k<n){
		ll res=OR(c[k].id,c[k+1].id)+AND(c[k].id,c[k+1].id);
		ll sum=(res+c[k].res+c[k+1].res)/2;
		if(c[k+1].res<=res)cout<<"finish "<<sum-c[k+1].res<<endl;
		else if(c[k].res<=res)cout<<"finish "<<sum-res<<endl;
		else cout<<"finish "<<sum-c[k].res<<endl;
	}
	else{
		ll res=OR(c[k-1].id,c[k].id)+AND(c[k-1].id,c[k].id);
		ll sum=(res+c[k].res+c[k-1].res)/2;
		if(c[k-1].res>=res)cout<<"finish "<<sum-res<<endl;
		else cout<<"finish "<<sum-c[k-1].res<<endl;
	}
}

int main(){
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}