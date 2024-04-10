#include<bits/stdc++.h>
using namespace std;
enum{N=100009};
basic_string<int>g[N];
bool b[N];
int o;
void dfs(int x){
	b[x]=1,++o;
	for(int i:g[x])if(!b[i])dfs(i);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,p,i,j,c=0,s=1;
	cin>>n>>m>>p;
	while(m--)cin>>i>>j,g[i]+=j,g[j]+=i;
	for(i=1;i<=n;++i)if(!b[i])o=0,dfs(i),++c,s=s*1ll*o%p;
	if(c==1)cout<<1%p;
	else{
		for(i=c-2;i;--i)s=s*1ll*n%p;
		cout<<s;
	}
}