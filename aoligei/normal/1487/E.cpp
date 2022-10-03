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
ll n1,n2,n3,n4,a[200002],b[200002],c[200002],d[200002],temp[200002];
vector<int>ban1[200002],ban2[200002],ban3[200002];
inline bool cmp1(int x,int y){
	return a[x]!=a[y]?a[x]<a[y]:x<y;
}inline bool cmp2(int x,int y){
	return b[x]!=b[y]?b[x]<b[y]:x<y;
}inline bool cmp3(int x,int y){
	return c[x]!=c[y]?c[x]<c[y]:x<y;
}
int main() {
	cin>>n1>>n2>>n3>>n4;
	F(i,1,n1)read(a[i]);a[0]=INT_MAX;
	F(i,1,n2)read(b[i]);b[0]=INT_MAX;
	F(i,1,n3)read(c[i]);c[0]=INT_MAX;
	F(i,1,n4)read(d[i]);d[0]=INT_MAX;
	F(i,1,read())ban1[read()].push_back(read());
	F(i,1,read())ban2[read()].push_back(read());
	F(i,1,read())ban3[read()].push_back(read());
	F(i,1,n1)temp[i]=i;
	sort(temp+1,temp+n1+1,cmp1);
	F(i,1,n2){
		if(ban1[i].size()>1)sort(ban1[i].begin(),ban1[i].end(),cmp1);
		ban1[i].push_back(998244353);
		F(j,1,n1+1){
			if(ban1[i][j-1]!=temp[j]){
				b[i]+=a[temp[j]];
				break;
			}
		}
	}F(i,1,n2)temp[i]=i;temp[n2+1]=0;
	sort(temp+1,temp+n2+1,cmp2);
	F(i,1,n3){
		if(ban2[i].size()>1)sort(ban2[i].begin(),ban2[i].end(),cmp2);
		ban2[i].push_back(998244353);
		F(j,1,n2+1){
			if(ban2[i][j-1]!=temp[j]){
				c[i]+=b[temp[j]];
				break;
			}
		}
	}F(i,1,n3)temp[i]=i;temp[n3+1]=0;
	sort(temp+1,temp+n3+1,cmp3);
	F(i,1,n4){
		if(ban3[i].size()>1)sort(ban3[i].begin(),ban3[i].end(),cmp3);
		ban3[i].push_back(998244353);
		F(j,1,n3+1){
			if(ban3[i][j-1]!=temp[j]){
				d[i]+=c[temp[j]];
				break;
			}
		}
	}if(*min_element(d+1,d+n4+1)<1e9)cout<<*min_element(d+1,d+n4+1);
	else puts("-1");
	return 0;
}