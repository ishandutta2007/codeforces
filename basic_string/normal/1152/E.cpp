#include<bits/stdc++.h>
using namespace std;
#define GG puts("-1"),exit(0);
map<int,int>mp;
const int N=1e5+3,M=2e5+3;
int b[N],st[N],tp,he[N],to[M],ne[M],d[N],a[N];
bool f[N];
void dfs(int x){for(int i,j;i=he[x];)if(he[x]=ne[i],!f[j=i>>1])f[j]=1,dfs(to[i]),st[++tp]=i;}
int main(){
	int m,i,j,k,n=0,t=1;
	scanf("%d",&m),--m;
	for(i=1;i<=m;++i)if(scanf("%d",b+i),!mp[b[i]])a[mp[b[i]]=++n]=b[i];
	for(i=1;i<=m;++i){
		scanf("%d",&j);
		if(j<b[i])GG
		if(!mp[j])a[mp[j]=++n]=j;
		j=mp[j],k=mp[b[i]],++d[j],++d[k];
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	for(i=1,j=0;i<=n;++i)if(d[i]&1)++j;
	if(j>2)GG
	if(j==2){for(i=1;i<=n;++i)if(d[i]&1){dfs(i);break;}}
	else dfs(i=1);
	if(tp<m)GG
	for(printf("%d ",a[i]),i=tp;i;--i)printf("%d ",a[to[st[i]]]);
	return 0;
}