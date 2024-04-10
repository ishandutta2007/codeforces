#include<bits/stdc++.h>
using namespace std;
const int N=1e6+3;
basic_string<int>g[N];
bool f[N];
void dfs(int x){f[x]=1;for(int i:g[x])if(!f[i])dfs(i);}
int main(){
	int n,m,i,j,k,o=0;
	long long s;
	scanf("%d%d",&n,&m),memset(f,1,n+1);
	for(k=0;k<m;++k){
		scanf("%d%d",&i,&j),f[i]=f[j]=0;
		if(i==j)++o;
		else g[i]+=j,g[j]+=i;
	}
	dfs(i);
	for(i=1;i<=n;++i)if(!f[i])puts("0"),exit(0);
	s=o*(o-1ll)/2+o*1ll*(m-o);
	for(i=1;i<=n;++i)j=g[i].size(),s+=j*(j-1ll)/2;
	printf("%lld",s);
	return 0;
}