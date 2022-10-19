#include<bits/stdc++.h>
#define ll long long
#define N 1015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,k;
int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
int val[N*N],fa[N*N],siz[N*N];
char s[N][N];
bool check(int x,int y){
	return (x <= n) && (x > 0) && (y > 0) && (y <= m);
}
inline int id(int x,int y){
	return (x-1)*m + y;
}
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
void uni(int u,int v){
	u = find(u);v = find(v);
	if(u == v) return;
	if(siz[u] < siz[v]) swap(u,v);
	fa[v] = u; siz[u] += siz[v]; val[u] += val[v];
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d%d",&n,&m,&k);
 	rep(i,1,n) rep(j,1,m) fa[id(i,j)] = id(i,j),siz[id(i,j)] = 1;
 	rep(i,1,n)
 		scanf("%s",s[i]+1);
 	rep(i,1,n) rep(j,1,m){
 		if(s[i][j] == '*') continue;
 		rep(d,0,3){
 			int ti = i+dx[d],tj = j+dy[d];
 			if(!check(ti,tj)) continue;
 			val[id(i,j)] += s[ti][tj] == '*';
 		}
 	}
 	rep(i,1,n) rep(j,1,m){
 		if(s[i][j] == '*') continue;
 		rep(d,0,3){
 			int ti = i+dx[d],tj = j+dy[d];
 			if(!check(ti,tj)) continue;
 			if(s[ti][tj] == '.'){
 				uni(id(i,j),id(ti,tj));
 			}
 		}
 	}
 	while(k--){
 		int x,y; scanf("%d%d",&x,&y);
 		printf("%d\n",val[find(id(x,y))]);
 	}
	return 0;
}