#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3,M=6e5+3;
#define ll long long
int he[N],to[M],ne[M],e[N];
ll len[M],d[N];
bool b[N];
priority_queue<pair<ll,int> >q;
int main(){
	int n,m,i,j,k,t=1;
	ll l;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%lld",&j,&k,&l);
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	scanf("%d",&i),q.push({0,i}),memset(d,9,sizeof d),d[i]=0;
	while(!q.empty()){
		i=q.top().second,q.pop();
		if(b[i])continue;
		for(b[i]=1,j=he[i];j;j=ne[j])if(d[k=to[j]]>=(l=d[i]+len[j])){
			d[k]=l,e[k]=j,q.push({-l,k});
		}
	}
	for(l=0,i=1;i<=n;++i)l+=len[e[i]];
	printf("%lld\n",l);
	for(i=1;i<=n;++i)if(e[i])printf("%d ",e[i]/2);
	return 0;
}