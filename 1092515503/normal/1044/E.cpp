#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
int dis[362880];
int rex[8][4]={
{0,0,1,1},
{0,0,1,1},
{1,1,2,2},
{1,1,2,2},
{0,1,1,0},
{0,1,1,0},
{1,2,2,1},
{1,2,2,1}
},rey[8][4]={
{0,1,1,0},
{1,2,2,1},
{0,1,1,0},
{1,2,2,1},
{0,0,1,1},
{1,1,2,2},
{0,0,1,1},
{1,1,2,2},
};
int appr[362880],las[362880];
vector<int>trans[3][3][3][3];
int code(int*a){
	int ret=0;
	for(int i=0;i<9;i++){
		ret=1ll*ret*(9-i);
		for(int j=i+1;j<9;j++)ret+=(a[i]>a[j]);
	}
	return ret;
}
void deco(int val,int*a){
	static bool cho[9];
	for(int i=8;i>=0;i--)a[i]=val%(9-i),val/=9-i,cho[i]=false;
	for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(!cho[j]&&!a[i]--){a[i]=j,cho[j]=true;break;}
}
void print(int*a){for(int i=0;i<3;i++){for(int j=0;j<3;j++)printf("%d",a[i*3+j]);puts("");}puts("");}
void mo(int*a,int id){
	int tmp=a[rex[id][3]*3+rey[id][3]];
	for(int i=2;i>=0;i--)a[rex[id][i+1]*3+rey[id][i+1]]=a[rex[id][i]*3+rey[id][i]];
	a[rex[id][0]*3+rey[id][0]]=tmp;
}
int a[9];
queue<int>q;
void bfs(){
	memset(dis,-1,sizeof(dis)),dis[0]=0,q.push(0);
//	for(int i=0;i<8;i++){for(int j=0;j<4;j++)printf("(%d,%d)",rex[i][j],rey[i][j]);puts("");}
	while(!q.empty()){
		int x=q.front(),y;q.pop();
//		printf("%d\n",x);
		deco(x,a);
//		print(a);
		for(int i=0;i<8;i++){
			mo(a,i);
			y=code(a);
			if(dis[y]==-1)dis[y]=dis[x]+1,las[y]=x,appr[y]=i,q.push(y);
			mo(a,i^4);
		}
	}
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int I=0;I<3;I++)for(int J=0;J<3;J++){
		if(i==I&&j==J)continue;
		for(int k=0;k<9;k++)a[k]=k;
		swap(a[i*3+j],a[I*3+J]);
		int x=code(a);
		while(x)trans[i][j][I][J].push_back(appr[x]),x=las[x];
		reverse(all(trans[i][j][I][J]));
//		printf("(%d,%d)->(%d,%d)",i,j,I,J);for(auto k:trans[i][j][I][J])printf("%d ",k);puts("");
	}
}
int n,m,b[1000];
vector<vector<int> >v;
void MOVE(vector<int>x,vector<int>y){
	vector<int>u;
	for(int i=0;i<4;i++)u.push_back(b[x[i]*m+y[i]]);
	v.push_back(u);
	int tmp=b[x[3]*m+y[3]];
	for(int i=2;i>=0;i--)b[x[i+1]*m+y[i+1]]=b[x[i]*m+y[i]];
	b[x[0]*m+y[0]]=tmp;
}
void MOVE(int x,int y,int id){
	vector<int>X(4),Y(4);
	for(int i=0;i<4;i++)X[i]=rex[id][i]+x,Y[i]=rey[id][i]+y;
	MOVE(X,Y);
}
void MOVE(int x,int y,int X,int Y){
	int xx=max(0,max(x,X)-2);
	int yy=max(0,max(y,Y)-2);
	x-=xx,y-=yy,X-=xx,Y-=yy;
	for(auto i:trans[x][y][X][Y])MOVE(xx,yy,i); 
}
void Rightward(int&x,int&y){
	if(x==n-1)MOVE(x,y,x,y+1);
	else MOVE({x,x,x+1,x+1},{y,y+1,y+1,y});
	y++;
}
void Leftward(int&x,int&y){
	if(x==n-1)MOVE(x,y,x,y-1);
	else MOVE({x,x,x+1,x+1},{y,y-1,y-1,y});
	y--;
}
void Upward(int&x,int&y){
	if(y==m-1)MOVE(x,y,x-1,y);
	else MOVE({x-1,x-1,x,x},{y,y+1,y+1,y});
	x--;
}
int main(){
	bfs();
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&b[i*m+j]);
	for(int i=0;i<n*m;i++){
		int x=i/m,y=i%m,X,Y;
		for(int j=i;j<n*m;j++)if(b[j]==i+1)X=j/m,Y=j%m;
		if(x==X&&y==Y)continue;
		if(X==n-1&&x<n-2)Upward(X,Y);
		while(Y<y)Rightward(X,Y);
		while(Y>y)Leftward(X,Y);
		while(X>x)Upward(X,Y);
//		for(int i=0;i<n;i++){for(int j=0;j<m;j++)printf("%d ",b[i*m+j]);puts("");}
	}
	printf("%d\n",v.size()); 
	for(auto i:v){printf("%d ",i.size());for(auto j:i)printf("%d ",j);puts("");}
	return 0;
}