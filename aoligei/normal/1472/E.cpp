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
struct orz{
	int h,w,pos;
}a[200002];
itn n,ans[200002];
bool cmp(orz x,orz y){
	return x.h<y.h;
}
bool check(){
	F(i,2,n){
		if(a[i].w>a[i-1].w&&a[i].h>a[i-1].h);
		else return 0;
	}return 1;
}
int main() {
F(qwq,1,read()){
	read(n);
	F(i,1,n){
		a[i].h=read();
		a[i].w=read();
		a[i].pos=i;
		if(a[i].h>a[i].w)swap(a[i].h,a[i].w);
	}sort(a+1,a+n+1,cmp);
	ri lst=0,mmin=INT_MAX,pos;
	F(i,1,n){
		while(lst<n&&a[lst+1].h<a[i].h){
			lst++;
			if(a[lst].w<mmin)mmin=a[lst].w,pos=a[lst].pos;
		}if(mmin<a[i].w){
			ans[a[i].pos]=pos;
		}else ans[a[i].pos]=-1;
	}F(i,1,n)write(ans[i],' ');putchar('\n');
}
	return 0;
}