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
	template<class T,class... Args>
	inline void read(T& t,Args&... args) {
		read(t);
		read(args...);
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
#define uint unsigned int
namespace getrd{
	uint seed=114514;
	inline uint rd(){
		seed^=(seed<<13);
		seed^=(seed>>17);
		seed^=(seed<<5);
		return seed;
	}
}
using getrd::rd;
struct S{
	int l,r;
	inline bool operator<(const S &b){
		return l<b.l;
	}
	inline int len(){
		return r-l+1;
	}
};
uint pri[1000002];
int lc[1000002],rc[1000002],sz[1000002],root,cnt;
S v[1000002];
inline int new_node(S vv){
	v[++cnt]=vv;
	sz[cnt]=vv.len();
	pri[cnt]=rd();
	return cnt;
}
struct pii{
	int a,b;
};
#define update(pos) sz[pos]=sz[lc[pos]]+sz[rc[pos]]+v[pos].len()
inline pii cut(int x,int s){
	if(!s)return pii{0,x};
	if(s==v[x].len())return pii{x,0};
	int temp=new_node(v[x]);
	v[x].r=v[x].l+s-1;
	v[temp].l+=s;
	return pii{x,temp};
}
inline pii split(int pos,int s){
	if(!pos)return pii{0,0};
	if(s>=sz[lc[pos]]+v[pos].len()){
		pii temp=split(rc[pos],s-(sz[lc[pos]]+v[pos].len()));
		rc[pos]=temp.a;
		update(pos);
		return pii{pos,temp.b};
	}else if(s<=sz[lc[pos]]){
		pii temp=split(lc[pos],s);
		lc[pos]=temp.b;
		update(pos);
		return pii{temp.a,pos};
	}else{
		int qwql=lc[pos],qwqr=rc[pos];
		pii temp=cut(pos,s-sz[lc[pos]]);
		lc[temp.a]=qwql;
		rc[temp.a]=0;
		rc[temp.b]=qwqr;
		lc[temp.b]=0;
		update(temp.a);update(temp.b);
		return temp;
	}
}
inline int merge(int x,int y){
	if(!x||!y)return x|y;
	if(pri[x]>pri[y]){
		rc[x]=merge(rc[x],y);
		update(x);
		return x;
	}else{
		lc[y]=merge(x,lc[y]);
		update(y);
		return y;
	}
}
inline void insert(S x,int s){
	pii temp=split(root,s-1);
	root=merge(merge(temp.a,new_node(x)),temp.b);
}
vector<S>vec;
inline void dfs(int pos){
	if(!pos)return;
	dfs(lc[pos]);
	vec.push_back(v[pos]);
	dfs(rc[pos]);
}
int n,m,x,y,lstx;
#define mod 998244353
namespace getinv{
#define n 1000000
long long fac[1000002],ifac[1000002],inv[1000002];
inline long long pw(long long x,long long p){
    long long res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1)res=res*x%mod;
    return res;
}
inline long long getm(long long top,long long bot) {
	return (top*pw(bot,mod-2))%mod;
}
inline long long C(long long top,long long bot){
	if(top<bot||top<0||bot<0)return 0;
	return fac[top]*ifac[bot]%mod*ifac[top-bot]%mod;
}
int main() {
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	ifac[n]=getm(1,fac[n]);
	UF(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%mod;
	F(i,1,n)inv[i]=ifac[i]*fac[i-1]%mod;
	return 0;
}
#undef n
}
int main() {
	getinv::main();
	F(qwq,1,read()){
		read(n);
		read(m);
		root=0;
		vec.clear();
		lstx=0;
		F(i,1,m){
			read(x);read(y);
			if(lstx<x-1)insert(S{lstx+1,x-1},sz[root]+1);
			lstx=x;
			insert(S{x,x},y);
			//cerr<<x<<' '<<sz[root]<<endl;
		}
		if(lstx<n)insert(S{lstx+1,n},sz[root]+1);
		dfs(root);
		int szz=vec.size();x=0;
		for(register int i=0;i+1<szz;++i)x+=(vec[i+1]<vec[i]);//for(auto i:vec)cerr<<i.l<<' '<<i.r<<endl;
		write(getinv::C(2*n-1-x,n-1-x),'\n');//cerr<<x<<endl;
		//cerr<<sz[root]<<endl;
	}
	return 0;
}