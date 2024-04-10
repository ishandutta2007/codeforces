#include<bits/stdc++.h>
using namespace std;
int n,m,head[100100],cnt,dis[100100];
struct lb{//linear basis?
	int d[40];
	void print(){
		for(int i=0;i<=30;i++)if(d[i])printf("%d:%d\n",i,d[i]);
	}
	lb(){memset(d,0,sizeof(d));}
	void operator +=(int x){
		for(int i=30;i>=0;i--){
			if(!(x&(1<<i)))continue;
			if(d[i])x^=d[i];
			else{d[i]=x;break;}
		}
	}
	int& operator [](int x){
		return d[x];
	}
	void operator +=(lb &x){
		for(int i=30;i>=0;i--)if(x[i])*this+=x[i];
	}
	friend lb operator +(lb &x,lb &y){
		lb z=x;
		for(int i=30;i>=0;i--)if(y[i])z+=y[i];
		return z;
	}
	int calc(int x){//calculate minimum possible
		int res=x;
		for(int i=30;i>=0;i--)if((res^d[i])<res)res^=d[i];
		return res;
	}
}LB;
struct node{
	int to,next,val;
}edge[200100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++; 
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++; 
}
bool vis[100100];
void dfs(int x){
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(!vis[edge[i].to])vis[edge[i].to]=true,dis[edge[i].to]=dis[x]^edge[i].val,dfs(edge[i].to);
		else LB+=dis[x]^dis[edge[i].to]^edge[i].val;
	}
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	dfs(1);
//	LB.print();
	printf("%d\n",LB.calc(dis[n]));
	return 0;
}