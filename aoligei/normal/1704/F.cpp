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
int n,sg[500002];
char a[500002];
bool vis[5002];
vi vec;
int main() {
	
	F(i,2,1000){
		memset(vis,0,sizeof(vis));
		F(j,1,i-1){
			vis[sg[j-1]^sg[i-j-1]]=true;
		}
		F(j,0,5001)if(!vis[j]){
			sg[i]=j;
			break;
		}
	//	if(i>34)if(sg[i]!=sg[i-34])cerr<<i<<" ",cerr<<sg[i]<<" "<<sg[i-34]<<endl;
	}
	F(i,1001,500000)sg[i]=sg[i-34];
	F(dsaf,1,read()){
		read(n);
		scanf("%s",a+1);
		int x=0,y=0;
		F(i,1,n-1){
			if(a[i]=='R')++x;
			else ++y;
		}if(a[n]=='R')++x;
			else ++y;
		if(x>y)puts("Alice");
		else if(x<y)puts("Bob");
		else{
			int s=0;
			for(int l=1,r;l<=n;l=r+1){
				r=l;
				while(r<n&&a[r+1]!=a[r])++r;
				s^=sg[r-l+1];
			}
			if(s)puts("Alice");
			else puts("Bob");
		}
	}
	return 0;
}