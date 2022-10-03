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
using std::bitset;
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
int pre[300002],suf[300002],a[300002],n,temp,ans;
il bool isf(int pos){if(pos==1||pos==n)return 0;
	return (a[pos]>a[pos-1]&&a[pos]>a[pos+1])||(a[pos]<a[pos-1]&&a[pos]<a[pos+1]);
}
int main() {
F(qwq,1,read()){
	read(n);
	F(i,0,n+1){
		pre[i]=suf[i]=0;
	}F(i,1,n)read(a[i]);
	if(n<3){
		puts("0");continue;
	}
	F(i,1,n)pre[i]=pre[i-1]+isf(i);
	UF(i,n,1)suf[i]=suf[i+1]+isf(i);
	ans=pre[n];
	F(i,2,n-1){
		temp=a[i];
		a[i]=a[i-1];
		ans=min(ans,pre[i-2]+suf[i+2]+isf(i)+isf(i-1)+isf(i+1));
		a[i]=a[i+1];
		ans=min(ans,pre[i-2]+suf[i+2]+isf(i)+isf(i-1)+isf(i+1));
		a[i]=temp;
	}write(ans,'\n');
}
	return 0;
}