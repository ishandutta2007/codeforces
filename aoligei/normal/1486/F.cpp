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
int n,m,tot[600002],orz[600002],dp[600002],fa[600002][20],tag[600002],qwq[600002];
ll ans;
const int MAXN=600002;
int t1,t2,f[MAXN];
vector<int>g[MAXN],c[MAXN];
map<pair<int,int>,int>mp[600002];
bool vis[MAXN];
inline void make_tree(int pos){
	vis[pos]=1;ri nxt;
	F(i,0,g[pos].size()-1){
		nxt=g[pos][i];
		if(!vis[nxt]){
			f[nxt]=pos;
			c[pos].push_back(nxt);
			make_tree(nxt);
		}
	}
}
inline void dfs(ri pos){
	dp[pos]=dp[f[pos]]+1;
	fa[pos][0]=f[pos];
	F(i,1,18)fa[pos][i]=fa[fa[pos][i-1]][i-1];
	F(i,0,c[pos].size()-1)dfs(c[pos][i]);
}
inline int lca(int x,int y){
	if(dp[x]>dp[y]){
		UF(i,18,0){
			if(dp[fa[x][i]]>=dp[y])x=fa[x][i];
		}
	}swap(x,y);
	if(dp[x]>dp[y]){
		UF(i,18,0){
			if(dp[fa[x][i]]>=dp[y])x=fa[x][i];
		}
	}if(x==y)return x;
	UF(i,18,0){
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	}return f[x];
}
inline int up(ri x,ri lim){
	UF(i,18,0){
		if((1<<i)<=lim)x=fa[x][i],lim-=(1<<i);
	}return x;
}
inline void uuu(ri pos){
	F(i,0,c[pos].size()-1)uuu(c[pos][i]),tag[pos]+=tag[c[pos][i]];
}
int main() {
	cin>>n;
	F(i,2,n){
		read(t1),read(t2);
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}make_tree(1);
	dfs(1);
	cin>>m;
	F(i,1,m){
		read(t1);read(t2);
		ri t3=lca(t1,t2);
		if(t1==t3){
			c[t3].push_back(++n);
			fa[n][0]=t3;
			f[n]=t3;
			dp[n]=dp[t3]+1;
			t1=n;
		}if(t2==t3){
			c[t3].push_back(++n);
			fa[n][0]=t3;
			f[n]=t3;
			dp[n]=dp[t3]+1;
			t2=n;
		}
		ri t4=up(t1,dp[t1]-dp[t3]-1),t5=up(t2,dp[t2]-dp[t3]-1);
		if(t4>t5)swap(t4,t5);
		mp[t3][make_pair(t4,t5)]++;
		qwq[t4]++;
		qwq[t5]++;
		tag[t1]++;
		tag[t2]++;
		tag[t3]--;
		tag[t3]--;
		orz[t3]++;
	}
	uuu(1);
	F(i,1,n){
		int mns=0;
		for(map<pii,int>::iterator d=mp[i].begin();d!=mp[i].end();++d){
			ans+=1ll*(tag[i]-tag[d->first.first]-tag[d->first.second]-(-qwq[d->first.first]-qwq[d->first.second]))*(d->second);
		}
	}
	ll ans2=0;
	F(i,1,n){
		int mns=0;
		for(map<pii,int>::iterator d=mp[i].begin();d!=mp[i].end();++d){
			ans2+=1ll*(orz[i]-qwq[d->first.first]-qwq[d->first.second]+(d->second))*(d->second);
		}
	}
	cout<<ans+ans2/2;
	return 0;
}