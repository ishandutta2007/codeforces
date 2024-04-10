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
//#include <random>
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
long long inv[1000002],now,ans;
int n,m,s[200002],t[200002],cnt[200002],c[200002];
inline void add(int pos,int v){
	while(pos<=200000){
		c[pos]+=v;
		pos+=(-pos&pos);
	}
}
inline int query(int pos){
	int rt=0;
	while(pos){
		rt+=c[pos];
		pos-=(-pos&pos);
	}
	return rt;
}
void init_inv(int n){
    inv[1] = 1;
    for(int i = 2;i <= n;i++)  inv[i] = (mod -  mod / i) * inv[mod % i] % mod;
}
int main() {
	cin>>n>>m;
	init_inv(n);
	F(i,1,n)read(s[i]);F(i,1,m)read(t[i]);
	if(m>n){
		++t[n];
		m=n;
	}ans=1;
	F(i,1,n){
		ans=1ll*ans*i%mod*inv[++cnt[s[i]]]%mod;
		add(s[i],1);
	}
	now=ans;ans=0;
	F(i,1,min(n,m)){
		int x=query(t[i]-1);
		ans+=1ll*x*inv[n-i+1]%mod*now%mod;
		if(cnt[t[i]]){
			add(t[i],-1);
			now=now*inv[n-i+1]%mod*(cnt[t[i]]--)%mod;
		}else break;
	}
	cout<<ans%mod;
	return 0;
}