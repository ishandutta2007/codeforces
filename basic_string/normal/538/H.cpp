#include<bits/stdc++.h>
using namespace std;
#define GG  puts("IMPOSSIBLE"),exit(0);
const int N=1e5+3;
basic_string<int>g[N];
int l[N],r[N],c[N];
void dfs(int x){for(int i:g[x])if(!c[i])c[i]=3-c[x],dfs(i);else if(c[i]==c[x])GG}
int main(){
	int t,T,n,m,i,j,n1=2e9,n2=0;
	scanf("%d%d%d%d",&t,&T,&n,&m);
	for(i=1;i<=n;++i)scanf("%d%d",l+i,r+i),n1=min(n1,r[i]),n2=max(n2,l[i]);
	if(n1=min(n1,T-n2),n2=max(n2,t-n1),n1<0)GG
	for(i=1;i<=n;++i)if(l[i]>n1||n1>r[i]){
		if(l[i]>n2||n2>r[i])GG
		else c[i]=2;
	}else if(l[i]>n2||n2>r[i])c[i]=1;
	while(m--)scanf("%d%d",&i,&j),g[i]+=j,g[j]+=i;
	for(i=1;i<=n;++i)if(c[i])dfs(i);
	for(i=1;i<=n;++i)if(!c[i])c[i]=1,dfs(i);
	puts("POSSIBLE"),printf("%d %d\n",n1,n2);
	for(i=1;i<=n;++i)printf("%d",c[i]);
	return 0;
}