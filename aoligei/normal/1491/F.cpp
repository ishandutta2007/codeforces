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
int n,t,ak,tak;
bool qwq[2002];
inline bool check(int pos) {
	cout<<"? "<<1<<' '<<n-pos<<'\n';
	F(i,pos,pos)printf("%d ",i);
	printf("\n");
	F(i,pos+1,n) {
		printf("%d ",i);
	}
	printf("\n");
	fflush(stdout);
	int temp;
	cin>>temp;
	return (temp!=0);
}
inline bool checkk(int l,int r) {
	cout<<"? 1 "<<r-l+1<<'\n';
	printf("%d\n",ak);
	F(i,l,r) {
		printf("%d ",i);
	}
	printf("\n");
	fflush(stdout);
	int temp;
	cin>>temp;
	return (temp!=0);
}
inline int solve(int pos) {
	int len=1,l=1;
	while(len<pos)len<<=1;
	len>>=1;
	for(ri i=len; i; i>>=1) {
		if(l+i<=pos&&!checkk(l,l+i-1)) {
			l+=i;
		}
	}
	return l%pos;
}
inline bool tql(int x,int y) {
	printf("? 1 1\n");
	printf("%d\n",x);
	printf("%d\n",y);
	fflush(stdout);
	int temp;
	cin>>temp;
	return (temp!=0);
}
#define vis qwq
inline void outpu() {
	printf("! ");
	ri ans=0;
	F(i,1,n)if(vis[i]==1)ans++;
	printf("%d ",ans);
	F(i,1,n)if(vis[i]==1)printf("%d ",i);
}
int main() {
	cin>>t;
	while(t--) {
		memset(qwq,0,sizeof(qwq));
		cin>>n;
		F(i,1,n) {
			if(check(i)) {
				ak=i;
				tak=solve(i);

				if(!tak) {
					F(j,1,i-1)vis[j]=1;
					F(j,i+1,n) {
						if(!tql(i,j))vis[j]=1;
					}
					outpu();
					
				} else {
					ri cnt=0;
					F(j,1,i-1)vis[j]=1,cnt++;
					vis[tak]=0;
					F(j,i+1,n-1) {
						if(!tql(i,j))vis[j]=1,cnt++;
					}
					if((n-cnt)&1)vis[n]=1;
					outpu();
				}goto orz;
			}
		}

orz:
		;
	}
	return 0;
}