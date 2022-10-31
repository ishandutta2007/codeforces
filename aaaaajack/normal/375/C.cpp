#include<cstdio>
#include<cctype>
#include<cstring>
#include<queue>
using namespace std;
int dp[30][30][256];
const int mx[4]={-1,0,1,0},my[4]={0,-1,0,1};
struct state{
	int x;
	int y;
	int m;
	state(){}
	state(int _x,int _y,int _m):x(_x),y(_y),m(_m){}
};
bool intersect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	if(x1==x2){
		if((x1-x3)*(x1-x4)>0) return false;
		double ty=y3+(y4-y3)*1.0*(x1-x3)/(x4-x3);
		return (ty-y1)*(ty-y2)<0;
	}
	else{
		if((y1-y3)*(y1-y4)>0) return false;
		double tx=x3+(x4-x3)*1.0*(y1-y3)/(y4-y3);
		return (tx-x1)*(tx-x2)<0;
	}
}
int main(){
	int obx[8],oby[8],v[8],n,m,i,j,stx,sty,temp,k=0,l,Max;
	char g[30][30];
	state r;
	queue<state> q;
	scanf("%d%d",&n,&m);
	getchar();
	for(i=0;i<n;i++) gets(g[i]);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(g[i][j]=='S'){
				stx=i;
				sty=j;
				g[i][j]='.';
			}
			else if(isdigit(g[i][j])){
				temp=g[i][j]-'0';
				if(temp>k) k=temp;
				obx[temp-1]=i;
				oby[temp-1]=j;
			}
		}
	}
	l=k;
	for(i=0;i<k;i++) scanf("%d",&v[i]);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(g[i][j]=='B'){
				temp=k++;
				obx[temp]=i;
				oby[temp]=j;
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[stx][sty][0]=0;
	q.push(state(stx,sty,0));
	while(!q.empty()){
		r=q.front();
		q.pop();
		for(j=0;j<4;j++){
			int nx=r.x+mx[j],ny=r.y+my[j];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&g[nx][ny]=='.'){
				temp=0;
				for(i=0;i<k;i++){
					if(intersect( nx,ny, r.x,r.y, obx[i],oby[i], 100,oby[i]+1 )){
						temp|=(1<<i);
					}
				}
				if(dp[nx][ny][r.m^temp]<0){
					dp[nx][ny][r.m^temp]=dp[r.x][r.y][r.m]+1;
					q.push(state(nx,ny,r.m^temp));
				}
			}
		}
	}
	Max=0;
	for(i=0;i<(1<<l);i++){
		temp=0;
		for(j=0;j<l;j++){
			if(i&(1<<j)) temp+=v[j];
		}
		if(dp[stx][sty][i]<0) continue;
		if(temp-dp[stx][sty][i]>Max) Max=temp-dp[stx][sty][i];
	}
	printf("%d\n",Max);
	return 0;
}