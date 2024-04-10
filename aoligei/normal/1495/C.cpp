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
int n,m;
char c[502][502];
bool ban[502][502],k[502][502];
int main() {
	F(qwq,1,read()){
		read(n);read(m);
		F(i,1,m+1)c[n+1][i]='.';
		F(i,1,n+1)c[i][m+1]='.';
		F(i,1,n){
			scanf("%s",c[i]+1);
		}
		if(n%3){
			for(ri i=1;i<=n;i+=3){
				F(j,1,m)c[i][j]='X';
				if(i<n-1){
					if(c[i+1][2]!='X'&&c[i+2][2]!='X')c[i+1][1]=c[i+2][1]='X';
					else c[i+1][2]=c[i+2][2]='X';
				}
			}
			
		}else{
			for(ri i=2;i<=n;i+=3){
				F(j,1,m)c[i][j]='X';
				if(i<n-1){
					if(c[i+1][2]!='X'&&c[i+2][2]!='X')c[i+1][1]=c[i+2][1]='X';
					else c[i+1][2]=c[i+2][2]='X';
				}
			}
		}F(i,1,n){
			printf("%s\n",c[i]+1);
		}
	}
	return 0;
}