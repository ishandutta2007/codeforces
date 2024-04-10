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
int c[52][300002],pre[600002],N;
mt19937 rd(time(0)^(unsigned long long)new char);
bool vis[52][600002],siv[600002][52];
int n,q,a[300002],op[300002],t1[300002],t2[300002],t3[300002],b[600002],cnt;
inline void add(int *c,int pos,int v){
	while(pos<=n){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline ll query(int *c,int pos){
	ll rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
inline ll query(int *c,int l,int r){
	return query(c,r)-query(c,l-1);
}
inline void build(int pos){
	F(i,1,n)pre[i]=pre[i-1]+vis[pos][a[i]];
	F(i,1,n)c[pos][i]=pre[i]-pre[i-(-i&i)];
}
int main() {
	cin>>n>>q;N=n<<1;
	F(i,1,50)F(j,1,n+n)siv[j][i]=vis[i][j]=rd()&1;
	F(i,1,n)read(a[i]);cnt=n;memcpy(b,a,sizeof(a));
	F(i,1,q){
		read(op[i]);read(t1[i]);read(t2[i]);if(op[i]==2)read(t3[i]);else b[++cnt]=t2[i];
	}
	sort(b+1,b+cnt+1);
	cnt=unique(b+1,b+cnt+1)-b-1;
	F(i,1,n)a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	F(i,1,q)if(op[i]==1)t2[i]=lower_bound(b+1,b+cnt+1,t2[i])-b;
	F(i,1,50)build(i);
	F(i,1,q){
		if(op[i]==1){
			int pos=t1[i],v=t2[i];
			int lst=a[pos];a[pos]=v;
			F(j,1,50)if(siv[lst][j]!=siv[v][j])add(c[j],pos,siv[lst][j]?-1:1);
		}else{
			int l=t1[i],r=t2[i],k=t3[i];
			bool flag=true;
			F(j,1,50){
				if(query(c[j],l,r)%k){
					flag=false;
					puts("NO");
					break;
				}
			}
			if(flag)puts("YES");
		}
	//	F(ij,1,n)cerr<<a[ij]<<" ";cerr<<endl;
	}
	return 0;
}