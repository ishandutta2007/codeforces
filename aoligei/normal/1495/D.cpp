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
bitset<401>ak[402][402];
bool ed[402][402];
ll ans[402][402],dis[402][402],n,m,t1,t2;
int orz[402];
vector<int>g[402];
#define mod 998244353
queue<int>q;
bool vis[402];
inline void bfs(ri pos){
	vis[pos]=1;
	q.push(pos);
	while(!q.empty()){
		ri p=q.front();
		q.pop();
		F(i,0,g[p].size()-1){
			if(!vis[g[p][i]]){
				dis[pos][g[p][i]]=dis[pos][p]+1;
				vis[g[p][i]]=1;
				q.push(g[p][i]);
			}
		}
	}
}
int main() {
	cin>>n>>m;
	F(i,1,m){
		read(t1);read(t2);
		ed[t1][t2]=ed[t2][t1]=1;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
	}F(i,1,n)F(j,1,n)ans[i][j]=1;
	F(i,1,n){
		memset(vis,0,sizeof(vis));
		bfs(i);
	}
	F(i,1,n){
		F(j,1,n){
			F(k,1,n){
				if(dis[i][j]==dis[k][j]+1&&ed[i][k])ak[i][j][k]=1;
			}
		}
	}
	F(i,1,n){
		F(j,i,n){
			ri d=dis[i][j];
			memset(orz,0,sizeof(orz));memset(vis,0,sizeof(vis));
			orz[0]=i;orz[d]=j;vis[i]=vis[j]=1;
			F(k,1,n){
				if(k!=i&&k!=j)if(dis[i][k]+dis[j][k]==dis[i][j]){
					if(!orz[dis[i][k]]){
						orz[dis[i][k]]=k;
						vis[k]=1;
					}else{
						ans[i][j]=0;
						goto nxt;
					}
				}
			}
			F(ii,1,d){
				if(!ed[orz[ii]][orz[ii-1]]){
					ans[i][j]=0;
					goto nxt;
				}
			}
			F(k,1,n)if(!vis[k]){
				ans[i][j]=ans[i][j]*(ak[k][i]&ak[k][j]).count()%mod;
			}
			nxt:;
		}
	}
	F(i,1,n)F(j,1,i-1)ans[i][j]=ans[j][i];
	F(i,1,n){
		F(j,1,n){
			write(ans[i][j],' ');
		}putchar('\n');
	}
	return 0;
}