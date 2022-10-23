//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <climits>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <random>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
using namespace std;
//using namespace __gnu_pbds;
const double Pi=acos(-1);
namespace fastIO {
	template<class T>
	inline void read(T &x) {
		x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		if(fu)x=-x;
	}
	inline int read() {
		int x=0;
		bool fu=0;
		char ch=0;
		while(ch>'9'||ch<'0') {
			ch=getchar();
			if(ch=='-')fu=1;
		}
		while(ch<='9'&&ch>='0') x=(x*10-48+ch),ch=getchar();
		return fu?-x:x;
	}
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
	}
	char _n_u_m_[40];
	template<class T>
	inline void write(T x) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		int cnt = 0 ;
		while( tmp > 0 ) {
			_n_u_m_[ cnt ++ ] = tmp % 10 + '0' ;
			tmp /= 10 ;
		}
		while( cnt > 0 ) putchar(_n_u_m_[ -- cnt ]) ;
	}
	template<class T>
	inline void write(T x ,char ch) {
		write(x);
		putchar(ch);
	}
}
using namespace fastIO;
const int mod=1e9+7;
long long n,fac[3000002],ifac[3000002],inv[3000002],v[1000002],suf0[2000002],suf1[2000002],p2[1000002],i2[1000002],pre[1000002],w[1000002];
inline long long pw(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
inline long long C(long long top,long long bot){
	if(top<bot||top<0||bot<0)return 0;
	return fac[top]*ifac[bot]%mod*ifac[top-bot]%mod;
}
int main() {
	n=3e6;
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	F(i,1,n)inv[i]=ifac[i]*fac[i-1]%mod;
	p2[0]=i2[0]=1;
	F(i,1,1e6)p2[i]=1ll*p2[i-1]*2%mod;
	i2[1]=getm(1,2);
	F(i,2,1e6)i2[i]=1ll*i2[i-1]*i2[1]%mod;
	F(i,2,1e6)pre[i]=(pre[i-1]+i2[i+1])%mod;
	F(dsaf,1,read()){
		read(n);
		if(n==1){
			puts("1");
			continue;
		}
		F(i,0,n+n+1)v[i]=suf0[i]=suf1[i]=w[i]=0;
		v[n]=1;
		w[n]=1;
		UF(i,n,1){
			
			if(i!=n)v[i]=p2[i]*(suf1[i+2]-suf1[i+i]+mod)%mod,w[i]=(v[i]+i2[1]*w[i+1])%mod;
		//	suf0[i]=(suf0[i+1]+i2[i]*w[i])%mod;
			w[n-1]=1;
			suf1[i]=(suf1[i+1]+i2[i-(i==n)]*w[i]%mod)%mod;
		//	suf1[n-1]=suf1[n];
		}
	//	F(i,1,n)cerr<<w[i]<<" ";cerr<<endl;
		write(0,'\n');
	//	F(i,1,n)cerr<<v[i]<<" ";cerr<<endl;
	ll sum=0;
		F(i,2,n){
			ll tot=i2[(i+1)>>1];
			if(i==n)tot=1ll*tot*2%mod;
		//	cerr<<tot<<endl;
			write(tot*w[i]%mod,'\n');
			sum+=tot*w[i]%mod;
		}
	//	cerr<<sum%mod<<endl;
	}
	return 0;
}