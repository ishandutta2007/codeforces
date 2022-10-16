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

int h,m;

int rev(int a){
	if(a==0)return 0;
	if(a==1)return 1;
	if(a==2)return 5;
	if(a==5)return 2;
	if(a==8)return 8;
	return -1;
}

bool check(char a,char b,char c,char d){
	int aa=rev(d-'0'),bb=rev(c-'0'),cc=rev(b-'0'),dd=rev(a-'0');
	if(~aa&&~bb&&~cc&&~dd){
		int hh=aa*10+bb,mm=cc*10+dd;
		return hh<h&&mm<m;
	} return 0;
}

void solve(){
	char a,b,c,d;
	cin>>h>>m>>a>>b>>c>>c>>d;
	while(!check(a,b,c,d)){
		d++;
		if(d>'9')d='0',c++;
		int mm=(c-'0')*10+d-'0';
		if(mm>=m)c=d='0',b++;
		if(b>'9')b='0',a++;
		int hh=(a-'0')*10+b-'0';
		if(hh>=h)a=b=c=d='0';
	}
	cout<<a<<b<<":"<<c<<d<<endl;
}

int main(){
	int t=1;
	cin>>t;
	while(t--)solve();

	return 0;
}