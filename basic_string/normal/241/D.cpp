#include<bits/stdc++.h>
using namespace std;
const int N=29;
int a[N],b[N],t,n,p;
void dfs(int x,int sum,int yh,int st){
	if(x>t){
		if(sum||yh||!st)return;
		cout<<"Yes\n"<<__builtin_popcount(st)<<'\n';
		for(int i=1;i<=t;++i)if(st>>i&1)cout<<b[i]<<' ';
		exit(0);
	}
	dfs(x+1,sum,yh,st);
	dfs(x+1,(sum*(a[x]<10?10:100)+a[x])%p,yh^a[x],st|(1<<x));
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int i,j;
	for(cin>>n>>p,i=1;i<=n;++i)if(cin>>j,j<26)a[++t]=j,b[t]=i;
	dfs(1,0,0,0),cout<<"No";
	return 0;
}