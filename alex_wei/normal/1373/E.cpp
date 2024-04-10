/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) putchar(x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=99824353;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1; for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]); for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=2e5+5;
const int inf=0x3f3f3f3f;

void solve(){
	ll n,k,ans=1e18; cin>>n>>k;
	if(k==0){
		if(n%9)cout<<n%9,n-=n%9;
		while(n)cout<<9,n-=9; cout<<endl;
		return;
	}
	for(int i=0;i<=n/9;i++){
		for(int j=0;j<=9;j++){
			int bit=i*9+j,tmp=j,sum=bit;
			for(int m=1;m<=k;m++){
				bit++,tmp=(tmp+1)%10;
				if(tmp==0)bit-=(i+1)*9;
				sum+=bit;
			}
			int res=n-sum;
			if(res>=0&&res%(k+1)==0){
				ll z=j,bs=10,tag=0; res/=(k+1);
				for(int m=0;m<i;m++)z+=9*bs,bs*=10;
				while(res){
					int sub=min(res,tag?9:8);
					res-=sub,z+=sub*bs,bs*=10,tag=1;
				}
				ans=min(ans,z);
			}
		}
	} cout<<(ans==1e18?-1:ans)<<endl;
}

int main(){
	int t=1;
	cin>>t;
	while(t--)solve();
	return 0;
}
/*
1
99 1
*/