#include <stdio.h>
#include <algorithm>
#include <queue>

struct Data {
	int y,x,cnt,di;
	Data() {}
	Data(int y, int x, int cnt, int di):y(y),x(x),cnt(cnt),di(di){}
};
const int dy[4]={0,1,0,-1},dx[4]={1,0,-1,0};
int n,m,sx,sy,ex,ey;
char str[1010][1010];
int vis[1010][1010][3][4];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%s",str[i]);
		for(int j=0;j<m;j++) {
			if(str[i][j]=='S'){
				sy=i;sx=j;
			}
			else if(str[i][j]=='T') {
				ey=i;ex=j;
			}
		}
	}

	std::queue<Data> que;
	for(int k=0;k<4;k++) {
		int yy=sy+dy[k],xx=sx+dx[k];
		if(yy>=0&&xx>=0&&yy<n&&xx<m&&str[yy][xx]!='*'){
			que.push(Data(yy,xx,0,k));
			vis[yy][xx][0][k]=1;
		}
	}

	while(!que.empty()) {
		Data now=que.front();que.pop();
		// printf("%d %d %d %d\n",now.y,now.x,now.cnt,now.di);
		for(int k=0;k<4;k++) {
			if((k+2)%4==now.di) continue;

			int yy=now.y+dy[k],xx=now.x+dx[k];
			int it=(k!=now.di)?1:0;
			if(yy>=0&&xx>=0&&yy<n&&xx<m&&str[yy][xx]!='*'&&now.cnt+it<=2&&vis[yy][xx][now.cnt+it][k]==0) {
				vis[yy][xx][now.cnt+it][k]=vis[now.y][now.x][now.cnt][now.di]+1;
				que.push(Data(yy,xx,now.cnt+it,k));
			}
		}
	}

	int min=987654321;
	for(int t=0;t<3;t++) {
		
		for(int k=0;k<4;k++) {
			if(vis[ey][ex][t][k]==0) continue;
			min=std::min(min,vis[ey][ex][t][k]);
		}
	}

	if(min==987654321)
		printf("NO\n");
	else
		printf("YES");

	return 0;
}