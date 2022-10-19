#include<bits/stdc++.h>
using namespace std;
namespace Initialize{
	int id[1<<20],all,r[500][500];
	struct Linear_Basis{
		int d[5];
		int&operator[](const int&x){return d[x];}
		bool ins(int x){
			for(int i=4;i>=0;i--){
				if(!(x&(1<<i)))continue;
				if(!d[i]){d[i]=x;return true;}
				x^=d[i];
			}
			return false;
		}
		void comp(){for(int i=0;i<5;i++)for(int j=i-1;j>=0;j--)if((d[i]^d[j])<d[i])d[i]^=d[j];}
		int HASH()const{int ret=0;for(int i=0;i<5;i++)ret<<=(i+1),ret+=d[i];return ret;}
		int Hash(){comp();return id[HASH()];} 
		friend int operator+(Linear_Basis&u,Linear_Basis&v){
			Linear_Basis w=u;
			for(int i=0;i<5;i++)if(v[i]&&!w.ins(v[i]))return -1;
			return w.Hash();
		}
		void print()const{for(int i=0;i<5;i++)printf("%d ",d[i]);puts("");}
		void clear(){for(int i=0;i<5;i++)d[i]=0;}
	}lb;
	vector<Linear_Basis>v;
	void dfs(int pos){
		if(pos==5){lb.comp();if(id[lb.HASH()]==-1)id[lb.HASH()]=all++,v.push_back(lb);return;}
		Linear_Basis tmp=lb;
		for(int i=0;i<(1<<pos);i++)if(lb.ins(i+(1<<pos)))dfs(pos+1),lb=tmp;
		dfs(pos+1),lb=tmp;
	}
	void init(){
		memset(id,-1,sizeof(id)),dfs(0);
//		printf("%d\n",all);for(auto i:v)printf("%d:",i.HASH()),i.print();
		for(int i=0;i<all;i++)for(int j=0;j<all;j++)r[i][j]=v[i]+v[j];
	}
}
using namespace Initialize;
int n,m;
namespace Graph{
	const int mod=1e9+7;
	int head[100100],cnt,dis[100100];
	struct node{int to,next,val;}edge[200100];
	void ae(int u,int v,int w){
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
	}
	bool vis[100100];
	int sp;
	bool dfs(int x,int fa){
		vis[x]=true;
		bool ret=true; 
		for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa){
			if(vis[edge[i].to]){
				if(edge[i].to==1){sp=dis[x]^edge[i].val;continue;}
				if(edge[i].to>x&&!lb.ins(dis[x]^dis[edge[i].to]^edge[i].val))ret=false;
				continue;
			}
			dis[edge[i].to]=dis[x]^edge[i].val;
			if(!dfs(edge[i].to,x))ret=false;
		}
		return ret;
	}
	int f[510],g[510],res;
	void solve(){
		vis[1]=true;
		f[all-1]=1;
		for(int i=head[1];i!=-1;i=edge[i].next){
			if(vis[edge[i].to])continue;
			sp=-1,lb.clear(),dis[edge[i].to]=edge[i].val;
			if(!dfs(edge[i].to,1))continue;
//			lb.print(),printf("%d\n",sp);
			int x=lb.Hash();
			memset(g,0,sizeof(g));
			for(int j=0;j<all;j++)if(r[x][j]!=-1)(g[r[x][j]]+=(f[j]<<(sp!=-1))%mod)%=mod;
			if(sp!=-1&&lb.ins(sp)){
				x=lb.Hash();
				for(int j=0;j<all;j++)if(r[x][j]!=-1)(g[r[x][j]]+=f[j])%=mod;
			}
			for(int j=0;j<all;j++)(f[j]+=g[j])%=mod;
		}
		for(int i=0;i<all;i++)(res+=f[i])%=mod;
		printf("%d\n",res);
	}
}
using namespace Graph;
int main(){
	init(),scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<=m;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	solve();
	return 0;
}
/*
28 41
1 2 27
1 3 1
1 4 1
3 4 0
5 3 31
7 1 31
6 8 31
8 7 3
6 7 31
8 9 31
8 9 2
7 9 5
10 5 2
1 12 31
13 5 31
13 5 2
13 3 2
14 8 3
15 8 3
14 15 31
16 15 31
16 15 6
16 9 7
17 1 2
17 11 2
18 17 2
18 11 2
19 2 2
20 19 4
2 20 2
21 20 4
22 20 2
21 23 4
23 22 7
24 25 6
23 24 2
25 21 2
26 22 9
12 27 2
28 12 2
28 27 2
*/