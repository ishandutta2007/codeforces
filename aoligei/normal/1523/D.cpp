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
		if(x==0) {
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
int n,m,p,pos,cnt[200002],can[200002][17],NOW,ccnt;
char c[200002][62];
bitset<200002>bit[62];
bool ok;
int sc,ans;
ll res;
bitset<200002>sta[62];
inline void dfs(int pos,int cnt,ll S) {
	if(sta[sc].count()<(n+1>>1)) {
		--sc;
		return;
	}else if(ans<cnt){
		res=S;ans=cnt;
	}if(pos==ccnt){
		--sc;return;
	}
	sta[sc+1]=sta[sc];
	++sc;
	dfs(pos+1,cnt,S);
	sta[sc+1]&=bit[can[NOW][pos]];
	++sc;
	dfs(pos+1,cnt+1,S|(1ll<<(ll)can[NOW][pos]));
	--sc;
}
int main() {
	srand(time(0));
	cin>>n>>m>>p;
	F(i,1,n) {
		scanf("%s",c[i]+1);
		F(j,1,m)if(c[i][j]=='1')bit[j][i]=1,can[i][cnt[i]++]=j;
	}
	F(i,1,m)if(bit[i].count()>=(n+1)/2) {
		ok=1;
	}
	if(!ok) {
		F(i,1,m)cout<<0;
		return 0;
	}
	res=0;
	F(i,1,m)
	while(1.0*clock()/CLOCKS_PER_SEC<=2.4) {
		pos=(1ll*rand()*RAND_MAX+rand())%n+1;
		sc=0;
		NOW=pos;ccnt=cnt[pos];
		sta[0].set();
		dfs(0,0,0);
	}F(i,1,m)cout<<(res>>i&1);
	return 0;
}