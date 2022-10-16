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

inline int qpow(int a,int b){
	int res=1;
	while(b>0){
		if(b&1)res=1ll*res*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return res;
}	

int x[N],y[N],n,m,K,q;
bool usedrow[N],usedcol[N];
int usedr,usedc;

void solve(){
	n=read(),m=read(),K=read(),q=read();
	rep(i,1,q)x[i]=read(),y[i]=read();
	int ans=0;
	per(i,q,1){
		bool r=!usedrow[x[i]]&&usedc!=m;
		bool c=!usedcol[y[i]]&&usedr!=n;
		if(r||c)ans++;
		if(!usedrow[x[i]])usedrow[x[i]]=1,usedr++;
		if(!usedcol[y[i]])usedcol[y[i]]=1,usedc++;
	}
	print(qpow(K,ans),'\n');
	rep(i,1,q)usedrow[x[i]]=usedcol[y[i]]=0;
	usedr=usedc=0;
}

int main(){
	int T=read();
	while(T--)solve();
	return 0;
}