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
#define vi vector<int>
#define ull unsigned long long
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
int n,q,l,r;
ll a[100002],mmax[400002];
ll pre[100002];
struct node{
	ll res,tag;
}orz[400002];
inline node merge(node x,node y){
	if(x.tag<=y.res){
		return node{x.res+y.res-x.tag,y.tag};
	}
	return node{x.res,x.tag+y.tag-y.res};
}
#define mid ((l+r)>>1)
inline void build(int pos,int l,int r){
	if(l==r){
		if(a[l]>0)orz[pos]=node{0,a[l]};
		else orz[pos]=node{-a[l],0};
		mmax[pos]=pre[l];
		return;
	}
	build(pos<<1,l,mid);build(pos<<1|1,mid+1,r);
	mmax[pos]=max(mmax[pos<<1],mmax[pos<<1|1]);
	orz[pos]=merge(orz[pos<<1],orz[pos<<1|1]);
}
inline ll querymax(int pos,int l,int r,int ql,int qr){
	if(l>qr||r<ql)return -LLONG_MAX;
	if(ql<=l&&qr>=r)return mmax[pos];
	return max(querymax(pos<<1,l,mid,ql,qr),querymax(pos<<1|1,mid+1,r,ql,qr));
}
inline node query(int pos,int l,int r,int ql,int qr){
	if(l>qr||r<ql)return node{0ll,0ll};
	if(ql<=l&&qr>=r)return orz[pos];
	return merge(query(pos<<1,l,mid,ql,qr),query(pos<<1|1,mid+1,r,ql,qr));
}
int main() {
	cin>>n>>q;
	F(i,1,n)read(a[i]);
	F(i,1,n)a[i]-=read();
	F(i,1,n)pre[i]=pre[i-1]+a[i];
	build(1,1,n);
	F(i,1,q){
		read(l);read(r);
		node temp=query(1,1,n,l,r);
		if(querymax(1,1,n,l,r)-pre[l-1]>0||pre[l-1]!=pre[r])puts("-1");
		else write(temp.res,'\n');
	}
	return 0;
}