#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=109,N=2e5+9;
int a[M],k;
ll n,f[M][N];
bool v[M][N];
ll dfs(int x,ll s){
	if(x==k)return 0;
	if(s<N&&v[x][s])return f[x][s];
	ll u=s/a[x],w=u+dfs(x+1,s)-dfs(x+1,u);
	if(s<N)return v[x][s]=1,f[x][s]=w;
	return w;
}
int main(){
	int i;
	scanf("%lld%d",&n,&k);
	for(i=0;i<k;++i)scanf("%d",a+i);
	sort(a,a+k,greater<int>()),printf("%lld",n-dfs(0,n));
	return 0;
}