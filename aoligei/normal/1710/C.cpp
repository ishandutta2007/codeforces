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
#define mod 998244353
char s[200002];
int n,dp[200002][2][2][2][2][2][2];
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	F(i,1,n)s[i]-='0';
	dp[0][0][0][0][0][0][0]=1;
	F(i,1,n){
		F(a,0,1)F(b,0,1)F(c,0,1)F(x,0,1)F(y,0,1)F(z,0,1){
			int v=dp[i-1][a][b][c][x][y][z];//if(v)cerr<<i-1<<" "<<a<<' '<<b<<" "<<c<<" "<<x<<" "<<y<<" "<<z<<" "<<v<<endl;
			F(p1,0,a||s[i])F(p2,0,b||s[i])F(p3,0,c||s[i]){
				int na=(s[i]&&!p1),nb=(s[i]&&!p2),nc=(s[i]&&!p3);
				(dp[i][na|a][nb|b][nc|c][x|(p1!=p2&&p1!=p3)][y|(p2!=p1&&p2!=p3)][z|(p3!=p1&&p3!=p2)]+=v)%=mod;
			}
		}
	}
	ll ans=0;
	F(a,0,1)F(b,0,1)F(c,0,1)F(x,1,1)F(y,1,1)F(z,1,1)ans+=dp[n][a][b][c][x][y][z];
	cout<<ans%mod;
	return 0;
}