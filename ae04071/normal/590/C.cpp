#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii=pair<int,int>;
using lli = long long;

const int inf=1e9;

int n,m;
char str[1000][1001];
int vis[1000][1000][8],dist[1000][1000][8];

struct td{
	int c,y,x,s;
	td(){}
	td(int c,int y,int x,int s):c(c),y(y),x(x),s(s) {}
	bool operator<(const td &rhs)const {
		return c>rhs.c;
	}
};

inline bool go(int y,int x) {
	return y>=0 && x>=0 && y<n && x<m && str[y][x]!='#';
}
inline int get(char ch) {return 1<<(ch-'1');}
const int dy[]={-1,1,0,0},dx[]={0,0,-1,1};
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	
	priority_queue<td> que;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++) if(str[i][j]!='#') {
		for(int k=1;k<8;k++) dist[i][j][k]=inf;
		if(isdigit(str[i][j])) {
			dist[i][j][get(str[i][j])] = 0;
			que.push(td(0,i,j,get(str[i][j])));
		}
	}

	while(!que.empty()) {
		int y=que.top().y,x=que.top().x, s=que.top().s,c=que.top().c;
		que.pop();
		if(vis[y][x][s]) continue;
		vis[y][x][s]=1;
		if(s==7) continue;
		for(int k=0;k<4;k++) {
			int ny=y+dy[k], nx=x+dx[k];
			if(go(ny,nx)) {
				for(int t=6,ts=s;t>=0;--t,ts=t|s) {
					int nc = (t!=0) ? c : c+1;
					//if(ny==2 && nx==1) printf("%d %d %d, %d %d %d, %d %d %d %d\n",y,x,s, ny,nx,t, ts, dist[ny][nx][ts],dist[ny][nx][t],nc);
					if(ts != t && dist[ny][nx][ts] > dist[ny][nx][t]+nc) {
						dist[ny][nx][ts] = dist[ny][nx][t]+nc;
						que.push(td(dist[ny][nx][ts], ny,nx,ts));
					}
				}
			}
		}
	}

	int ans=inf;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(go(i,j)) ans=min(ans,dist[i][j][7]);
	if(ans==inf) ans=-1;
	printf("%d\n",ans);

	return 0;
}