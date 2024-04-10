#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
const double eps=1e-10;
const int N=200100;
int n,m,t,pay,head[60],DIS[60];
struct edge{
	int to,next,val;
}edge[110];
void ae(int u,int v,int w,int p){
	edge[p].next=head[u],edge[p].to=v,edge[p].val=w,head[u]=p;
}
double prob[110][N],dis[60][N],now[N];
int rev[N],lim=1,LG;
struct cp{
	double x,y;
	cp(double X=0,double Y=0){
		x=X,y=Y;
	}
	friend cp operator +(const cp &u,const cp &v){
		return cp(u.x+v.x,u.y+v.y);
	}
	friend cp operator -(const cp &u,const cp &v){
		return cp(u.x-v.x,u.y-v.y);
	}
	friend cp operator *(const cp &u,const cp &v){
		return cp(u.x*v.x-u.y*v.y,u.x*v.y+u.y*v.x);
	}
}A[N],B[N];
void FFT(cp *a,int tp){
	for(int i=0;i<lim;i++)if(rev[i]>i)swap(a[rev[i]],a[i]);
	for(int md=1;md<lim;md<<=1){
		cp rt=cp(cos(pi/md),tp*sin(pi/md));
		for(int stp=md<<1,pos=0;pos<lim;pos+=stp){
			cp w=cp(1,0);
			for(int i=0;i<md;i++,w=w*rt){
				cp x=a[pos+i],y=a[pos+md+i]*w;
				a[pos+i]=x+y;
				a[pos+md+i]=x-y;
			}
		}
	}
	if(tp==-1)for(int i=0;i<lim;i++)a[i].x/=lim;
}
void mul(double *a,double *b,double *c){
	for(int i=0;i<lim;i++)A[i]=B[i]=cp(0,0);
	for(int i=0;i<(lim>>1);i++)A[i]=cp(a[i],0),B[i]=cp(b[i],0);
	FFT(A,1),FFT(B,1);
	for(int i=0;i<lim;i++)A[i]=A[i]*B[i];
	FFT(A,-1);
	for(int i=0;i<lim;i++)c[i]=A[i].x;
}
bool vis[60];
void Dijkstra(){
	priority_queue<pair<int,int> >q;
	for(int i=1;i<=n;i++)DIS[i]=0x3f3f3f3f;
	DIS[n]=0,q.push(make_pair(0,n));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=true;
		for(int i=head[x],y;i!=-1;i=edge[i].next){
			y=edge[i].to;
			if(DIS[y]>DIS[x]+edge[i].val)DIS[y]=DIS[x]+edge[i].val,q.push(make_pair(-DIS[y],y));
		}
	} 
}
bool in[60];
void SPFA(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=t;j++)dis[i][j]=0x3f3f3f3f;
		for(int j=t+1;j<=2*t;j++)dis[i][j]=DIS[i]+pay;
	}
	for(int j=0;j<=t;j++)dis[n][j]=0;
	q.push(n),in[n]=true;
	while(!q.empty()){
		int x=q.front();q.pop(),in[x]=false;
		for(int i=head[x],y;i!=-1;i=edge[i].next){
			y=edge[i].to,mul(dis[x],prob[i],now);
			bool modi=false;
			for(int j=0;j<=t;j++)if(dis[y][j]>now[t+1+j]+edge[i].val)modi=true,dis[y][j]=now[t+1+j]+edge[i].val;
			if(modi&&!in[y])in[y]=true,q.push(edge[i].to);
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&t,&pay),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z),ae(y,x,z,i);
		for(int j=1;j<=t;j++)scanf("%d",&x),prob[i][j]=1.0*x/100000;
		reverse(prob[i]+1,prob[i]+t+1);
	}
	while(lim<=(t<<2))lim<<=1,LG++;
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(LG-1));
	Dijkstra();
	SPFA();
	printf("%.10lf\n",dis[1][0]);
	return 0;
}