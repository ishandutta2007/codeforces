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
int dis[200002],dp[200002],n,m,temp[200002];
vector<int>g[200002];
bool vis[200002];
queue<int>q;
bool cmp(int x,itn y){
	return dis[x]>dis[y];
}
int main() {
F(qwq,1,read()){read(n);read(m);
	F(i,1,n)dis[i]=dp[i]=1e9,vis[i]=0,temp[i]=i,g[i].clear();
	F(i,1,m){
		ri t1=read(),t2=read();
		g[t1].push_back(t2);
	}dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty()){
		ri pos=q.front();
		q.pop();
		F(i,0,g[pos].size()-1){
			if(!vis[g[pos][i]]){
				q.push(g[pos][i]);
				dis[g[pos][i]]=dis[pos]+1;
				vis[g[pos][i]]=1;
			}
		}
	}sort(temp+1,temp+n+1,cmp);
	F(ii,1,n){ri i=temp[ii];dp[i]=dis[i];
		F(j,0,g[i].size()-1){
			if(dis[g[i][j]]>dis[i]){
				dp[i]=min(dp[i],dp[g[i][j]]);
				
			}else dp[i]=min(dp[i],dis[g[i][j]]);
		}
	}F(i,1,n)write(dp[i],' ');
	puts("");
}
	return 0;
}