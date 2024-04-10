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
	#ifdef __WIN64
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=getchar();
		while(!isdigit(s))sign|=s=='-',s=getchar();
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=998244353;
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

const int N=5e3+5;

int n,m,n1,n2,n3,od,ev,cnum,dis[N],col[N],chs[N],ac[N],ac2[N];
int p[N][N],dp[N][N];

queue <int> q;
vector <int> e[N];
vector <pii> c;

int main(){
	cin>>n>>m>>n1>>n2>>n3;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].pb(v),e[v].pb(u);
	}
	ac[0]=1;
	for(int i=1;i<=n;i++){
		if(dis[i])continue;
		q.push(i); cnum++;
		while(!q.empty()){
			int t=q.front(); q.pop();
			col[t]=cnum;
			dis[t]&1?od++:ev++;
			for(int it:e[t]){
				if(it!=i&&!dis[it])
					dis[it]=dis[t]+1,q.push(it);
			}
		}
		c.pb(make_pair(od,ev));
		for(int j=0;j<=n;j++){
			if(j-od>=0&&ac[j-od]){
//				cout<<"ach "<<j<<endl;
				ac2[j]=1;
				dp[j][cnum]=1;
				p[j][cnum]=od;
			}
			else if(j-ev>=0&&ac[j-ev]){
//				cout<<"ach "<<j<<endl;
				ac2[j]=1;
				dp[j][cnum]=0;
				p[j][cnum]=ev;
			}
			else ac2[j]=0;
		}
		for(int j=0;j<=n;j++)ac[j]=ac2[j];
		od=ev=0;
	}
	for(int i=1;i<=n;i++)for(int it:e[i])if((dis[i]&1)==(dis[it]&1)&&col[i]==col[it])
		puts("NO"),exit(0);
	if(ac[n2]){
		puts("YES");
		while(cnum){
			chs[cnum]=dp[n2][cnum];
//			cout<<cnum<<" choose "<<chs[cnum]<<endl;
			n2-=p[n2][cnum--];
//			cout<<n2<<" "<<cnum<<endl;
		}
		for(int i=1;i<=n;i++)
			if((dis[i]&1)==chs[col[i]])
				cout<<2;
			else if(n1)cout<<1,n1--;
			else cout<<3;
	}
	else puts("NO");
	
	return 0;
}