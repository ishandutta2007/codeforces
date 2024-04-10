#include<bits/stdc++.h>
using namespace std;
const int N=200009;
long long w[N],l[N],r[N];
basic_string<int>g[N];
int ans;
void dfs(int x){
	long long sum=0;
	for(int i:g[x])dfs(i),sum+=w[i];
	if(sum<l[x]){
		++ans;
		w[x]=r[x];
	}else w[x]=min(r[x],sum);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	for(cin>>T;T--;){
		cin>>n;
		for(i=1;i<=n;++i)g[i]={};
		for(i=2;i<=n;++i)cin>>j,g[j]+=i;
		for(i=1;i<=n;++i)cin>>l[i]>>r[i];
		ans=0;dfs(1);cout<<ans<<'\n';
	}
}