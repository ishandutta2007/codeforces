#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;

int n,vis[1010][1010];
pii a,b,c;
int _abs(int a){ return a<0 ? -a : a;}
bool dfs(int y,int x) {
	if(y==c.fi && x==c.se) return true;

	if(vis[y][x]) return false;

	const int dy[]={-1,-1,-1,0,0,1,1,1},dx[]={-1,0,1,-1,1,-1,0,1};
	vis[y][x] = 1;
	for(int k=0;k<8;k++) {
		int yy=y+dy[k],xx=x+dx[k];
		if(yy>=1 && xx>=1 && yy<=n && xx<=n) {
			if(dfs(yy,xx)) return true;
		}
	}
	return false;
}
int main() {
	scanf("%d",&n);
	scanf("%d%d%d%d%d%d",&a.fi,&a.se,&b.fi,&b.se,&c.fi,&c.se);

	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		int dy=_abs(a.fi-i),dx=_abs(a.se-j);
		if(dy==0 || dx==0 || dy==dx) vis[i][j]=2;
	}

	puts(dfs(b.fi,b.se) ? "YES" : "NO");

	return 0;
}