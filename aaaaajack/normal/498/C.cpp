#include<cstdio>
#include<cstring>
#include<queue>
#define M 1000
#define N 1000
#define K 32000
#define inf 1023456789
using namespace std;
struct edge{
	int to;
	int c;
	edge(int _t=0,int _c=0):to(_t),c(_c){}
}e[M];
int cnt=0,ptr[N],dis[N],n;
vector<int> g[N];
void add_edge(int x,int y,int c){
	e[cnt]=edge(y,c);
	g[x].push_back(cnt++);
	e[cnt]=edge(x,0);
	g[y].push_back(cnt++);
}
bool BFS(){
	queue<int> q;
	memset(dis,-1,sizeof(dis));
	dis[0]=0;
	q.push(0);
	while(!q.empty()){
		int now=q.front();
		for(int i=0;i<g[now].size();i++){
			if(e[g[now][i]].c&&dis[e[g[now][i]].to]==-1){
				q.push(e[g[now][i]].to);
				dis[e[g[now][i]].to]=dis[now]+1;
			}
		}
		q.pop();
	}
	if(dis[n+1]>=0) return true;
	else return false;
}
int go(int now,int c){
	if(now==n+1) return c;
	int tmp;
	for(int &i=ptr[now];i<g[now].size();i++){
		if(!e[g[now][i]].c||dis[now]+1!=dis[e[g[now][i]].to]) continue;
		tmp=go(e[g[now][i]].to,min(c,e[g[now][i]].c));
		if(tmp){
			e[g[now][i]].c-=tmp;
			e[g[now][i]^1].c+=tmp;
			return tmp;
		}
	}
	return 0;
}
int max_flow(){
	int ans=0,tmp;
	while(BFS()){
		memset(ptr,0,sizeof(ptr));
		while(tmp=go(0,inf)){
			ans+=tmp;
		}
	}
	return ans;
}
bool isprm[K];
int pcnt=0,prm[K];
int main(){
	int i,j,a[N],m,r,x[M],y[M],apow,ans=0;
	memset(isprm,-1,sizeof(isprm));
	for(i=2;i<K;i++){
		if(isprm[i]) prm[pcnt++]=i;
		for(j=0;j<pcnt&&i*prm[j]<K;j++){
			isprm[i*prm[j]]=false;
			if(i%prm[j]==0) break;
		}
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<m;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(y[i]&1) swap(x[i],y[i]);
	}
	for(i=0;i<pcnt;i++){
		bool flag=false;
		cnt=0;
		for(j=0;j<=n+1;j++) g[j].clear();
		for(j=0;j<m;j++){
			add_edge(x[j],y[j],inf);
		}
		for(j=1;j<=n;j++){
			if(!a[j]) apow=inf;
			else{
				if(a[j]>1) flag=true;
				apow=0;
				while(a[j]%prm[i]==0){
					a[j]/=prm[i];
					apow++;
				}
			}
			if(j&1) add_edge(0,j,apow);
			else add_edge(j,n+1,apow);
		}
		if(!flag) break;
		ans+=max_flow();
	}
	for(i=1;i<=n;i++){
		if(a[i]==1) continue;
		cnt=0;
		for(j=0;j<=n+1;j++) g[j].clear();
		for(j=0;j<m;j++){
			add_edge(x[j],y[j],inf);
		}
		r=a[i];
		for(j=1;j<=n;j++){
			if(!a[j]) apow=inf;
			else{
				apow=0;
				while(a[j]%r==0){
					a[j]/=r;
					apow++;
				}
			}
			if(j&1) add_edge(0,j,apow);
			else add_edge(j,n+1,apow);
		}
		ans+=max_flow();
	}
	printf("%d\n",ans);
	return 0;
}