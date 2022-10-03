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
using namespace std;
#define mod 1000000007
int t[200002],f[200002],sum1[200002],sum2[200002],size[200002],a[200002],type,
dp[200002],head[200002],big[200002],root=1,n,m,t1,t2,t3,num,qwqwqwq,p,x,y,z;
vector<int>c[200002],g[200002];
bool vis[200002];
inline int low(int x){
	return -x&x;
}
inline void Add(int pos,int v){
	ri p=pos;
	pos--;
	while(p<=n){
		sum1[p]+=v;
		sum2[p]+=pos*v;
		p+=low(p);
	}
}
inline void add(int l,int r,int v){
	Add(l,v);
	Add(r+1,-v);
}
inline int QWQ(int pos){
	ri rt=0;
	while(pos){
		rt+=sum1[pos];
		pos-=low(pos);
	}return rt;
}
inline int QAQ(int pos){
	ri rt=0;
	while(pos){
		rt+=sum2[pos];
		pos-=low(pos);
	}return rt;
}
inline int Q(int pos){
	return QWQ(pos)*pos-QAQ(pos);
}
inline int query(int l,int r){
	return Q(r)-Q(l-1);
}
inline void make_tree(int pos){	
	vis[pos]=1;dp[pos]=dp[f[pos]]+1;
	F(i,0,g[pos].size()-1)
		if(!vis[g[pos][i]]){
			f[g[pos][i]]=pos;
			c[pos].push_back(g[pos][i]);
			make_tree(g[pos][i]);
		}
}
inline void getsize(int pos){
	F(i,0,c[pos].size()-1){
		getsize(c[pos][i]);
		size[pos]+=size[c[pos][i]];
	}size[pos]++;
}
inline int Lca(int x,int y){
	while(head[x]!=head[y]){
		if(dp[head[x]]<dp[head[y]]){
			y=f[head[y]];
		}else{
			x=f[head[x]];
		}
	}if(dp[x]<dp[y])return x;
	else return y;
}
void dfs(int pos,bool isbig){
	if(isbig)head[pos]=head[f[pos]];
	else head[pos]=pos;
	t[pos]=++num;
	ri mmax=0,mpos=0;
	F(i,0,c[pos].size()-1){
		if(size[c[pos][i]]>mmax){
			mpos=c[pos][i];
			mmax=size[c[pos][i]];
		}
	}big[pos]=mpos;
	if(c[pos].size())dfs(mpos,1);
	F(i,0,c[pos].size()-1)if(c[pos][i]!=mpos)dfs(c[pos][i],0);
}
int lca[202][202],dis[202][202],C[202][202],pw[202];
ll ans;
inline int fr(int x,int y){
	ri a,b,temp=dis[x][y],rt=0;
	F(i,1,n){
		temp=dis[x][i]+dis[y][i]-dis[x][y];
		temp>>=1;
		a=dis[x][i]-temp;
		b=dis[y][i]-temp;//cerr<<a<<' '<<b<<endl;
		rt=(rt+1ll*pw[a+b-1]*C[a+b-1][b])%mod;//cerr<<rt<<endl;
	}
	return rt;
}
inline long long pww(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pww(bot,mod-2))%mod;
}

int main(){
	root=1;pw[0]=1;
	F(i,1,200)pw[i]=1ll*pw[i-1]*(mod/2+1)%mod;
	F(i,0,200)C[i][0]=1;
	F(i,1,200)F(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	F(i,1,200)UF(j,i,0)C[i][j]=(C[i][j+1]+C[i][j])%mod;
    cin>>n;
    F(i,2,n){
    	t1=read(),t2=read();
    	g[t1].push_back(t2);
    	g[t2].push_back(t1);
	}make_tree(root);
	getsize(root);
	dfs(root,0);
	F(i,1,n)F(j,1,n){
		lca[i][j]=Lca(i,j);
		dis[i][j]=dp[i]+dp[j]-dp[lca[i][j]]*2;
	}
	F(i,1,n)F(j,i+1,n)ans+=fr(i,j);
	cout<<getm(ans%mod,n);
    return 0;
}