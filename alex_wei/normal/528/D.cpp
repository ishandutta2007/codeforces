#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define gc getchar()
#define pb push_back
#define mem(x,v,n) memset(x,v,sizeof(int)*n)
#define cpy(x,y,n) memcpy(x,y,sizeof(int)*n)

const ld Pi=acos(-1);
const ll mod=998244353;

inline int read(){
	int x=0; char s=gc;
	while(!isdigit(s))s=gc;
	while(isdigit(s))x=x*10+s-'0',s=gc;
	return x;
}

ll ksm(ll a,ll b){
	ll s=1;
	while(b){
		if(b&1)s=s*a%mod;
		a=a*a%mod,b>>=1;
	}
	return s;
}
ll inv(ll x){return ksm(x,mod-2);}
void mul(int *f,int *g,int n){for(int i=0;i<n;i++)f[i]=1ll*f[i]*g[i]%mod;}

const int G=3;
const int ivG=inv(3);

const int N=1<<18;

int r[N];
void pre(int n){for(int i=1;i<n;i++)r[i]=(r[i>>1]>>1)|(i&1?n>>1:0);}
void NTT(int *g,int n,bool op){
	pre(n);
	static ull f[N],w[N]; w[0]=1;
	for(int i=0;i<n;i++)f[i]=g[r[i]];
	for(int l=1;l<n;l<<=1){
		ll wn=ksm(op?G:ivG,(mod-1)/(l+l));
		for(int i=1;i<l;i++)w[i]=w[i-1]*wn%mod;
		for(int i=0;i<n;i+=l<<1)
			for(int j=0;j<l;j++){
				int t=w[j]*f[i|j|l]%mod;
				f[i|j|l]=f[i|j]+mod-t,f[i|j]+=t;
			}
		if(l==(1<<16))for(int i=0;i<n;i++)f[i]%=mod;
	}
	if(!op){
		ll iv=inv(n);
		for(int i=0;i<n;i++)g[i]=f[i]%mod*iv%mod;
	} else for(int i=0;i<n;i++)g[i]=f[i]%mod;
}

int n,m,lim=1,ans,k,p[N],f[N],g[N],ps[N];
char s[N],t[N];

void check(char it){
	mem(ps,0,N),mem(f,0,N),mem(g,0,N);
	for(int i=0;i<n;i++)if(s[i]==it)ps[max(0,i-k)]++,ps[min(n,i+k+1)]--;
	for(int i=0;i<n;i++)f[i]=(ps[i]+=i?ps[i-1]:0)>0;
	for(int i=0;i<m;i++)g[i]=t[i]==it;
	NTT(f,lim,1),NTT(g,lim,1);
	for(int i=0;i<lim;i++)f[i]=1ll*f[i]*g[i]%mod;
	NTT(f,lim,0);
	for(int i=0;i<n;i++)p[i]+=f[i];
}
int main(){
	scanf("%d%d%d%s%s",&n,&m,&k,s,t);
	reverse(s,s+n);
	while(lim<n)lim<<=1;
	check('A'),check('C'),check('G'),check('T');
	for(int i=m-1;i<n;i++)ans+=(p[i]==m);
	cout<<ans<<endl; 
	return 0;
}