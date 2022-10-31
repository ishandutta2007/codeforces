#include<bits/stdc++.h>
#define N 100100
using namespace std;
vector<int> g[N],v[N];
int n,id[N],nxt[N],cur[N];
struct edge{
	int a,b;
	int len()const{
		int s=b-a;
		if(s<0) s+=n;
		return s;
	}
	bool operator<(const edge &e2)const{
		return len()<e2.len();
	}
}e[N];
bool cmp(int i,int j){
	for(int k=0;k<v[i].size()&&k<v[j].size();k++){
		if(v[i][k]<v[j][k]) return true;
		else if(v[i][k]>v[j][k]) return false;
	}
	return v[i].size()<v[j].size();
}
bool del[N];
int sz[N],dep[N];
int build_sz(int u,int p){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		int to=g[u][i];
		if(del[to]||to==p) continue;
		sz[u]+=build_sz(to,u);
	}
	return sz[u];
}
void decom(int u,int d){
	int tsz=build_sz(u,-1);
	int p=-1;
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=0;i<g[u].size();i++){
			int to=g[u][i];
			if(del[to]||to==p){
				continue;
			}
			if(sz[to]+sz[to]>tsz){
				p=u;
				u=to;
				flag=true;
				break;
			}
		}
	}
	del[u]=true;
	dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		int to=g[u][i];
		if(!del[to]) decom(to,d+1);
	}
}
int main(){
	memset(cur,-1,sizeof(cur));
	int m,in=1,now;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		nxt[i]=i+1;
	}
	nxt[n]=1;
	for(int i=0;i<m;i++){
		scanf("%d%d",&e[i].a,&e[i].b);
		if(e[i].len()*2>n){
			swap(e[i].a,e[i].b);
		}
	}
	sort(e,e+m);
	for(int i=0;i<m;i++){
		for(int j=e[i].a;j!=e[i].b;j=nxt[j]){
			if(cur[j]>=0){
				g[i].push_back(cur[j]);
				g[cur[j]].push_back(i);
			}
			v[i].push_back(j);
		}
		v[i].push_back(e[i].b);
		in=e[i].b;
		cur[e[i].a]=i;
		nxt[e[i].a]=e[i].b;
		//printf("%d %d\n",e[i].a,e[i].b);
	}
	now=in;
	do{
		if(cur[now]>=0){
			g[m].push_back(cur[now]);
			g[cur[now]].push_back(m);
			//printf("%d %d\n",cur[now],m);
		}
		v[m].push_back(now);
		now=nxt[now];
	}while(now!=in);
	//puts("!!");
	for(int i=0;i<=m;i++){
		sort(v[i].begin(),v[i].end(),greater<int>());
		id[i]=i;
	}
	sort(id,id+m+1,cmp);
	decom(0,1);
	for(int i=0;i<=m;i++){
		if(i) putchar(' ');
		printf("%d",dep[id[i]]);
	}
	puts("");
	return 0;
}