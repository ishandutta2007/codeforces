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
int n,k,a[1002][1002],lst1[1002],lst2[1002],ans[1002][1002];
inline bool orz(){
	char ch=getchar();
	while(ch!='0'&&ch!='1')ch=getchar();
	return ch=='1';
}
inline void solve1(int x){
	lst1[x]=max(lst1[x-1],lst1[x+1]+1);
	while(lst1[x]<=n-x&&a[x+lst1[x]][lst1[x]]==false)++lst1[x];
	if(lst1[x]<=n-x)ans[x+lst1[x]][lst1[x]]=false;
}
inline void solve2(int x){
	lst2[x]=max(lst2[x-1],lst2[x+1]+1);
	while(lst2[x]<=n-x&&a[lst2[x]][x+lst2[x]]==false)++lst2[x];
	if(lst2[x]<=n-x)ans[lst2[x]][x+lst2[x]]=false;
}
int main() {
	F(asdf,1,read()){
		read(n,k);k=n-k+1;memset(lst1,0,sizeof(lst1));memset(lst2,0,sizeof(lst2));
		F(i,1,n)F(j,1,n)a[i][j]=orz(),ans[i][j]=true;
		F(t,1,k){
			UF(i,t-1,1){
				solve1(i);
				solve2(i);
			}
			solve1(0);
			solve2(0);
			ans[lst1[0]][lst1[0]]=true;
			ans[lst2[0]][lst2[0]]=true;
			lst1[0]=lst2[0]=max(lst1[0],lst2[0]);
			ans[lst1[0]][lst2[0]]=false;
		}
		if(*max_element(lst1,lst1+k)>n||*max_element(lst2,lst2+k)>n)puts("NO");
		else{
		puts("YES");
		F(i,1,n){
			F(j,1,n)putchar(ans[i][j]+'0');
			putchar('\n');
		}
		}
		
	}
	return 0;
}