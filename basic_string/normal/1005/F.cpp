#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,M=4e5+3;
int he[N],to[M],ne[M],d[N],q[N],o,a[N],n,m;
bool b[N];
vector<int>v[N];
void dfs(int x){
	int i;
	if(x>n){
		memset(b+1,0,m);
		for(i=2;i<=n;++i)b[v[i][a[i]]]=1;
		for(i=1;i<=m;++i)putchar(b[i]?'1':'0');
		putchar(10);
		if(--o,!o)exit(0);
		return;
	}
	for(i=v[x].size()-1;~i;--i)a[x]=i,dfs(x+1);
}
int main(){
	int k,i,j,h,t=1;
	scanf("%d%d%d",&n,&m,&o);
	for(k=1;k<=m;++k){
		scanf("%d%d",&i,&j);
		ne[++t]=he[i],to[t]=j,he[i]=t;
		ne[++t]=he[j],to[t]=i,he[j]=t;
	}
	q[1]=1,h=0,t=1;
	while(h!=t){
		i=q[++h];
		for(j=he[i];j;j=ne[j]){
			k=to[j];
			if(!d[k])d[k]=d[i]+1,q[++t]=k;
			if(d[k]==d[i]+1)v[k].push_back(j/2);
		}
	}
	for(i=2,j=1;i<=n;++i){
		if(j*1ll*v[i].size()>=o)goto gg;
		j*=v[i].size();
	}
	o=j;
	gg:;
	printf("%d\n",o);
	dfs(2);
	return 0;
}