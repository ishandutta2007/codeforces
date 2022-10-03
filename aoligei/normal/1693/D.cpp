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
int n;
#define a p
struct T{
	int p[200002],ans[200002],sta[200002],f[200002],g[200002],cnt;pii x[200002],y[200002];int c[200002];
	inline bool cmp(int x,int y){
		return f[x]>f[y];
	}
	inline bool cmp2(int x,int y){
		return g[x]>g[y];
	}
	inline void add(int pos){
		int v=n-a[pos]+1;
		while(v<=n){
			c[v]=min(c[v],pos);
			v+=(-v&v);
		}
	}
	inline int query(int pos){
		pos=n-a[pos]+1;
		int rt=n+1;
		while(pos){
			rt=min(rt,c[pos]);
			pos-=(-pos&pos);
		}
		return rt;
	}
	void main(){
		memset(c,0x3f,sizeof(c));
		F(i,1,n){
			while(cnt&&p[sta[cnt]]<p[i])--cnt;
			g[i]=sta[cnt];
			sta[++cnt]=i;
		}
	//	F(i,1,n)g[i]=max(g[i],g[i-1]);
		cnt=0;
		f[n+1]=n+1;
		int now=n;
		sta[0]=n+1;
		UF(i,n,1){
			while(cnt&&p[sta[cnt]]>p[i])--cnt;
			f[i]=sta[cnt];
			sta[++cnt]=i;
		}
		F(i,1,n)x[i]={f[i],i},y[i]={g[i],i};
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		UF(i,n,1){
			while(now&&g[y[now].second]>f[x[i].second])add(y[now--].second);//cerr<<y[now+1].second<<" "<<query(5)<<endl;
			ans[x[i].second]=query(x[i].second);//cerr<<x[i].second<<endl;
		}
		ans[n+1]=n+1;//;F(i,1,n)cerr<<f[i]<<" "<<g[i]<<" "<<ans[i]<<endl;
		UF(i,n,1)ans[i]=min(ans[i],ans[i+1]);
	}
}A,B;
int main() {
	cin>>n;
	F(i,1,n)read(A.p[i]),B.p[i]=n-A.p[i]+1;B.main(),A.main();
//	A.main(),B.main();
	ll rt=0;
	F(i,1,n)rt+=min(A.ans[i],B.ans[i])-i;
	cout<<rt;
	return 0;
}