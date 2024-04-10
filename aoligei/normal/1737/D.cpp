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
ll e[502][502];
ll w[502][502],d[502][502];
int n,m,u[250002],v[250002],W[250002];
int main() {
	F(dsaf,1,read()){
		memset(e,0x3f,sizeof(e));
		memset(w,0x3f,sizeof(w));
		memset(d,0x3f,sizeof(d));
		read(n,m);
		F(i,1,m){
			int x=read(),y=read();ll z=read();
			u[i]=x,v[i]=y,W[i]=z;
			e[x][y]=e[y][x]=1;
			w[x][y]=min(w[x][y],z);
			w[y][x]=min(w[y][x],z);
		}
		F(i,1,n)e[i][i]=0;
		F(k,1,n)F(i,1,n)F(j,1,n)e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
		ll ans=1e18;
		F(j,1,m){
			F(i,1,n){
				ans=min(ans,(e[1][i]+e[n][i]+2+min(e[u[j]][i],e[v[j]][i]))*W[j]);
			}
			ans=min(ans,(e[1][u[j]]+e[n][v[j]]+1)*W[j]);
			ans=min(ans,(e[1][v[j]]+e[n][u[j]]+1)*W[j]);
		}
		write(ans,'\n');
	}
	return 0;
}