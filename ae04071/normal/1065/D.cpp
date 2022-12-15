#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;
typedef pair<double,double> pdd;

inline int _abs(int a) {return a<0 ? -a : a;}
inline lli _abs(lli a) {return a<0 ? -a : a;}

const int inf=1e9;

int n,a[10][10],vis[100][10][10][3];
pii dp[101][10][10][3];

bool go(int y,int x)  {
	return y>=0 && x>=0 && y<n && x<n;
}
int tdy[]={-2,-2,-1,-1,1,1,2,2},tdx[]={-1,1,-2,2,-2,2,-1,1};


struct td{
	pii d;
	int v,i,j,s;
	td() {}
	td(pii d,int v,int i,int j,int s):d(d),v(v),i(i),j(j),s(s){}
	bool operator<(const td &rhs)const {
		return d.fi!=rhs.d.fi ? d.fi>rhs.d.fi : d.se > rhs.d.se;
	}
};
int cnt[3],dy[3][100],dx[3][100];
void make() {
	cnt[0] = 8;
	for(int i=0;i<8;i++) 
		dy[0][i]=tdy[i], dx[0][i]=tdx[i];

	for(int i=0;i<=n*2;i++){
		dy[1][i] = (i-n), dx[1][i]=i-n;
		cnt[1]++;
	}
	for(int i=0;i<=n*2;i++) {
		dy[1][i+2*n+1]=n-i, dx[1][i+2*n+1]=i-n;
		cnt[1]++;
	}

	for(int i=0;i<=n*2;i++){
		dy[2][i] = (i-n), dx[2][i]=0;
		cnt[2]++;
	}
	for(int i=0;i<=n*2;i++) {
		dy[2][i+2*n+1]=0, dx[2][i+2*n+1]=i-n;
		cnt[2]++;
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		scanf("%d",&a[i][j]);

	for(int i=1;i<=n*n;i++) for(int j=0;j<n;j++)for(int k=0;k<n;k++)
		for(int t=0;t<3;t++)
			dp[i][j][k][t] = pii(inf,inf);

	priority_queue<td> que;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j]==1) {
		dp[1][i][j][0]=dp[1][i][j][1]=dp[1][i][j][2]=pii(0,0);
		que.push(td(pii(0,0),1,i,j,0));
		que.push(td(pii(0,0),1,i,j,1));
		que.push(td(pii(0,0),1,i,j,2));
		break;
	}
	make();

	while(!que.empty()) {
		int v=que.top().v,i=que.top().i,j=que.top().j,s=que.top().s;
		que.pop();

		if(vis[v][i][j][s]) continue;
		vis[v][i][j][s] = 1;

		for(int t=0;t<3;t++) if(t!=s) {
			if(dp[v][i][j][t].fi > dp[v][i][j][s].fi+1 ||
				(dp[v][i][j][t].fi==dp[v][i][j][s].fi+1 && 
					dp[v][i][j][t].se > dp[v][i][j][s].se+1)) {
				dp[v][i][j][t] = dp[v][i][j][s];
				dp[v][i][j][t].se++;
				dp[v][i][j][t].fi++;
				que.push(td(dp[v][i][j][t],v,i,j,t));
			}
		}

		for(int k=0;k<cnt[s];k++) {
			int y=i+dy[s][k],x=j+dx[s][k];
			if(go(y,x)) {
				int nv=v;
				if(a[y][x]==v+1) nv++;
				if(dp[nv][y][x][s].fi > dp[v][i][j][s].fi+1 ||
				(dp[nv][y][x][s].fi==dp[v][i][j][s].fi+1 && 
					dp[nv][y][x][s].se > dp[v][i][j][s].se)) {
					dp[nv][y][x][s] = dp[v][i][j][s];
					dp[nv][y][x][s].fi++;
					que.push(td(dp[nv][y][x][s],nv,y,x,s));
				}
			}
		}
	}

	pii ans;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(a[i][j]==n*n){
		ans=  min({dp[n*n][i][j][0],dp[n*n][i][j][1],dp[n*n][i][j][2]});
	}
	printf("%d %d\n",ans.fi,ans.se);

	return 0;
}