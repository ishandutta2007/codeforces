#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define N 150000
using namespace std;
bool del[N],atk[N];
int deg[N];
vector<int> g[N];
void get_long(int u,int p,int &v,int &len,int &tlf,int &lf){
	v=u;
	len=0;
	tlf=0;
	lf=u;
	int mlen[2]={0,0},mv[2]={u,u};
	for(int i=0;i<g[u].size();i++){
		if(g[u][i]==p||del[g[u][i]]) continue;
		int cv,clen,ctlf,clf;
		get_long(g[u][i],u,cv,clen,ctlf,clf);
		if(ctlf+1>tlf||(ctlf+1==tlf&&clf<lf)){
			tlf=ctlf+1;
			lf=clf;
		}
		if(clen>len||clen==len&&cv<v){
			len=clen;
			v=cv;
		}
		if(mlen[0]<ctlf+1||mlen[0]==ctlf+1&&clf<mv[0]){
			mlen[1]=mlen[0];
			mv[1]=mv[0];
			mlen[0]=ctlf+1;
			mv[0]=clf;
		}
		else if(mlen[1]<ctlf+1||mlen[1]==ctlf+1&&clf<mv[1]){
			mlen[1]=ctlf+1;
			mv[1]=clf;
		}
	}
	if(mlen[0]+mlen[1]>len||mlen[0]+mlen[1]==len&&min(mv[0],mv[1])<v){
		len=mlen[0]+mlen[1];
		v=min(mv[0],mv[1]);
	}
}
int main(){
	int n,m,num;
	scanf("%d%d",&n,&m);
	num=n-1;
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		deg[x]++,deg[y]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(deg[i]==1) q.push(i);
	}
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		atk[x]=true;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(atk[u]) continue;
		del[u]=true;
		num--;
		for(int i=0;i<g[u].size();i++){
			if(del[g[u][i]]) continue;
			deg[g[u][i]]--;
			if(deg[g[u][i]]<=1) q.push(g[u][i]);
		}
	}
	int x=1,r1,r2,r3,r4;
	while(del[x]) x++;
	get_long(x,0,r1,r2,r3,r4);
	printf("%d\n%d\n",r1,num*2-r2);
	return 0;
}