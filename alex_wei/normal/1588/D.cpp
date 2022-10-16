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
	#define flush() fwrite(obuf,1,O-obuf,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void rec_print(int x){if(x>=10)rec_print(x/10);pc(x%10+'0');}
	void print(int x){if(x<0)pc('-'),x=-x;rec_print(x);}
}

namespace math{
	const int mod=998244353;
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

template <class T1,class T2> void cmin(T1 &a,T2 b){a=a<b?a:b;}
template <class T1,class T2> void cmax(T1 &a,T2 b){a=a>b?a:b;}

const int N=10;
int n,len[N],mp[1<<N];
pii tr[1<<N][1<<N];
int f[1<<7][1<<N],buc[N][1<<N],pos[2][N][1<<N]; 
char s[N][1<<N];
void print(int i,int S){
	if(!i)return;
	print(tr[i][S].fi,tr[i][S].se);
	cout<<s[0][i-1];
}
void solve(){
	cin>>n,mem(buc,0),mem(pos,-1),mem(f,0);
	for(int i=0;i<n;i++){
		cin>>s[i],len[i]=strlen(s[i]);
		for(int j=0;j<len[i];j++){
			int id=mp[s[i][j]];
			pos[buc[i][id]++][i][id]=j;
		}
	}
	for(int i=0;i<len[0];i++)
		for(int j=i+1;j<=len[0];j++)
			for(int S=0;S<1<<n;S++){
				int ok=1,msk=0;
				int pre=i?mp[s[0][i-1]]:0,suf=mp[s[0][j-1]];
				for(int p=0;p<n&&ok;p++){
					if(!buc[p][suf]){ok=0;break;}
					if(!i)continue;
					int b=S>>p&1;
					if(buc[p][pre]<=b){ok=0;break;}
					int lim=pos[b][p][pre],fd=-1;
					for(int z=0;z<buc[p][suf];z++)
						if(pos[z][p][suf]>lim){
							fd=z;
							break;
						}
					if(fd==-1){ok=0;break;}
					msk|=fd<<p;
				}
				if(!ok)continue;
				if(f[i][S]+1>f[j][msk])
					f[j][msk]=f[i][S]+1,tr[j][msk]={i,S};
			}
	int ansp=0,ansS=0;
	for(int i=1;i<=len[0];i++)
		for(int S=0;S<1<<n;S++)
			if(f[i][S]>f[ansp][ansS])
				ansp=i,ansS=S;
	cout<<f[ansp][ansS]<<endl;
	print(ansp,ansS),cout<<endl;
}

int main(){
	for(int i=0;i<26;i++)mp['A'+i]=i;
	for(int i=0;i<26;i++)mp['a'+i]=i+26;
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}