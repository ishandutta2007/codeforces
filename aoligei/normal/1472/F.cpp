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
int n,m;
map<int,char>mp;
bool solve(){
	ri t1=0,t2=0;
	for(auto i=mp.begin();i!=mp.end();++i){
		if(i->second==3){
			if(t1==t2){
				t1=t2=i->first;
			}else{
				return 0;
			}
		}else if(i->second==1){
			if(t1==t2){
				t1=t2=i->first-1;
				t1++;
			}else{
				t2+=(i->first-t2)/2*2;
				if((i->first-t1)%2){
					t1+=(i->first-t1)/2*2;
					t1++;
				}else return 0;
			}
		}else{
			if(t1==t2){
				t1=t2=i->first-1;
				t2++;
			}else{
				t1+=(i->first-t1)/2*2;
				if((i->first-t2)%2){
					t2+=(i->first-t2)/2*2;
					t2++;
				}else return 0;
			}
		}
	}
	if(t1==t2&&t1<=n&&t2<=n)
	return 1;
	else return 0;
}
int main() {
F(qwq,1,read()){mp.clear();
	read(n),read(m);
	F(i,1,m){
		ri t2=read(),t1=read();
		mp[t1]|=t2;
	}if(solve())puts("yes");else puts("no");
}
	return 0;
}