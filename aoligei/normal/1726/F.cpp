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
ll n,t,d[200002],l[200002],r[200002],f[200002];
int v[1600002],mmin[1600002],p[500002],cnt;
#define mid ((l+r)>>1)
ll dis(ll x,ll y){
	if(x<=y)return y-x;
	else return y+t-x;
}
inline bool in(int x,int pos){
	if(l[pos]<=r[pos])return x>=l[pos]&&x<=r[pos];
	else return x>=l[pos]||x<=r[pos];
}
inline void pd(int pos){
	if(v[pos]){
		v[pos<<1]=v[pos<<1|1]=mmin[pos<<1]=mmin[pos<<1|1]=v[pos];
		v[pos]=0;
	}
}
inline void pu(int pos){
	mmin[pos]=max(mmin[pos<<1],mmin[pos<<1|1]);
}
inline void add(int pos,int l,int r,int ql,int qr,int w){
	if(ql>r||qr<l)return;
	if(ql<=l&&qr>=r){
		v[pos]=w;
		mmin[pos]=w;
		return;
	}
	pd(pos);
	if(ql<=mid)add(pos<<1,l,mid,ql,qr,w);
	if(qr>mid)add(pos<<1|1,mid+1,r,ql,qr,w);
	pu(pos);
}
inline int query(int pos,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r)return mmin[pos];
	if(ql>r||qr<l)return 0;
	pd(pos);
	int ans=INT_MAX;
	if(ql<=mid)ans=min(ans,query(pos<<1,l,mid,ql,qr));
	if(qr>mid)ans=min(ans,query(pos<<1|1,mid+1,r,ql,qr));
	return ans;
}
inline int id(int x){
	return lower_bound(p+1,p+cnt+1,x)-p;
}
inline int query(int x){
	if(l[x]<=r[x])return query(1,1,cnt,id(l[x]),id(r[x]));
	else{
		return min(query(1,1,cnt,id(l[x]),id(t-1)),query(1,1,cnt,id(0),id(r[x])));
	}
}
inline void add(int x){
	if(l[x]<=r[x])add(1,1,cnt,1,id(l[x])-1,x),add(1,1,cnt,id(r[x])+1,cnt,x);
	else{
		add(1,1,cnt,id(r[x])+1,id(l[x])-1,x);
	}
}
inline int diss(int x,int y){
	x=p[x],y=p[y];
	return dis(x,y);
}
inline int calcmax(int pos,int l,int r,int p){
	if(mmin[pos]<=n)return INT_MAX;
	if(l==r)return (l<=p)?diss(l,p):INT_MAX;
	if(p<=mid)return calcmax(pos<<1,l,mid,p);
	else{
		int res=calcmax(pos<<1|1,mid+1,r,p);
		if(res<=1e9)return res;
		else return calcmax(pos<<1,l,mid,p);
	}
}
inline int calcmax(int p){
	int res=calcmax(1,1,cnt,id(p));
	if(res<=1e9)return res;
	return calcmax(1,1,cnt,cnt)+p+1;
}
int main() {
	memset(mmin,0x3f,sizeof(mmin));
	cin>>n>>t;
	F(i,1,n)read(r[i],l[i]),l[i]=-l[i],r[i]+=l[i]-1;
	F(i,2,n)d[i]=d[i-1]+read(),r[i]-=d[i],l[i]-=d[i];
	F(i,1,n)l[i]=(l[i]%t+t)%t,r[i]=(r[i]%t+t)%t;//cerr<<l[i]<<" "<<r[i]<<endl;
	p[cnt=1]=0;p[cnt=2]=t-1;
	F(i,1,n)p[++cnt]=l[i],p[++cnt]=r[i];
	sort(p+1,p+cnt+1);
	cnt=unique(p+1,p+cnt+1)-p-1;
	UF(i,n,1){
		int nxt=query(1,1,cnt,id(l[i]),id(l[i]));
		if(nxt<=n)f[i]=f[nxt]+dis(l[i],l[nxt]);
		add(i);
	}
	memset(mmin,0x3f,sizeof(mmin));
	ll ans=LLONG_MAX;//F(i,1,n)cerr<<f[i]<<" ";
	F(i,1,n){
		ans=min(ans,calcmax(l[i])+f[i]);
		add(i);
		if(mmin[1]<=n)break;
	}
	if(mmin[1]>n)write(d[n]);
	else write(d[n]+ans);
	return 0;
}