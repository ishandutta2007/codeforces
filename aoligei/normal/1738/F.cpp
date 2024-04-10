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
vector<int>a[1002];
int n,deg[1002],rk[1002],sa[1002],c[1002];
bool vis[1002];
inline bool cmp(int x,int y){
	return deg[x]<deg[y];
}
int main() {
	F(dasf,1,read()){
		memset(vis,0,sizeof(vis));
		read(n);
		F(i,1,n)read(deg[i]),sa[i]=c[i]=i,a[i].clear();
		sort(sa+1,sa+n+1,cmp);
		F(i,1,n)rk[sa[i]]=i;
		UF(ii,n,1){
			int i=sa[ii];
			if(!vis[i]){
				a[i]={i};vis[i]=true;
				F(j,1,deg[i]){
					printf("? %d\n",i);
					fflush(stdout);
					int v=read();
					if(vis[v]){
						for(int k:a[i])a[c[v]].push_back(k),c[k]=c[v];
						a[i].clear();
						break;
					}else{
						vis[v]=true;
						a[i].push_back(v);
						c[v]=i;
					}
				}
			}
		}
		putchar('!');putchar(' ');
		F(i,1,n)for(int j:a[i])c[j]=i;
		F(i,1,n)write(c[i],' ');puts("");fflush(stdout);
	}
	return 0;
}