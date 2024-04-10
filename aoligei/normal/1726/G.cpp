//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <math.h>
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
//#include <ext/pb_ds/tree_policy.hpp>
#define itn int
#define nit int
#define ll long long
#define ms multiset
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
//#pra gma G CC opti mize(3)
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
	inline void write(T x ) {
		if(x==0){
			putchar('0');
			return;
		}
		T tmp = x > 0 ? x : -x ;
		if( x < 0 ) putchar('-') ;
		register int cnt = 0 ;
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
int n,a[400002],b[400002],temp[200002];
inline int fac(int x){
	int rt=1;
	F(i,1,x)rt=1ll*rt*i%mod;
	return rt;
}
bool check(int lim){
	F(i,lim+1,n)if(a[i]||b[i])return false;
	int tot=0;n>>=1;
	F(i,1,lim-1){
		if(a[i]){
			if(lim-i>tot)return false;
			tot+=a[i];
		}
		if(b[i]){
			if(b[i]>1)return false;
			if(lim-i<n-tot-1||lim-i>=n)return false;
			++tot;
		}
	}
	return true;
}
int main(){
	cin>>n;
	F(i,1,n)read(temp[i]);
	if(*min_element(temp+1,temp+n+1)==*max_element(temp+1,temp+n+1)){
		cout<<fac(n);
		return 0;
	}
	F(i,1,n){
		if(read())++b[temp[i]];
		else ++a[temp[i]];
	}
	int lim=1;
	n<<=1;
	while(!b[lim])++lim;
	lim+=(n>>1)-1;
	int ans=1;
	F(p,1,n){
		if(p==lim){
			F(i,1,a[p])ans=1ll*ans*i%mod;
			F(i,1,b[p])ans=1ll*ans*((n>>1)-i+1)%mod;
		}else{
			F(i,1,a[p])ans=1ll*ans*i%mod;
			F(i,1,b[p])ans=1ll*ans*i%mod;
		}
	}
	cout<<(check(lim)?ans:0);
    return 0;
}