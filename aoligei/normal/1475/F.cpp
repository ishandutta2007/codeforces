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
int t,n,f[2002],tag[2002],size[2002];
char a[1002][1002],b[1002][1002];
inline int findf(int x){
	return (f[x]==x)?x:findf(f[x]);
}
inline bool findt(int x){
	return (f[x]==x)?0:(findt(f[x])^tag[x]);
}
int main() {
F(qwq,1,read()){
	read(n);
	F(i,1,n+n)f[i]=i,size[i]=1,tag[i]=0;
	F(i,1,n){
		scanf("%s",a[i]+1);
	}F(i,1,n)scanf("%s",b[i]+1);
	F(i,1,n){
		F(j,1,n){
			if(findf(i)==findf(j+n)){
				if((findt(i)==findt(j+n))!=(a[i][j]==b[i][j])){
					puts("no");
					goto nxt;
				}
			}else{
				a[i][j]-='0',b[i][j]-='0';
				a[i][j]^=b[i][j];
				a[i][j]^=findt(i)^findt(j+n);
				ri fa=findf(i),fb=findf(j+n);
				if(size[fa]>size[fb])f[fb]=fa,tag[fb]=a[i][j],size[fa]+=size[fb];
				else f[fa]=fb,tag[fa]=a[i][j],size[fb]+=size[fa];
			}
		}
	}puts("yes");
	nxt:;
}
	return 0;
}