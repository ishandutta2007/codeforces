// Author: wlzhouzhuan
#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mset(s,t) memset(s,t,sizeof(s))
#define mcpy(s,t) memcpy(s,t,sizeof(t))
#define SZ(x) ((int)x.size())
#define pb push_back
#define eb emplace_back
#define fir first
#define sec second

template<class T1,class T2>bool ckmax(T1 &a,T2 b){if(a<b)return a=b,1;else return 0;}
template<class T1,class T2>bool ckmin(T1 &a,T2 b){if(a>b)return a=b,1;else return 0;}

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=ch=='-',ch=getchar();
	while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
	return f?-x:x;
}
template<typename T>void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+'0');
}
template<typename T>void print(T x,char ch){
	print(x),putchar(ch);
}

const int N=200005;
const int mod=998244353;

inline void add(int &x,int y){
	if((x+=y)>=mod)x-=mod;
}

int fac[N],ifac[N];
int n,m,a[N],b[N],cnt[N];

inline int qpow(int a,int b=mod-2){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}
inline void init(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n]);per(i,n,1)ifac[i-1]=1ll*ifac[i]*i%mod;
}

struct fen{
	int c[N];
	void ins(int x,int dlt){
		while(x<=200000)
			add(c[x],dlt),x+=x&-x;
	}
	int qry(int x){
		int ret=0;
		while(x)
			add(ret,c[x]),x^=x&-x;
		return ret;
	}
}tr;

int main(){
	n=read(),m=read(),init(200000);
	rep(i,1,n)a[i]=read(),cnt[a[i]]++;
	rep(i,1,m)b[i]=read();
	int now=1;
	rep(i,1,200000){
		if(cnt[i]){
			tr.ins(i,1ll*fac[cnt[i]]*ifac[cnt[i]-1]%mod);
			now=1ll*now*ifac[cnt[i]]%mod;
		}
	}
	int ans=0;
	rep(i,1,min(n,m)){
		int qwq=tr.qry(b[i]-1);
		// printf("when i=%d,qwq=%d,now=%d\n",i,qwq,now);
		ans=(ans+1ll*qwq*fac[n-i]%mod*now)%mod;
		// printf("ans=%d\n",ans);
		if(!cnt[b[i]])break;
		tr.ins(b[i],(mod-1ll*fac[cnt[b[i]]]*ifac[cnt[b[i]]-1]%mod)%mod);
		now=1ll*now*fac[cnt[b[i]]]%mod;
		cnt[b[i]]--;
		if(cnt[b[i]])tr.ins(b[i],1ll*fac[cnt[b[i]]]*ifac[cnt[b[i]]-1]%mod);
		now=1ll*now*ifac[cnt[b[i]]]%mod;
		if(i==n&&m>n)ans=(ans+1)%mod;
	}
	print(ans,'\n');
	return 0;
}