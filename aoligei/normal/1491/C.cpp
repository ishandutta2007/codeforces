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
		if(x==0) {
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
ll n,a[5002],ans,nxt[10002];
inline int findf(int pos) {
	return (nxt[pos]==pos)?pos:(nxt[pos]=findf(nxt[pos]));
}
inline void mg(int x,int y) {
	nxt[x]=findf(y);
}
int main() {
	F(qwq,1,read()) {
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		memset(nxt,0,sizeof(nxt));
		F(i,1,n)read(a[i]),nxt[i]=i;
		nxt[n+1]=n+1;
		F(i,1,n) {
			if(a[i]>n-i+1)ans+=a[i]-(n-i+1),a[i]=n-i+1;
			while(a[i]>1) {
				ri pos=i;
				ans++;
				while(pos<=n&&pos) {
					ri lst=a[pos];
					a[pos]=max(a[pos]-1,1ll);
					if(a[pos]==1)mg(pos,pos+1);
					if(pos+lst>n)pos=0;
					else pos=nxt[pos+lst];
				}
			}
		}
		write(ans,'\n');
	}
	return 0;
}