/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//using int = long long

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
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;

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
	const int MAXN=1e6+5;
	ll ksm(ll a,ll b){
		ll s=1,m=a;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}
	ll fc[MAXN],ifc[MAXN];
	void init(){
		fc[0]=1; for(int i=1;i<MAXN;i++)fc[i]=fc[i-1]*i%mod;
		ifc[MAXN-1]=inv(fc[MAXN-1]);
		for(int i=MAXN-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll bin(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// Please give me more points.

using namespace IO;
//using namespace math;

const int N=1e5+5;

string op[N<<1];
int v[N<<1],ans[N<<1],cnt;
set <int> s;

int val[N<<2];
void modify(int l,int r,int x,int pos,int v){
	if(l==r){
		val[x]=v;
		return;
	} int m=l+r>>1;
	if(pos<=m)modify(l,m,x<<1,pos,v);
	else modify(m+1,r,x<<1|1,pos,v);
	val[x]=max(val[x<<1],val[x<<1|1]);
}
int query(int l,int r,int ql,int qr,int x){
	if(ql<=l&&r<=qr){
		return val[x];
	} int m=l+r>>1,ans=0;
	if(ql<=m)ans=max(ans,query(l,m,ql,qr,x<<1));
	if(m<qr)ans=max(ans,query(m+1,r,ql,qr,x<<1|1));
	return ans;
}

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n*2;i++){
		cin>>op[i];
		if(op[i][0]=='-')cin>>v[i];
	}
	for(int i=1;i<=2*n;i++){
		if(op[i][0]=='-'){
			int p=(v[i]==n?0:query(1,n,v[i]+1,n,1));
			if(!s.size()){
				puts("NO");
				exit(0);
			} int mx=*--s.end();
			if(p>mx)puts("NO"),exit(0);
			else ans[mx]=v[i],modify(1,n,1,v[i],mx),s.erase(--s.end());
		} else s.insert(i);
	} puts("YES");
	for(int i=1;i<=n<<1;i++)
		if(ans[i])cout<<ans[i]<<" ";
	cout<<endl; 
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve(); 
	return 0;
}