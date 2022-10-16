/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;
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
//	const int mod=99824353;
	const int maxn=2e6+5;

	ll ksm(ll a,ll b,ll p){
		ll s=1,m=a%p;
		while(b){
			if(b&1)s=s*m%p;
			m=m*m%p,b>>=1;
		} return s;
	}
}

using namespace IO;
using namespace math;

const int N=2e5+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;

ll ans=1;
int n,q,ava,p[N],x[N],to[N],sm[N];
vector <int> mp[N];
multiset <int> s[N];
pii f[N][8],ss[N][8];

void fc(int n,int tp,int id){
	int num=0;
	for(int i=2;i*i<=n;i++)
		if(n%i==0){
		int cnt=0;
		while(n%i==0)cnt++,n/=i;
		if(tp==1)f[id][num++]={i,cnt};
		else ss[id][num++]={i,cnt};
	} assert(num<8);
	if(n>1)tp==1?f[id][num++]={n,1}:ss[id][num++]={n,1};
}

int get(int d){
	return s[d].size()<n?0:*s[d].begin();
}
void upd(int id,int d,int ad){
	if(sm[d]<n)return;
	int ori=d;
	d=to[d];
	int v=get(d);
	auto it=s[d].find(mp[id][d]);
	if(it!=s[d].end())s[d].erase(it);
	s[d].insert(mp[id][d]+=ad);
	int vv=get(d);
	ans=ans*ksm(ori,vv-v,mod)%mod;
}

vector <int> qu[N];
int buc[N];

void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)fc(read(),1,i);
	for(int i=1;i<=q;i++){
		p[i]=read(),x[i]=read();
		qu[p[i]].pb(i),fc(x[i],2,i);
	}
	for(int i=1;i<=n;i++){
		for(pii it:f[i])if(!buc[it.fi])buc[it.fi]=1,sm[it.fi]++;
		for(int it:qu[i])for(pii j:ss[it])if(!buc[j.fi])buc[j.fi]=1,sm[j.fi]++;
		for(pii it:f[i])buc[it.fi]=0;
		for(int it:qu[i])for(pii j:ss[it])buc[j.fi]=0;
	} int d=0;
	for(int i=1;i<=2e5;i++)if(sm[i]==n)to[i]=d++;
	for(int i=1;i<=n;i++)mp[i].resize(d+1);
	for(int i=1;i<=n;i++){
		for(pii it:f[i])upd(i,it.fi,it.se);
	}
	for(int i=1;i<=q;i++){
		for(pii it:ss[i])upd(p[i],it.fi,it.se);
		print(ans),pc('\n'); 
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();
	return flush(),0;
}