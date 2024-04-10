/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,h[200100],g[200100],f[200100];
bool sp[200100];
vector<int>v[200100],u[200100];
queue<int>q[200100];
bool vis[200100];
bool occ[200100];
int mn[200100],mx[200100];
int main(){
	scanf("%d",&n),memset(h,-1,sizeof(h));
	for(int i=1;i<=n;i++){scanf("%d",&sp[i]);if(sp[i])h[i]=0,q[0].push(i);}
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	for(int i=0;i<=n;i++)while(!q[i].empty()){
		int x=q[i].front();q[i].pop();
		for(auto y:v[x])if(h[y]==-1)q[h[y]=h[x]+1].push(y);
	}
	for(int x=1;x<=n;x++)for(auto y:v[x])if(h[x]==h[y])occ[h[x]]=true;
	for(int i=1;i<=n;i++)u[h[i]].push_back(i),g[i]=h[i];
	// for(int i=1;i<=n;i++)printf("%d ",h[i]);puts("");
	for(int _=0;_<=n;_++)if(occ[_]){
		// printf("%d:\n",_);
		memset(f,0x3f,sizeof(f)),memset(vis,false,sizeof(vis));
		memset(mn,0x3f,sizeof(mn)),memset(mx,0xc0,sizeof(mx));
		for(int x=1;x<=n;x++)for(auto y:v[x])if(h[x]==_&&h[y]==_)f[x]=f[y]=0;
		for(int i=_;i<=n;i++){
			for(auto j:u[i])if(f[j]!=0x3f3f3f3f)q[f[j]].push(j),mx[i]=max(mx[i],f[j]),mn[i]=min(mn[i],f[j]);
			for(int j=mn[i];j<=mx[i];j++)while(!q[j].empty()){
				int x=q[j].front();q[j].pop();
				if(vis[x])continue;vis[x]=true;
				// printf("%d:%d\n",x,f[x]);
				for(auto y:v[x]){
					if(h[y]==h[x]){if(f[y]>f[x]+1)q[f[y]=f[x]+1].push(y),mx[i]=max(mx[i],f[y]);}
					if(h[y]>h[x])f[y]=min(f[y],max(f[x]-1,0));
				}
			}
		}
		// for(int i=1;i<=n;i++)printf("%d ",f[i]);puts("");
		for(int i=1;i<=n;i++)if(!f[i])g[i]=min(g[i],_);
	}
	for(int i=1;i<=n;i++)printf("%d\n",(h[i]<<1)-g[i]);
	return 0;
}