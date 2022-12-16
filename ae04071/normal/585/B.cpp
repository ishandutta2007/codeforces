#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

char str[3][110];
int vis[3][110];
int n=3,m,k;
bool endf;

const int dy[]={-1,1,0},dx[]={0,0,0};

bool go(int y,int x) {
	return y>=0 && x>=0 && y<n && x<m && !isupper(str[y][x]);
}
bool canGo(int d,int y,int x,pii &res) {
	x+=1;
	if(!go(y,x)) {
		if(x==m) endf=true;
		return false;
	}
	y+=dy[d],x+=dx[d];
	if(!go(y,x)) {
		if(x==m) endf=true;
		return false;
	}
	x+=1;
	if(!go(y,x)) {
		if(x==m) endf=true;
		return false;
	}
	x+=1;
	if(!go(y,x)) {
		if(x==m) endf=true;
		return false;
	}
	res = pii(y,x);
	return true;
}

bool bfs(int sy,int sx) {
	memset(vis,0,sizeof(vis));
	endf=false;

	queue<pii> que;
	que.push(pii(sy,sx));
	vis[sy][sx]=0;
	while(!que.empty()) {
		int y=que.front().fi, x=que.front().se;
		que.pop();
		for(int k=0;k<3;k++) {
			pii pos;
			if(canGo(k,y,x,pos) && !vis[pos.fi][pos.se]) {
				vis[pos.fi][pos.se]=1;
				que.push(pos);
			}
		}
	}

	return endf;
}

int main() {
	int test;
	scanf("%d",&test);
	while(test--) {
		scanf("%d%d",&m,&k);
		for(int i=0;i<n;i++) scanf("%s",str[i]);
		
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(str[i][j]=='s') {
			puts(bfs(i,j) ? "YES" : "NO");
		}
	}
	return 0;
}