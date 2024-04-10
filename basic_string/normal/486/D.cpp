#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=2003,M=4003,O=2003;
int he[N],to[M],ne[M],v[N];
long long sum;
bool b[N],f[N];
vector<int>vv[O];
int dfs(int x){
	int w=1,i=he[x],j;
	for(b[x]=0;i;i=ne[i])if(b[j=to[i]])w=w*1ll*dfs(j)%P;
	return sum+=w,w+1;
}
int main(){
	int d,n,i,j,k,t=0,ans=0;
	scanf("%d%d",&d,&n);
	for(i=1;i<=n;++i)scanf("%d",v+i),vv[v[i]].push_back(i);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	for(i=0;i<O;++i)if((k=vv[i].size())){
		memset(b,1,n+1);
		for(j=1;j<=n;++j)if(v[j]<i||v[j]>i+d)b[j]=0;
		for(j=1;j<=n;++j)if(b[j])dfs(j);
		memset(b,1,n+1),ans=(ans+sum)%P,sum=0;
		for(j=1;j<=n;++j)if(v[j]<i||v[j]>i+d)b[j]=0;
		for(j=0;j<k;++j)b[vv[i][j]]=0;
		for(j=1;j<=n;++j)if(b[j])dfs(j);
		ans=(ans-sum)%P,sum=0;
	}
	printf("%d",(ans+P)%P);
	return 0;
}