/*
	Templates start.
	Powered by c++11.
	Author : Alex_Wei.
*/

//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

// IO templates.

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

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

/*
	Templates end.
	Please give me more points.
*/

const int N=2e5+5;
const ll mod=998244353;

ll ksm(ll a,ll b){
	ll s=1,m=a;
	while(b){
		if(b&1)s=s*m%mod;
		b>>=1,m=m*m%mod;
	}
	return s;
}
ll inv(ll x){return ksm(x,mod-2);}

ll n,k,ans,tmp,v,a[N],f[N],vf[N];

ll C(ll m,ll n){return f[n]*vf[m]%mod*vf[n-m]%mod;}

int main(){
	cin>>n>>k,f[0]=vf[0]=1;
	for(int i=1;i<=n;i++)cin>>a[i],f[i]=f[i-1]*i%mod,vf[i]=inv(f[i]);
	for(int i=1;i<=n;i++)v+=a[i]!=a[i==1?n:i-1];
	tmp=ksm(k,n-v);
	for(int i=0;i<=v;i++)ans=(ans+ksm(k-2,v-i)*C(v-i,v)%mod*(ksm(2,i)-(i&1?0:C(i/2,i)))%mod*inv(2))%mod;
	cout<<((ans+mod)%mod)*tmp%mod<<endl;
	return 0;
}