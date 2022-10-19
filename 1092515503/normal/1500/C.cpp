#include<bits/stdc++.h>
using namespace std;
const int mod1=19260817;
const int mod2=17680321;
int n,m,a[1510][1510],b[1510][1510],p[1510];
pair<int,int>hsh[1510];
bool mat[1510];
queue<int>q;
vector<int>v[1510],u[1510],w;
int in[1510];
bool vis[1510];
void read(int&x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
}
int main(){
	read(n),read(m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)read(a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)read(b[i][j]);
	for(int i=1;i<=n;i++){
		int vl1=0,vl2=0;
		for(int j=1;j<=m;j++)vl1=(1ll*n*vl1+a[i][j])%mod1,vl2=(1ll*n*vl2+a[i][j])%mod2;
		hsh[i]=make_pair(vl1,vl2);
	}
	for(int i=1;i<=n;i++){
		int vl1=0,vl2=0;
		for(int j=1;j<=m;j++)vl1=(1ll*n*vl1+b[i][j])%mod1,vl2=(1ll*n*vl2+b[i][j])%mod2;
		for(int j=1;j<=n;j++)if(!mat[j]&&hsh[j]==make_pair(vl1,vl2)){mat[j]=true,p[i]=j;break;}
		if(!p[i]){puts("-1");return 0;}
	}
//	for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(a[p[i]][j]<a[p[i+1]][j])u[j].push_back(i);
			if(a[p[i]][j]>a[p[i+1]][j])v[i].push_back(j),in[j]++;
		}
	}
	for(int i=1;i<=m;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		w.push_back(x);
		for(auto y:u[x]){
			if(vis[y])continue;vis[y]=true;
			for(auto z:v[y])if(!--in[z])q.push(z);
		}
	}
	for(int i=1;i<n;i++)if(p[i]>p[i+1]&&!vis[i]){puts("-1");return 0;}
	reverse(w.begin(),w.end());
	printf("%d\n",w.size());
	for(auto x:w)printf("%d ",x);
	return 0;
}