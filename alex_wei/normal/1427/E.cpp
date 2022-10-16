/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(3)
#define int long long

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

//using namespace IO;
//using namespace math;

const int N=1e6+5;

int x,cnt,f[N];
vector <int> ans[N];
map <int,bool> mp;

int pls(int x,int y){
	cnt++;
	ans[cnt].pb(x);
	ans[cnt].pb(0);
	ans[cnt].pb(y);
	return x+y;
}
int xo(int x,int y){
	cnt++;
	ans[cnt].pb(x);
	ans[cnt].pb(1);
	ans[cnt].pb(y);
	return x^y;
}

void mer(int tp,int j,int x){
	int v=max((int)log2(j),4ll);
	for(int i=0;i<=v;i++){
		pls(x<<i,x<<i);
	} int res=0;
	for(int i=0;i<=v;i++)
		if((j>>i)&1){
			if(res){
				pls(res,x<<i);
				res+=x<<i;
			} else res=x<<i;
		}
	if(tp==1){
		int c=pls(x*j,x*2);
		int a=xo(x*2,x);
		int b=pls(a,x*j);
		xo(b,c);
	} else{
		int a=xo(x*2,x);
		int b=pls(a,x*j);
		int c=pls(x*j,x*4);
		int d=xo(b,c);
		xo(d,x*2);
	}
}

void print(int val){
	if(val==1)return;
	int v=0,res=0;
	for(int j=1;j<=1e7;j++){
		int x=((val*2)^val)+val*j,y=val*j;
		if((x^(y+val*2))<val){
			v=j;
			res=x^(y+val*2);
			mer(1,j,val);
			print(res);
			return;
		}
		else if((x^(y+val*4)^(val*2))<val){
			v=j;
			res=x^(y+val*4)^(val*2);
			mer(2,j,val);
			print(res);
			break;
		}
	}
}

void solve(){
	cin>>x; mp[x]=1;
	print(x);
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<ans[i][0]<<" ";
		cout<<(ans[i][1]?'^':'+');
		cout<<" "<<ans[i][2]<<endl;
	}
	for(int i=3;i<=x;i+=2){
		int v=0,res=0;
		for(int j=1;j<=1e7;j++){
			int x=((i*2)^i)+i*j,y=i*j;
			if((x^(y+i*2))<i){
				v=j;
				res=x^(y+i*2);
				break;
			}
			else if((x^(y+i*4)^(i*2))<i){
				v=j;
				res=x^(y+i*4)^(i*2);
				break;
			}
		}
	}
}

signed main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}