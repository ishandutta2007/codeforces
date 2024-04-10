#include<bits/stdc++.h>
using namespace std;
const int N=1509;
int a[N][N],b[N][N],c[N],p[N];
bool f[N];
basic_string<int>s,q;
int main(){
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",a[i]+j);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",b[i]+j);
	for(i=1;i<n;++i)for(j=1;j<=m;++j)if(b[i][j]>b[i+1][j])++c[j];
	for(i=1;i<=m;++i)if(!c[i])q+=i;
	while(q.size()){
		k=q.back(),q.pop_back(),s+=k;
		for(i=1;i<n;++i)if(!f[i]&&b[i][k]<b[i+1][k]){
			f[i]=1;
			for(j=1;j<=m;++j)if(b[i][j]>b[i+1][j])if(!--c[j])q+=j;
		}
	}
	reverse(s.begin(),s.end()),iota(p+1,p+n+1,1);
	for(int i:s)stable_sort(p+1,p+n+1,[&](int x,int y){return a[x][i]<a[y][i];});
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(a[p[i]][j]!=b[i][j])puts("-1"),exit(0);
	cout<<s.size()<<'\n';
	for(int i:s)printf("%d\n",i);
	return 0;
}