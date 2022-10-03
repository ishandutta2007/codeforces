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
int n,x[6001],y[6001];
ll ans;
bool orz[6001][6001];
#define ull unsigned long long
ull bit[6001][105];
inline int getorz(int x,int y){
	int pos=y+1;
	int rt=__builtin_popcountll((bit[x][pos>>6]>>(pos&63ull))^(bit[y][pos>>6]>>(pos&63ull)));
	for(int i=(pos>>6)+1;i<=93;i+=8){
		rt+=__builtin_popcountll(bit[x][i]^bit[y][i]);
		rt+=__builtin_popcountll(bit[x][i+1]^bit[y][i+1]);
		rt+=__builtin_popcountll(bit[x][i+2]^bit[y][i+2]);
		rt+=__builtin_popcountll(bit[x][i+3]^bit[y][i+3]);
		rt+=__builtin_popcountll(bit[x][i+4]^bit[y][i+4]);
		rt+=__builtin_popcountll(bit[x][i+5]^bit[y][i+5]);
		rt+=__builtin_popcountll(bit[x][i+6]^bit[y][i+6]);
		rt+=__builtin_popcountll(bit[x][i+7]^bit[y][i+7]);
	}
	return rt;
}
int main() {
	cin>>n;
	F(i,1,n)read(x[i],y[i]),x[i]>>=1,y[i]>>=1;
	F(i,1,n)F(j,i+1,n){
		orz[i][j]=((x[i]-x[j]&1)&&(y[i]-y[j]&1));
		if(orz[i][j])bit[i][j>>6]|=(1ull<<(j&63ull));
	}
	F(i,1,n-1){
	F(j,i+1,n-1){
		int tot=getorz(i,j);
		if(orz[i][j]){
			ans+=tot;
		}
		else ans+=n-j-tot;
	}}
	cout<<ans;
	return 0;
}