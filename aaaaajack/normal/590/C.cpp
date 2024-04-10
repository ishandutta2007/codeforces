#include<cstdio>
#include<utility>
#include<queue>
#include<cctype>
#include<algorithm>
#include<cstring>
#define X first
#define Y second
#define N 1010
#define inf 0x3f3f3f3f
using namespace std;
bool con[4][4];
int dis[4][N][N],mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
char s[N][N];
int main(){
	int n,m,ans=-1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i&&isdigit(s[i][j])&&isdigit(s[i-1][j])){
				int x=s[i][j]-'0',y=s[i-1][j]-'0';
				con[x][y]=con[y][x]=true;
			}
			if(j&&isdigit(s[i][j])&&isdigit(s[i][j-1])){
				int x=s[i][j]-'0',y=s[i][j-1]-'0';
				con[x][y]=con[y][x]=true;
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=3;i++){
		queue<pair<int,int> > q;
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(s[j][k]=='0'+i){
					q.push(make_pair(j,k));
					dis[i][j][k]=0;
				}
			}
		}
		while(!q.empty()){
			int x=q.front().X,y=q.front().Y;
			q.pop();
			for(int d=0;d<4;d++){
				int nx=x+mx[d],ny=y+my[d];
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]=='.'&&dis[i][x][y]+1<dis[i][nx][ny]){
					dis[i][nx][ny]=dis[i][x][y]+1;
					q.push(make_pair(nx,ny));
				}
			}
		}
	}
	if(con[1][2]&&con[2][3]||con[1][3]&&con[2][3]||con[1][2]&&con[1][3]){
		puts("0");
	}
	else if(con[1][2]||con[2][3]||con[3][1]){
		int u[3];
		if(con[1][2]) u[0]=3,u[1]=1,u[2]=2;
		else if(con[2][3]) u[0]=1,u[1]=2,u[2]=3;
		else u[0]=2,u[1]=1,u[2]=3;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int d1=dis[u[0]][i][j],d2=min(dis[u[1]][i][j],dis[u[2]][i][j]);
				if(d1<inf&&d2<inf){
					int tmp=d1+d2-1;
					if(ans==-1||tmp<ans) ans=tmp;
				}
			}
		}
		printf("%d\n",ans);
	}
	else{
		int c[3]={inf,inf,inf};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int d[3];
				for(int k=0;k<3;k++){
					d[k]=dis[k+1][i][j];
				}
				if(d[0]<inf&&d[1]<inf&&d[2]<inf){
					int tmp=d[0]+d[1]+d[2]-2;
					if(ans==-1||tmp<ans) ans=tmp;
				}
				if(d[0]<inf&&d[1]<inf&&d[0]+d[1]-1<c[2]) c[2]=d[0]+d[1]-1;
				if(d[1]<inf&&d[2]<inf&&d[1]+d[2]-1<c[0]) c[0]=d[1]+d[2]-1;
				if(d[0]<inf&&d[2]<inf&&d[0]+d[2]-1<c[1]) c[1]=d[0]+d[2]-1;
			}
		}
		if(c[0]<inf&&c[1]<inf&&(ans==-1||c[0]+c[1]<ans)) ans=c[0]+c[1];
		if(c[1]<inf&&c[2]<inf&&(ans==-1||c[1]+c[2]<ans)) ans=c[1]+c[2];
		if(c[0]<inf&&c[2]<inf&&(ans==-1||c[0]+c[2]<ans)) ans=c[0]+c[2];
		printf("%d\n",ans);
	}
	return 0;
}