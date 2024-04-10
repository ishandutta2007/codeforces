#include<bits/stdc++.h>
using namespace std;
const int N=3009;
int he[N],to[N<<1],len[N<<1],ne[N<<1],ans2;
int dfs(int x,int y,int z){
	ans2=min(ans2,z);
	int r=0;
	for(int i=he[x],j;i;i=ne[i]){
		j=to[i];
		if(j==y)continue;
		r+=dfs(j,x,z-len[i])+(len[i]==1); 
	}
	return r;
}
int main(){
	int n,i,j,k,t=0,ans=1e9,ans1;
	scanf("%d",&n);
	if(n==1)return puts("0"),0;
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,len[t]=-1,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=1,he[k]=t;
	}
	for(i=1;i<=n;++i)for(j=he[i];j;j=ne[j])if(j&1)ans2=0,ans1=dfs(i,to[j],0)+ans2,ans2=0,ans1+=dfs(to[j],i,0)+ans2,ans=min(ans,ans1);
	printf("%d",ans);
	return 0;
}