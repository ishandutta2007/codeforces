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
int n,m,u[200005],v[200005],fa[200005],d[200005];
vector<int>g[200005],e;
bool vis[200005],ans[200005],tag[200005];
inline void dfs(int pos,int lst){
	d[pos]=d[lst]+1;
	vis[pos]=true;
	for(int i:g[pos]){
	if((u[i]^v[i]^pos)!=lst){
		if(vis[(u[i]^v[i]^pos)]){
			if(!tag[i])e.push_back(i),tag[i]=true;
		}
		else dfs((u[i]^v[i]^pos),pos);
	}else fa[pos]=i;
	}
}
int main() {
	F(dasf,1,read()){
		read(n,m);
		F(i,1,n)g[i].clear(),vis[i]=false,fa[i]=0;
		F(i,1,m)tag[i]=false;
		e.clear();
		F(i,1,m){
			read(u[i],v[i]);
			g[u[i]].push_back(i);
			g[v[i]].push_back(i);
		}
		dfs(1,0);
		F(i,1,n)vis[i]=false;
		int cnt=0;
		for(int i:e){
			if(!vis[u[i]])++cnt,vis[u[i]]=true;
			if(!vis[v[i]])++cnt,vis[v[i]]=true;
		}
		if(m-n!=2||cnt>3){
			F(i,1,m)ans[i]=0;
			for(int i:e)ans[i]=1;
			F(i,1,m)putchar(ans[i]+'0');
			puts("");
		}else{
			F(i,1,m)ans[i]=0;
			for(int i:e)ans[i]=1;
			for(int i:e){
				if(d[u[i]]<d[v[i]])swap(u[i],v[i]);//cerr<<u[i]<<"k"<<v[i]<<endl;
				if(fa[u[i]]){
					ans[i]=0;
					ans[fa[u[i]]]=1;
			F(i,1,m)putchar(ans[i]+'0');
			puts("");
					break;		
				}
			}
		}
	}
	return 0;
}