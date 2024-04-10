#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int,int> ip;
const int dy[4]={1,-1,0,0},dx[4]={0,0,-1,1};

int n,m,k;
char str[600];
int arr[500][500];
bool vis[500][500];
int cc[500][500];
int cnt=0;
void DFS(int y,int x) {
	if(cnt>=k) return;
	vis[y][x]=true;
	bool flag=false;
	for(int t=0;t<4;t++) {
		int yy=y+dy[t],xx=x+dx[t];
		if(yy>=0&&xx>=0&&yy<n&&xx<m&&arr[yy][xx]==0&&!vis[yy][xx]) {
			flag=true;
			DFS(yy,xx);
		}
	}
	if(!flag) {
		arr[y][x]=2;
		cnt++;	
	}
}
bool D2(int y,int x) {
	if(cnt>=k) return true;
	vis[y][x]=true;
	bool flag=false;
	for(int t=0;t<4;t++) {
		int yy=y+dy[t],xx=x+dx[t];
		if(yy>=0&&xx>=0&&yy<n&&xx<m&&arr[yy][xx]==0&&!vis[yy][xx]) {
			if(D2(yy,xx)) {
				flag=true;
			}
		}
	}
	if(!flag&&cnt<k) {
		arr[y][x]=2;
		cnt++;
	}
	return flag;
}

int main() {
	int tc=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) {
		scanf("%s",str);
		for(int j=0;j<m;j++) {
			if(str[j]=='#') arr[i][j]=1;
			else arr[i][j]=0,tc++;
		}
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++) vis[i][j]=false;
	for(int i=0;i<n;i++) {
		bool flag=false;
		for(int j=0;j<m;j++) if(arr[i][j]==0) {
			DFS(i,j);
			flag=true;
			break;
		}
		if(flag) break;
	}
	for(int i=0;i<n;i++)for(int j=0;j<m;j++) vis[i][j]=false;
	for(int i=0;i<n;i++) {
		bool flag=false;
		for(int j=0;j<m;j++) if(arr[i][j]==0) {
			D2(i,j);
			flag=true;
			break;
		}
		if(flag) break;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(arr[i][j]==0) printf(".");
			else if(arr[i][j]==1) printf("#");
			else printf("X");
		}
		puts("");
	}

	return 0;
}