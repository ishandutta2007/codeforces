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
ll n,m,p[200002],k[200002],a[5000002],t[5000002],seed,base,tot[2],cut[5000002];
ll rnd() {
	ll ret = seed;
	seed = (seed * base + 233) % 1000000007;
	return ret;
}
int main() {
	cin>>n>>m;
	F(i,1,m) {
		read(p[i]);
		read(k[i]);
		read(seed);
		read(base);
		F(j,p[i-1]+1,p[i]) {
			t[j]=rnd()%2;
			a[j]=rnd()%k[i]+1;
			tot[t[j]]+=a[j];
		}
	}
	ri A;
	if(tot[t[1]]<=tot[!t[1]]) {
		A=t[1];
		ll cnt=0;
		F(ii,1,n+n) {
			ri i=ii;
			if(ii>n)i-=n;
			if(t[i]==A) {
				cnt+=a[i];
				cut[i]+=a[i];
				a[i]=0;
			} else {
				cut[i]+=min(cnt,a[i]);
				ll qwq=min(cnt,a[i]);
				cnt-=qwq;
				a[i]-=qwq;
			}
		}
	} else {
		A=!t[1];
		F(iakioi,1,1) {
			a[1]--;
			ri st=0;
			ll cnt=0;
			t[n+1]=A;
			F(i,1,n+1) {
				if(t[i]==A) {
					st=i;
					break;
				}
			}
			if(st>n)break;
			F(ii,1,n+n) {
				ri i=(st+ii-1);
				if(i>n)i-=n;
				if(i>n)i-=n;
				if(t[i]==A) {
					cnt+=a[i];
					cut[i]+=a[i];
					a[i]=0;
				} else {
					cut[i]+=min(cnt,a[i]);
					ll qwq=min(cnt,a[i]);
					cnt-=qwq;
					a[i]-=qwq;
				}
			}
		}
		cut[1]++;

	}
	ll ans=1;
#define mod 1000000007
	F(i,1,n) {
		ans=ans*((1ll*i*i^cut[i])%mod+1)%mod;
	}
	cout<<ans;

	return 0;
}