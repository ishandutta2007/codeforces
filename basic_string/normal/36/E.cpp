#include<bits/stdc++.h>
using namespace std;
#define GG puts("-1"),exit(0);
const int N=10009,M=20009;
int he[N],to[M],ne[M],d[N],g[N],o,st[N],tp;
bool f[M];
vector<int>v[N];
void pre(int x){
	f[x]=1,v[o].push_back(x);
	if(d[x]&1)++g[o];
	for(int i=he[x];i;i=ne[i])if(!f[to[i]])pre(to[i]);
}
void dfs(int x){for(int i,j;i=he[x];)if(he[x]=ne[i],!f[j=i>>1])f[j]=1,dfs(to[i]),st[++tp]=j;}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,m,t=1;
	scanf("%d",&m);
	if(m<2)GG
	for(i=1;i<=m;++i){
		scanf("%d%d",&j,&k),++d[j],++d[k];
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	for(i=1;i<N;++i)if(he[i]&&!f[i])++o,pre(i);
	memset(f,0,M);
	if(o>2)GG
	if(o>1){
		if(g[1]>2||g[2]>2)GG
		if(g[1]){for(int j:v[1])if(d[j]&1){dfs(j);break;}}
		else dfs(v[1].back());
		for(printf("%d\n",j=tp);j;--j)printf("%d ",st[j]);
		tp=0;
		if(g[2]){for(int j:v[2])if(d[j]&1){dfs(j);break;}}
		else dfs(v[2].back());
		for(printf("\n%d\n",j=tp);j;--j)printf("%d ",st[j]);
		return 0;
	}
	if(g[1]>4)GG
	if(g[1]==4){
		for(int j:v[1])if(d[j]&1)v[0].push_back(j);
		j=v[0][0],k=v[0][1];
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
		dfs(v[0][2]);
		for(j=1;;++j)if(st[j]==t/2)break;
		for(printf("%d\n",i=j-1);i;--i)printf("%d ",st[i]);
		for(printf("\n%d\n",tp-j),i=tp;i>j;--i)printf("%d ",st[i]);
		return 0;
	}
	if(g[1]){for(int j:v[1])if(d[j]&1){dfs(j);break;}}
	else dfs(v[1].back());
	printf("1\n%d",st[j=tp]);
	for(printf("\n%d\n",--j);j;--j)printf("%d ",st[j]);
	return 0;
}