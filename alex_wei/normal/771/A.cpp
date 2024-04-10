#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
vector <int> q[N];
int n,m,pd[N];
ll ans;
int dfs(int id){
	int ans=1;
	pd[id]=1;
	for(int i=0;i<q[id].size();i++)
		if(!pd[q[id][i]])
			ans+=dfs(q[id][i]);
	return ans;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		q[u].push_back(v);
		q[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!pd[i]){
			ll cnt=dfs(i);
			ans+=cnt*(cnt-1)/2;
		}
	if(ans!=m)puts("NO");
	else puts("YES");
    return 0;
}