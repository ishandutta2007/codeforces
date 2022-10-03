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
int n,m,pos[200002],d[200002];bool ans[200002];
ll x[200002],y[200002];
struct pii{
	int first,second,id;
};
inline bool cmp(pii x,pii y){
	return x.first<y.first;
}
pii v[200002];
inline bool check(int a,int y){
	return x[y]-max(0,d[a]-abs(pos[a]-pos[y]))<=m;
}
int main() {
	F(dsaf,1,read()){
		F(i,0,n+1)x[i]=y[i]=0;
		read(n,m);
		F(i,1,n)read(v[i].first,v[i].second),v[i].id=i;
		sort(v+1,v+n+1,cmp);
		F(i,1,n)pos[i]=v[i].first,d[i]=v[i].second;
		F(i,1,n){
			x[i]+=-2;
			y[i]+=v[i].first+v[i].second;
			int nxt=lower_bound(pos+1,pos+n+1,pos[i]+d[i])-pos;
			x[nxt]++;
			y[nxt]-=v[i].first+v[i].second;
			int lst=lower_bound(pos+1,pos+n+1,pos[i]-d[i])-pos;
			x[lst]++;
			y[lst]-=pos[i]-d[i];
			y[i]+=pos[i]-d[i];
		}
		F(i,1,n)x[i]+=x[i-1],y[i]+=y[i-1];
		F(i,1,n)x[i]=1ll*x[i]*pos[i]+y[i];
		//cerr<<x[i]<<" ";cerr<<endl;
		ll flagl=-1e18,flagr=-1e18;
		int pl=0,pr=0;
		F(i,1,n)if(x[i]>m){
			if(x[i]-m-pos[i]>flagl)flagl=max(flagl,x[i]-m-pos[i]),pl=i;
			if(x[i]-m+pos[i]>flagr)flagr=max(flagr,x[i]-m+pos[i]),pr=i;
		}
		if(flagl==-1e18){
			F(i,1,n)putchar('1');
		}else{F(i,1,n)ans[i]=false;
			F(i,1,n){
				if(check(i,pl)&&check(i,pr))ans[v[i].id]=true;
			}F(i,1,n)putchar(ans[i]+'0');
		}
		putchar('\n');
	}
	return 0;
}