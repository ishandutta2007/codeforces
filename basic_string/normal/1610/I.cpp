#include<bits/stdc++.h>
using namespace std;
enum{N=300009};
basic_string<int>g[N];
int f[N],s[N];
bool b[N];
void dfs(int x,int y){
	f[x]=y;
	for(int i:g[x])if(i^y)dfs(i,x),s[x]^=s[i]+1;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k;
	for(cin>>n,i=1;i<n;++i)cin>>j>>k,g[j]+=k,g[k]+=j;
	for(i=2,dfs(b[1]=1,0),j=s[1];cout<<(j==0)+1,i<=n;++i)for(k=i;!b[k];k=f[k])b[k]=1,j^=s[k]^s[k]+1^1;
	return 0;
}