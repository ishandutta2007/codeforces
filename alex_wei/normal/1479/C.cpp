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
using db = double;
using ld = long double;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;

pii operator + (pii a,pii b){return {a.fi+b.fi,a.se+b.se};}
pll operator + (pll a,pll b){return {a.fi+b.fi,a.se+b.se};}

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
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
	} ll ksm(ll a,ll b){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}
	ll fc[MAXN],ifc[MAXN];
	void init(int lim){
		assert(lim<MAXN);
		fc[0]=1; for(int i=1;i<=lim;i++)fc[i]=fc[i-1]*i%mod;
		ifc[lim]=inv(fc[lim]);
		for(int i=lim-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// Please give me more points.

using namespace IO;
using namespace math;
int l,r,edg;
vector <pii> e[50];
void add(int a,int b,int c){
	e[a].pb((pii){b,c});
	edg++;
}
int main(){
	cout<<"YES\n";
//	ios::sync_with_stdio(false),cin.tie(0);
	cin>>l>>r;
	int d=r-l+1;
	if(d==1){
		cout<<"2 1\n";
		cout<<"1 2 "<<l<<endl;
		exit(0);
	} int b=0;
	while((1<<b+1)<d)b++;
	int s=(1<<b)+1,res=d-(1<<b)-1;
	for(int i=2;i<=b+3;i++)
		for(int j=i+1;j<=b+3;j++)
			add(i,j,(j==b+3?1:(1<<b+2-j)));
	add(1,2,1),add(1,b+3,1);
	int n=b+3;
	if(l-1)n=b+4,add(b+3,b+4,l-1);
	for(int i=0;i<20;i++)
		if((res>>i)&1)
			add(1,b+2-i,s),s+=1<<i;
	cout<<n<<" "<<edg<<endl;
	for(int i=1;i<=32;i++)
		for(pii it:e[i])
			cout<<i<<" "<<it.fi<<" "<<it.se<<endl;
	return 0;
}