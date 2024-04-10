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
bool vis[200002],isf[200002];
int n,t1,t2,fib[200002],sz[200002],cnt,qwq[200002],quq[200002],tot;
vector<int>g[200002];
inline void dfs(ri pos,ri fa,ri tot) {
	sz[pos]=1;
	F(i,0,g[pos].size()-1) {
		if(!vis[g[pos][i]]&&g[pos][i]!=fa) {
			dfs(g[pos][i],pos,tot);
			sz[pos]+=sz[g[pos][i]];
		}
	}
	if(isf[sz[pos]]&&isf[tot-sz[pos]])qwq[++cnt]=pos,quq[cnt]=fa;
}
#include<assert.h>
inline bool ok(ri pos,ri tot) {
	if(tot==1)return 1;
	cnt=0;
	dfs(pos,0,tot);assert(cnt<10);
	int ss[10],qaq[10],qvq[10],cc=cnt;
	F(i,1,cnt) {
		qaq[i]=qwq[i];
		qvq[i]=quq[i];
		ss[i]=sz[qaq[i]];
	}cc=min(cc,1);
	F(i,1,cc) {
		vis[qaq[i]]=1;
		if(!ok(qvq[i],tot-ss[i])) {
			vis[qaq[i]]=0;
			continue;
		}
		vis[qaq[i]]=0;
		vis[qvq[i]]=1;
		if(!ok(qaq[i],ss[i])) {
			vis[qvq[i]]=0;
			continue;
		}
		vis[qvq[i]]=0;
		return 1;
	}return 0;
}
int main() {
	cin>>n;
	fib[1]=fib[2]=1;
	for(int i=2; fib[i]+fib[i-1]<=n; ++i)fib[i+1]=fib[i]+fib[i-1],isf[fib[i+1]]=1;
	isf[1]=1;
	if(!isf[n]){while(clock()<800);
		puts("NO");return 0;
	}
	F(i,2,n) {
		read(t1);
		read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}
	if(ok(1,n))puts("YES");
	else puts("NO");
	return 0;
}