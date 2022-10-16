#include <bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))
///////
inline int read(){
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=x*10+s-'0',s=getchar();
	return x;
}

const int N=3e5+5;
const ll mod=1e9+7;

namespace math{
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

	ll fc[N],ifc[N];
	void init_m(int n){
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll binom(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
} using namespace math;

int n,m,S[N];
int buc[N],cnt[N],f[N];

int main(){
	cin>>n,init_m(N-5);
	for(int i=1;i<=n;i++)S[i]=read(),buc[S[i]]++;
	for(int i=1;i<N;i++)for(int j=i;j<N;j+=i)cnt[i]+=buc[j];
	for(int i=1;i<=7;i++){
		mem(f,0,N);
		for(int j=N-5;j;j--){
			if(cnt[j]<i)continue;
			f[j]=binom(cnt[j],i);
			for(int k=j+j;k<N-4;k+=j)f[j]=(f[j]-f[k]+mod)%mod;
		} if(f[1]>0)cout<<i<<endl,exit(0); 
	} puts("-1"); 
	return 0;
}