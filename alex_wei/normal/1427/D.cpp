/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(3)
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

const int N=52+5;

int n,d[N],c[N],l[N],pos[N],v,cnt;
vector <int> ans[N];

void op(){
	vector <int> x[N];
	int num=0; ans[++cnt].pb(v);
	for(int i=1;i<=v;i++){
		ans[cnt].pb(c[i]);
		for(int j=1;j<=c[i];j++)
			x[i].pb(d[++num]);
	}
	num=0;
	for(int i=v;i;i--)
		for(int it:x[i])
			d[++num]=it;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>d[i];
	bool pre=0;
	while(1){
		int hav=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[j]==i)
					pos[i]=j;
		for(int i=1;i<n;i++)
			if(pos[i]>pos[i+1]){
				hav=i;
				break;
			}
		if(!hav)break;
		int pp=pos[hav];
		while(d[pp-1]+1==d[pp])pp--;
		pp--;
		v=0;
		if(pos[hav+1]-1)c[++v]=pos[hav+1]-1;
		c[++v]=pp-pos[hav+1]+1;
		c[++v]=pos[hav]-pp;
		if(n-pos[hav])c[++v]=n-pos[hav];
		op();
	} cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		for(int it:ans[i])cout<<it<<" ";
		cout<<endl;
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}