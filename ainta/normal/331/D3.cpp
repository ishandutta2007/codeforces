#include<stdio.h>
#include<algorithm>
#include<vector>
#define M_SIZE 100010

using namespace std;
int N,B,Q,SArr[M_SIZE];
int Next[51][M_SIZE];
long long dist[51][M_SIZE],Time[M_SIZE],INF=1e16;

int dis(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

struct Segment{
	int x1,y1,x2,y2,dir;
}seg[M_SIZE];

int IT[M_SIZE*3],SZ,LastC;

struct point{
	int x,y;
}Res[M_SIZE],Last[M_SIZE];

struct Xdir{
	int x1,y1,x2,y2,num,dir,tx;
	bool operator <(const Xdir &p)const{
		return tx<p.tx;
	}
}X[M_SIZE];
struct Ydir{
	int x1,y1,x2,y2,num,dir,ty;
	bool operator <(const Ydir &p)const{
		return ty<p.ty;
	}
}Y[M_SIZE];

struct vec{
	int t,dir,num;
}tp;
vector<vec> vecX[M_SIZE],vecY[M_SIZE];

void input()
{
	scanf("%d%d",&N,&B);
	int i,x1,y1,x2,y2,dir;
	for(i=1;i<=N;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)dir=y1<y2?0:1;
		else dir=x1<x2?3:2;
		seg[i].x1=x1,seg[i].y1=y1,seg[i].x2=x2,seg[i].y2=y2,seg[i].dir=dir;
		X[i].x1=x1,X[i].y1=y1,X[i].x2=x2,X[i].y2=y2,X[i].dir=dir,X[i].num=i;
		Y[i].x1=x1,Y[i].y1=y1,Y[i].x2=x2,Y[i].y2=y2,Y[i].dir=dir,Y[i].num=i;
	}
	scanf("%d",&Q);
	char dir2[2];
	for(i=0;i<Q;i++){
		scanf("%d%d",&x1,&y1);
		scanf("%s",dir2);
		if(dir2[0]=='U')dir=0;
		else if(dir2[0]=='D')dir=1;
		else if(dir2[0]=='L')dir=2;
		else dir=3;
		scanf("%lld",&Time[i]);
		if(dir<2){
			tp.t=x1,tp.dir=dir,tp.num=i;
			vecY[y1].push_back(tp);
		}
		else{
			tp.t=y1,tp.dir=dir,tp.num=i;
			vecX[x1].push_back(tp);
		}
	}
	SZ=1;
	while(SZ<=B)SZ*=2;
}

void spread(int x){
	IT[x*2]=IT[x*2+1]=IT[x];
	IT[x]=0;
}
void Ins(int node,int b,int e,int s,int l,int x)
{
	if(b==s && e==l){
		IT[node]=x;
		return;
	}
	if(IT[node])spread(node);
	int m=(b+e)>>1,c1=node<<1;
	if(s<=m)Ins(c1,b,m,s,min(l,m),x);
	if(l>m)Ins(c1+1,m+1,e,max(s,m+1),l,x);
}
int find(int node,int b,int e,int x)
{
	if(IT[node])return IT[node];
	if(b==e)return 0;
	int m=(b+e)>>1;
	if(x>m)return find(node*2+1,m+1,e,x);
	else return find(node*2,b,m,x);
}

void Calc(int x1,int y1,int x2,int y2,int dir,int a){
	long long T=Time[a];
	int d;
	if(T>dis(x1,y1,x2,y2)){
		Res[a].x=x2,Res[a].y=y2;
		return;
	}
	Res[a].x=x1,Res[a].y=y1;
	if(dir<2){
		d=abs(y2-y1);
		if(d>=T){
			if(y1<y2)Res[a].y+=T;
			else Res[a].y-=T;
			return;
		}
		Res[a].y=y2,T-=d;
		if(x1<x2)Res[a].x+=T;
		else Res[a].x-=T;
		return;
	}
	d=abs(x2-x1);
	if(d>=T){
		if(x1<x2)Res[a].x+=T;
		else Res[a].x-=T;
		return;
	}
	Res[a].x=x2,T-=d;
	if(y1<y2)Res[a].y+=T;
	else Res[a].y-=T;
	return;
}

