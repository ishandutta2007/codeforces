#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3,M=2e6+3;
int he[N],to[M],ne[M],d[N],w;
bool b[N];
void dfs(int x){
	b[x]=1,w+=d[x]&1;
	for(int i=he[x],j;i;i=ne[i])if(!b[j=to[i]])dfs(j);
}
int main(){
	int n,m,i,j,t=0,s=0;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&i,&j),++d[i],++d[j];
		ne[++t]=he[i],to[t]=j,he[i]=t;
		ne[++t]=he[j],to[t]=i,he[j]=t;
	}
	for(i=1,t=-1;i<=n;++i)if((he[i]||i==1)&&!b[i]){
		w=0,dfs(i),s+=w/2;
		if(w)t=0;else if(++s,~t)t=0;else t=1;
	}
	printf("%d",t?0:s);
	return 0;
}