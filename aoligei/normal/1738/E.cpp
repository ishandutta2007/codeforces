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
#define mod 998244353
int n,m,a[100002],b[100002];
ll pre[100002],suf[100002];
long long fac[300002],ifac[300002],inv[300002];
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
	n=3e5;
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	F(i,1,n)inv[i]=ifac[i]*fac[i-1]%mod;
	F(dasf,1,read()){
		read(n);
		F(i,1,n)read(a[i]);a[n+1]=0;
		F(i,0,n+1)pre[i]=suf[i]=a[i];
		F(i,1,n)pre[i]+=pre[i-1];
		UF(i,n,1)suf[i]+=suf[i+1];
		int l=1,r=n;
		int ans=1;
		if(*max_element(a+1,a+n+1)==0){
			F(i,1,n-1)ans=ans*2%mod;
		}else{
		int c0=0,c1=0;
		while(a[l]==0)++c0,++l;
		while(a[r]==0)++c1,--r;
		ll tot=0;
		F(i,0,min(c0,c1))tot+=C(c0,i)*C(c1,i)%mod;
		ans=tot%mod;
		while(l<r){
			if(pre[l]==suf[r]){
				if(pre[l]+suf[r]==pre[n]){
					F(i,1,r-l)ans=ans*2%mod;
					break;
				}
				else{
					++l,--r;
					int c0=1,c1=1;
					while(a[l]==0)++l,++c0;
					while(a[r]==0)--r,++c1;
					ll tot=0;
					F(i,0,min(c0,c1))tot+=C(c0,i)*C(c1,i)%mod;
					ans=ans*(tot%mod)%mod;
				}
			}else if(pre[l]<suf[r])++l;
			else --r;
		}	
		}
		write(ans,'\n');
	}
	return 0;
}