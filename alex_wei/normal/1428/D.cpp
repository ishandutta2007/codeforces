/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
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
	void init_m(int n){
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

#define no puts("-1"),exit(0)

const int N=1e5+5;

int a[N],n,col;
deque <int> y,z;
vector <pii> ans;

void solve(){
	cin>>n; col=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			if(!y.size()&&!z.size())ans.pb((pii){i,col++});
			else if(!y.size()){
				while(z.size()>1){
					ans.pb((pii){z[0],col}),ans.pb((pii){z[1],col++});
					z.pop_front();
				} int v=z.back(); z.pop_back();
				ans.pb((pii){v,col}),ans.pb((pii){i,col++}),ans.pb((pii){i,col++});
			}
			else{
				int v=y.back(); y.pop_back();
				int fd=lower_bound(z.begin(),z.end(),v)-z.begin()-1;
				if(fd>=0){
					for(int i=0;i<fd;i++){
						ans.pb((pii){z[i],col}),ans.pb((pii){z[i+1],col++});
					} ans.pb((pii){z[fd],col}),ans.pb((pii){v,col++});
					ans.pb((pii){v,col}),ans.pb((pii){i,col++});
					while(fd>=0)fd--,z.pop_front();
				} else ans.pb((pii){v,col}),ans.pb((pii){i,col++});
			}
		} else if(a[i]==2)y.pb(i);
		else if(a[i]==3)z.pb(i);
	} if(y.size()||z.size())no;
	cout<<ans.size()<<endl;
	for(pii it:ans)cout<<it.se<<" "<<it.fi<<endl;
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
/*
6
3 3 2 2 1 1
*/