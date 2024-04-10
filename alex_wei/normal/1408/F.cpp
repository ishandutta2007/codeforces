/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair <int,int>
#define pll pair <ll,ll>
#define pdd pair <double,double>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	inline void print(int x){if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=998244353;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init(int n){
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=3e5+5;

int n;
vector <pii> ans;

void fill(int lim,int n,int p){
	if(n==0)return;
	fill(lim,n-1,p);
	int gap=1<<n;
	for(int i=0;i+gap<=lim;i+=gap)
		for(int j=i+1;j<=i+gap/2;j++)
			ans.pb((pii){j+p,j+p+gap/2});
}

void solve(){
	cin>>n;
	deque <vector <int> > c;
	for(int i=20,p=0;~i;i--)
		if((n>>i)&1){
			int v=1<<i;
			fill(v,i,p);
			vector <int> tmp;
			for(int j=p+1;j<=p+v;j++)tmp.pb(j);
			c.pb(tmp),p+=v;
		}
	vector <int> x=c.front(); c.pop_front();
	while(c.size()>1){
		vector <int> z=c.back();
		c.pop_back();
		vector <int> y=c.back();
		c.pop_back();
		while(z.size()<y.size()){
			vector <int> tmp;
			for(int i=0;i<z.size();i++)
				ans.pb((pii){x.back(),z[i]}),tmp.pb(x.back()),tmp.pb(z[i]),x.pop_back();
			z=tmp;
		} int p=0;
		while(z.size()){
			ans.pb((pii){y[p++],z.back()});
			y.pb(z.back()),z.pop_back();
		}
		c.pb(y);
	} cout<<ans.size()<<endl;
	for(pii it:ans)cout<<it.fi<<" "<<it.se<<endl;
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}