void Make_GraphX(int dir)
{
	int i,st,ed,t,d,t2,pm,px,j,x,y;
	for(i=1;i<=SZ+B+1;i++)IT[i]=0;
	if(dir==3)st=N,ed=0,pm=-1,px=B;
	else st=1,ed=N+1,pm=1,px=0;
	
	if(dir==3)
		for(i=1;i<=N;i++)X[i].tx=max(X[i].x1,X[i].x2);
	else
		for(i=1;i<=N;i++)X[i].tx=min(X[i].x1,X[i].x2);
	sort(X+1,X+N+1);

	for(i=st;;i+=pm){
		while(i==ed||px!=X[i].tx){
			if(px==-1 ||px==B+1)break;
			for(j=0;j<vecX[px].size();j++){
				tp=vecX[px][j];
				if(tp.dir!=dir)continue;
				t=find(1,0,SZ-1,tp.t);
				t2=tp.num;
				if(t){
					d=dis(px,tp.t,seg[t].x2,seg[t].y2);
					if(d<=Time[t2]){
						Time[t2]-=d;
						SArr[t2]=t;
						continue;
					}
					Calc(px,tp.t,seg[t].x2,seg[t].y2,dir,t2);
				}
				else{
					x=px,y=tp.t;
					if(dir==3)x=B;
					else x=0;
					Calc(px,tp.t,x,y,dir,t2);
				}
			}
			px+=pm;
		}
		if(i==ed)break;
		if(dir!=X[i].dir){
			Ins(1,0,SZ-1,min(X[i].y1,X[i].y2),max(X[i].y1,X[i].y2),X[i].num);
			continue;
		}
		t=find(1,0,SZ-1,X[i].y1);
		t2=X[i].num;
		if(t){
			d=dis(X[i].x2,X[i].y2,seg[t].x2,seg[t].y2);
			Next[0][t2]=t;
			dist[0][t2]=d;
			continue;
		}
		x=X[i].x2,y=X[i].y2;
		if(dir==2)d=x,x=0;
		else d=B-x,x=B;
		++LastC;
		Next[0][t2]=N+LastC;
		dist[0][t2]=d;
		Last[LastC].x=x,Last[LastC].y=y;
	}
}
void Make_GraphY(int dir)
{
	int i,st,ed,t,d,t2,pm,py,j,x,y;
	for(i=1;i<=SZ+B+1;i++)IT[i]=0;
	if(dir==0)st=N,ed=0,pm=-1,py=B;
	else st=1,ed=N+1,pm=1,py=0;

	if(dir==0)
		for(i=1;i<=N;i++)Y[i].ty=max(Y[i].y1,Y[i].y2);
	else
		for(i=1;i<=N;i++)Y[i].ty=min(Y[i].y1,Y[i].y2);
	sort(Y+1,Y+N+1);

	for(i=st;;i+=pm){
		while(i==ed||py!=Y[i].ty){
			if(py==-1 ||py==B+1)break;
			for(j=0;j<vecY[py].size();j++){
				tp=vecY[py][j];
				if(tp.dir!=dir)continue;
				t=find(1,0,SZ-1,tp.t);
				t2=tp.num;
				if(t){
					d=dis(tp.t,py,seg[t].x2,seg[t].y2);
					if(d<=Time[t2]){
						Time[t2]-=d;
						SArr[t2]=t;
						continue;
					}
					Calc(tp.t,py,seg[t].x2,seg[t].y2,dir,t2);
				}
				else{
					x=tp.t,y=py;
					if(dir==0)y=B;
					else y=0;
					Calc(tp.t,py,x,y,dir,t2);
				}
			}
			py+=pm;
		}
		if(i==ed)break;
		if(dir!=Y[i].dir){
			Ins(1,0,SZ-1,min(Y[i].x1,Y[i].x2),max(Y[i].x1,Y[i].x2),Y[i].num);
			continue;
		}
		t=find(1,0,SZ-1,Y[i].x1);
		t2=Y[i].num;
		if(t){
			d=dis(Y[i].x2,Y[i].y2,seg[t].x2,seg[t].y2);
			Next[0][t2]=t;
			dist[0][t2]=d;
			continue;
		}
		x=Y[i].x2,y=Y[i].y2;
		if(dir==1)d=y,y=0;
		else d=B-y,y=B;
		++LastC;
		Next[0][t2]=N+LastC;
		dist[0][t2]=d;
		Last[LastC].x=x,Last[LastC].y=y;
	}
}

void save_2k(){
	int i,j;
	for(i=1;i<=50;i++){
		for(j=1;j<=N;j++){
			if(Next[i-1][j]>N)
				Next[i][j]=Next[i-1][j],dist[i][j]=dist[i-1][j];
			else
				Next[i][j]=Next[i-1][Next[i-1][j]],dist[i][j]=dist[i-1][j]+dist[i-1][Next[i-1][j]];
			if(dist[i][j]>INF)dist[i][j]=INF;
		}
	}
}

void GetAnswer(int a,int x,long long T){
	int i,d,X,Y;
	if(dist[50][x]<=T){
		Res[a]=Last[Next[50][x]-N];
		return;
	}
	for(i=49;i>=0;i--){
		if(dist[i][x]<=T){
			T-=dist[i][x];
			x=Next[i][x];
		}
	}
	Time[a]=T;
	d=Next[0][x];
	if(d<=N)X=seg[d].x2,Y=seg[d].y2;
	else X=Last[d-N].x,Y=Last[d-N].y;
	Calc(seg[x].x2,seg[x].y2,X,Y,seg[x].dir,a);
}
void Process()
{
	int i;
	for(i=0;i<Q;i++){
		if(SArr[i]){
			GetAnswer(i,SArr[i],Time[i]);
		}
	}
}
void Print()
{
	int i;
	for(i=0;i<Q;i++)
		printf("%d %d\n",Res[i].x,Res[i].y);
}

int main()
{
	input();
	Make_GraphX(2);
	Make_GraphX(3);
	Make_GraphY(0);
	Make_GraphY(1);
	save_2k();
	Process();
	Print();
	return 0;
}