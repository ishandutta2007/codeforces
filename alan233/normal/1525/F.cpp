// naive problem
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long int_;
inline int readint(){
	int a = 0; char c = getchar(), f = 1;
	for(; c<'0'||c>'9'; c=getchar())
		if(c == '-') f = -f;
	for(; '0'<=c&&c<='9'; c=getchar())
		a = (a<<3)+(a<<1)+(c^48);
	return a*f;
}
inline void writeint(int_ x){
	if(x > 9) writeint(x/10);
	putchar((x-x/10*10)^48);
}
inline int ABS(const int &x){
	return x < 0 ? -x : x;
}

const int MaxN = 55;
const int_ infty = (1ll<<62)-1;

int match[MaxN<<1];
bool vis[MaxN<<1], zxy[MaxN<<1];
vector<int> g[MaxN<<1];
bool dfs(int x){
	if(vis[x] || zxy[x]) return false;
	else vis[x] = true;
	for(int y : g[x]) if(!zxy[y])
		if(!match[y] || dfs(match[y])){
			match[x] = y, match[y] = x;
			return true; // find mate
		}
	return false; // fail
}
bool fakeDfs(int x){
	if(vis[x] || zxy[x]) return false;
	else vis[x] = true;
	for(int y : g[x]) if(!zxy[y])
		if(!match[y] || fakeDfs(match[y]))
			return true; // don't change anything
	return false; // fail
}

long long dp[MaxN][MaxN];
int pre[MaxN][MaxN], n;
vector<int> ans;
void print(int x,int y){
	if(!x) return ;
	print(x-1,pre[x][y]);
	int t = pre[x][y]-y;
	for(int i=1; i<=n&&t; ++i)
		if(match[i]){
			int jb = match[i];
			memset(vis+1,0,sizeof(vis));
			zxy[jb] = true; // deleted
			if(!fakeDfs(i))
				ans.push_back(n-jb);
			else{
				ans.push_back(i);
				zxy[i] = true;
				zxy[jb] = false; // not deleted
			}
			match[i] = match[jb] = 0;
			-- t; // fucked one
		}
	ans.push_back(0);
}
int main(){
	n = readint();
	int m = readint(), k = readint();
	for(int i=1,a,b; i<=m; ++i){
		a = readint(), b = readint();
		g[a].push_back(b+n);
		g[b+n].push_back(a);
	}
	int cnt = 0;
	for(int i=1; i<=n; ++i)
		if(!match[i]){
			memset(vis+1,0,n<<1);
			if(dfs(i)) ++ cnt;
		}
	rep(i,0,n) rep(j,0,n)
		dp[i][j] = -infty;
	dp[0][cnt] = 0; // zero score
	rep(i,1,k){
		int x = readint(), y = readint();
		rep(j,0,n) rep(t,0,j)
			if(dp[i][j-t] < dp[i-1][j]+max(0ll,x-1ll*t*y)){
				dp[i][j-t] = dp[i-1][j]+max(0ll,x-1ll*t*y);
				pre[i][j-t] = j;
			}
		rep(j,n-i,n) dp[i][j] = -infty;
	}
	int id = 0;
	rep(j,0,n-k-1) if(dp[k][j] > dp[k][id]) id = j;
	print(k,id);
	int len = ans.size();
	printf("%d\n",len);
	for(int i=0; i<len; ++i)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}