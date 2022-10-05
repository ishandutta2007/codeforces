#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
basic_string<int>g[N];
int ans[N],bud[N],yz;
bool f[N];
void dfs(int x,int y){
	bool fl=0,fl2=0;
	int ans1=0,ansb=0,mnans=1e9,w;
	for(int i:g[x])if(i!=y){
		dfs(i,x);fl=1;
		w=bud[i];
		if(f[i]){
			fl2=1;
			if(bud[i])--w;
		}
		ans1+=ans[i],ansb+=w;
		bud[x]+=w;
		mnans=min(mnans,w-ans[i]);
	}
	if(!fl)++yz;
	ans[x]=max(ans1,ansb-mnans);
	if(fl2)++bud[x];else f[x]=1;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,n,i,j,k;
	cin>>T;
	while(T--){
		cin>>n,yz=0;
		for(i=1;i<=n;++i)ans[i]=bud[i]=f[i]=0,g[i]={};
		for(i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
		dfs(1,0);
		cout<<yz-ans[1]<<'\n';
	}
	return 0;
}