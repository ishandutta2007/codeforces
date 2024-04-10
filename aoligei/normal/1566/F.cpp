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
#define int long long
#define re register
#define ri re int
#define il inline
#define pii pair<int,int>
#define cp complex<double>
#define vi vector<int>
#define ull unsigned long long
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
int n,m,a[200002],cnt,tot,L[200002],R[200002],dp[200002][3][3],f[200002][3];
pii b[200002],sta[200002];
vector<pii >seg[200002];
#define l first
#define r second
signed main() {
	F(iakioi,1,read()){
		cnt=tot=0;
		cin>>n>>m;
		F(i,0,max(n,m)+1)dp[i][1][1]=dp[i][1][2]=dp[i][2][1]=dp[i][2][2]=f[i][1]=f[i][2]=0,b[i]=sta[i]=make_pair(0,0),seg[i].clear();
		F(i,1,n)read(a[i]);
		sort(a+1,a+n+1);
		F(i,1,m)read(b[i].l),read(b[i].r);
		sort(b+1,b+m+1);
		F(i,1,m){
			while(cnt){
				if(sta[cnt].l<=b[i].l&&sta[cnt].r>=b[i].r)--cnt;
				else if(sta[cnt].l>=b[i].l&&sta[cnt].r<=b[i].r)goto hail;
				else break;
			}
			sta[++cnt]=b[i];
			hail:;
		}
		m=0;int p=1;a[n+1]=1e18;
		F(i,1,cnt){
			while(sta[i].l>a[p]&&p<=n)++p;
			if(sta[i].r<a[p])b[++m]=sta[i];
		}
		p=0;
		bool tag=0;
		a[0]=-1e18;
		F(i,1,m){
			while(b[i].l>a[p]){
				if(!tag){
					++tot;
					L[tot]=a[p];
					R[tot]=a[p];
					tag=1;
				}else R[tot]=a[p];
				++p;
			}
			tag=0;
			seg[tot].push_back(b[i]);
		}
		++tot;
		L[tot]=a[p];
		R[tot]=a[n+1];
		F(i,1,tot-1){//cerr<<L[i]<<' '<<R[i]<<'\n';for(auto j:seg[i])printf("   "),write(j.l,' '),write(j.r,'\n');
			dp[i][1][1]=min(seg[i].back().l-R[i],L[i+1]-seg[i].front().r);
			for(int j=0;j+1<seg[i].size();++j)dp[i][1][1]=min(dp[i][1][1],seg[i][j].l-R[i]+L[i+1]-seg[i][j+1].r);
			dp[i][1][2]=min(seg[i].back().l-R[i],L[i+1]-seg[i].front().r<<1);
			for(int j=0;j+1<seg[i].size();++j)dp[i][1][2]=min(dp[i][1][2],seg[i][j].l-R[i]+(L[i+1]-seg[i][j+1].r<<1));
			dp[i][2][1]=min(seg[i].back().l-R[i]<<1,L[i+1]-seg[i].front().r);
			for(int j=0;j+1<seg[i].size();++j)dp[i][2][1]=min(dp[i][2][1],(seg[i][j].l-R[i]<<1)+L[i+1]-seg[i][j+1].r);
			dp[i][2][2]=dp[i][1][1]*2;
		}//cerr<<L[tot]<<' '<<R[tot]<<endl;
		f[1][2]=0;
		f[1][1]=1e18;
		F(i,2,tot){
			if(L[i]!=R[i]){
				f[i][2]=min(f[i-1][1]+dp[i-1][2][1],f[i-1][2]+dp[i-1][1][1]);
				f[i][1]=1e18;
			}else{
				f[i][2]=min(f[i-1][1]+dp[i-1][2][2],f[i-1][2]+dp[i-1][1][2]);
				f[i][1]=min(f[i-1][1]+dp[i-1][2][1],f[i-1][2]+dp[i-1][1][1]);
			}//cerr<<i<<"  "<<f[i][1]<<" "<<f[i][2]<<endl;
		}
		write(min(f[tot][1],f[tot][2]),'\n');
	}
	return 0;
}
/*
1
4 11
2 6 14 18
0 3
4 5
11 15
3 5
10 13
16 16
1 4
8 12
17 19
7 13
14 19
*/