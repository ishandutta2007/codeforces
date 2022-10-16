/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

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

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x){
		if(x<0)return pc('-'),print(-x),void();
		if(x>9)print(x/10);
		pc(x%10+'0');
	}
}

namespace math{
	const int mod=99824353;
	const int maxn=2e6+5;

	ll ksm(ll a,ll b,ll p){
		ll s=1,m=a%p;
		while(b){
			if(b&1)s=s*m%p;
			m=m*m%p,b>>=1;
		} return s;
	} ll ksm(ll a,ll b){
		ll s=1,m=a%mod;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

using namespace IO;
//using namespace math;

const int N=2e5+5;
const int inf=0x3f3f3f3f;

int n,p[N],ans;
vector <pii> seq;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<n;){
		if(p[i]<p[i+1]){
			int r=i+1;
			while(r+1<=n&&p[r]<p[r+1])r++;
			seq.pb((pii){i,r}),i=r;
		}
		else{
			int r=i+1;
			while(r+1<=n&&p[r]>p[r+1])r++;
			seq.pb((pii){i,r}),i=r;
		}
	} int ans=0,cnt=0;
	for(pii it:seq)ans=max(ans,it.se-it.fi+1);
	for(pii it:seq)cnt+=it.se-it.fi+1==ans;
	if(cnt>=3||cnt==1)puts("0"),exit(0);
	if(cnt==2){
		pii a={0,0};
		for(pii it:seq)if(it.se-it.fi+1==ans){
			if(a.fi){
				if(a.se!=it.fi||p[a.se]<p[a.fi])puts("0"),exit(0);
				cout<<(ans&1)<<endl,exit(0);
			} else a=it;
		}
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();

	return 0;
}
/*
5
3 2 1 4 5
*/