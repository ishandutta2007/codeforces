#include<cstdio>
#include<cstring>
#define N 200100
using namespace std;
struct edge{
	int to;
	int nxt;
}e[N*2];
int head[N*2],deg[N*2];
char ans[N];
void go(int u,char c){
	bool flag=true;
	while(flag){
		flag=false;
		while(head[u]!=-1&&ans[head[u]>>1]) head[u]=e[head[u]].nxt;
		if(head[u]!=-1){
			ans[head[u]>>1]=c;
			int v=e[head[u]].to;
			head[u]=e[head[u]].nxt;
			deg[v]--;
			deg[u]--;
			u=v;
			flag=true;
			c^='b'^'r';
		}
	}
}
int main(){
	int n,x,y,i;
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		y+=N;
		e[i*2].nxt=head[x];
		e[i*2].to=y;
		e[i*2+1].nxt=head[y];
		e[i*2+1].to=x;
		head[x]=i*2;
		head[y]=i*2+1;
		deg[x]++;
		deg[y]++;
	}
	for(i=0;i<N*2;i++){
		if(deg[i]&1){
			go(i,'b');
		}
	}
	for(i=0;i<N*2;i++){
		if(deg[i]){
			go(i,'b');
		}
	}
	printf("%s\n",ans);
	return 0;
}