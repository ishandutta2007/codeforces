#include<bits/stdc++.h>
using namespace std;
enum{N=1009};
int a[N][N],w[N],p[N];
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j;
	for(cin>>n,i=1;i<=n;++i)cin>>w[i],p[i]=i;
	for(sort(p+1,p+n+1,[](int x,int y){return w[x]>w[y];}),i=1;i<=n;++i)for(j=0;j<w[p[i]];++j)a[(i+j)%(n+1)][p[i]]=1;
	for(cout<<n+1<<'\n',i=0;i<=n;cout<<'\n',++i)for(j=1;j<=n;++j)cout<<a[i][j];
	return 0;
}