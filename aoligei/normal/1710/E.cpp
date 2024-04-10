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
using namespace std;
int n, m, a[200010], b[200010], qwq, qaq, c[200010];
ll sum[200010];
inline bool check(int mid) {
	ll mx = 0;
	bool flag = 0;
	for (int i = 1, j = m; i <= n; i++) {
		while (j && a[i] + b[j] > mid) j--;
		c[i] = j;
		sum[i] = sum[i - 1] + j;
	}
	for (int i = m, j = 0, pos = n; i >= 1; i--) {
		while (pos && c[pos] < m - i) --pos;
		ll tmp = sum[pos] - 1ll * (m - i) * pos;
		tmp -= 1ll * i * (n - j) - (sum[n] - sum[j]);
		if (mx < tmp)
			mx = tmp, flag = 0;
		if (mx == tmp)
			flag |= (qaq <= i || qwq <= pos);
		while (j < n && c[j + 1] == i) j++;
	}
	return flag;
}
int main() {
	n = read(), m = read();
	qwq = 1, qaq = 1;
	F(i, 1, n) a[i] = read(), qwq += a[i] < a[1];
	F(i, 1, m) b[i] = read(), qaq += b[i] < b[1];
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
	int l = 0, r = a[qwq] + b[qaq], mid;
	while (l < r) {
		mid=(l+r)>>1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	write(l);
	return 0;
}