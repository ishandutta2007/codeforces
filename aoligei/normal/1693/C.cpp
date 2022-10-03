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
#define F(i,a,b) for(register int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(register int i=a,i##end=b;i>=i##end;--i)
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
int d[200002],n,m,f[200002],now[200002];
vector<int>g[200002],gg[200002];
priority_queue<pii,vector<pii>,greater<pii>>q;
bool vis[200002];
int main() {
	cin>>n>>m;
	memset(d,0x3f,sizeof(d));
	memset(f,0x3f,sizeof(f));
	F(i,1,m){
		int x=read(),y=read();
		g[y].push_back(x);
		gg[x].push_back(y);
	}
	d[n]=f[n]=0;
	q.push({0,n});
	while(!q.empty()){
		int pos=q.top().second;
		q.pop();
		if(vis[pos])continue;
		vis[pos]=true;
		for(auto i:g[pos])if(d[i]>d[pos]+1){
			d[i]=d[pos]+1;
			q.push({d[i],i});
		}
	}
	memset(vis,0,sizeof(vis));
	q.push({0,n});
	while(!q.empty()){
		int pos=q.top().second;
		q.pop();
		if(vis[pos])continue;
		vis[pos]=true;
		for(auto i:g[pos])if(f[i]>f[pos]+gg[i].size()-(++now[i])+1){
			f[i]=f[pos]+gg[i].size()-now[i]+1;
			q.push({f[i],i});
		}
	}
	cout<<f[1];
	return 0;
}