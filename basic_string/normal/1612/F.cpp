#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
unordered_set<int>s[N];
int ans=1e9,n,m;
void dfs(int x,int y,bool a,bool b,int w){
	int z=x+y+s[x].count(y);
	if(z>=n&&!b)return dfs(n,y,0,1,w+1);
	if(x+z>=n&&!b)return dfs(x,z,0,0,w+1);
	if(z>=m){ans=min(ans,w);return;}
	if(x==n)return dfs(n,z,0,1,w+1);
	if(a)dfs(z,y,!a,b,w+1);else dfs(x,z,!a,b,w+1);
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int q,i,j,k;
	for(i=1,cin>>n>>m>>q;i<=q;++i){
		if(cin>>j>>k,n>m)swap(j,k);
		s[j].insert(k);
	}
	if(n>m)swap(n,m);
	dfs(1,1,0,n==1,0),dfs(1,1,1,n==1,0),cout<<ans+1;
	return 0;
}