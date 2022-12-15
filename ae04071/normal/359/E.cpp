#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <utility>
#include <queue>
#include <functional>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;

int n,arr[501][501],xx,yy;
pii dd[500][500][4];

const int dy[4]={-1,0,1,0},dx[4]={0,1,0,-1};
const char dc[4] = {'U', 'R', 'D', 'L'};
int vis[500][500];

string res;
void dfs(int y,int x) {
	vis[y][x]=1;
	if(!arr[y][x]) res.push_back('1');
	arr[y][x] = 1;
	
	for(int k=0;k<4;k++) if(dd[y][x][k].fi!=-1) {
		int yy=y+dy[k], xx=x+dx[k];
		if(yy<0 || xx<0 || yy>=n || xx>=n) continue;
		if(vis[yy][xx]) continue;
		if(vis[dd[y][x][k].fi][dd[y][x][k].se]) continue;
		res.push_back(dc[k]);
		dfs(yy,xx);
		res.push_back(dc[(k+2)%4]);
	}

	res.push_back('2');
	arr[y][x] = 0;
}

int main() {
	scanf("%d%d%d",&n,&yy,&xx);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);

	for(int i=0;i<n;i++) {
		int pr=-1;
		for(int j=0;j<n;j++) {
			if(pr==-1) dd[i][j][3] = pii(-1,-1);
			else dd[i][j][3] = pii(i,pr);
			if(arr[i][j]) pr=j;
		}
		pr=-1;
		for(int j=n-1;j>=0;j--) {
			if(pr==-1) dd[i][j][1] = pii(-1,-1);
			else dd[i][j][1] = pii(i,pr);
			if(arr[i][j]) pr=j;
		}
	}
	for(int j=0;j<n;j++) {
		int pr=-1;
		for(int i=0;i<n;i++) {
			if(pr==-1) dd[i][j][0] = pii(-1,-1);
			else dd[i][j][0] = pii(pr,j);
			if(arr[i][j]) pr=i;
		}
		pr=-1;
		for(int i=n-1;i>=0;i--) {
			if(pr==-1) dd[i][j][2] = pii(-1,-1);
			else dd[i][j][2] = pii(pr,j);
			if(arr[i][j]) pr=i;
		}
	}

	yy--; xx--;
	dfs(yy,xx);
	
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(arr[i][j]) {
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%s\n",res.c_str());
	
	return 0;
}