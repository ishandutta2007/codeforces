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
	const int mod=1e9+7;
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

const int N=3e5+5;

vector <int> e[N];
int n,son[N],s1,s2;

void dfs(int id,int f){
	son[id]=1;
	int tmp=0;
	for(int it:e[id]){
		if(it!=f){
			dfs(it,id);
			son[id]+=son[it];
			tmp=max(tmp,son[it]);
		}
	} tmp=max(tmp,n-son[id]);
	if(tmp<=n/2){
		if(s1)s2=id;
		else s1=id;
	}
}

void solve(){
	cin>>n,s1=s2=0;
	for(int i=1;i<=n;i++)son[i]=0,e[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].pb(y),e[y].pb(x);
	} dfs(1,0);
	if(s1&&s2){
		int s3=0;
		for(int it:e[s1])
			if(it!=s2)s3=it;
		cout<<s1<<" "<<s3<<endl;
		cout<<s2<<" "<<s3<<endl;
	} else if(s1){
		cout<<s1<<" "<<e[s1][0]<<endl;
		cout<<s1<<" "<<e[s1][0]<<endl;
	}
}

int main(){
	int t=1;
	cin>>t;
	while(t--)solve(); 
	return 0;
}