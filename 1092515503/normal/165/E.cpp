#include<bits/stdc++.h>
using namespace std;
const int lim=1<<22;
int n,a[1001000],f[lim];
int main(){
	scanf("%d",&n),memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),f[a[i]]=a[i];
	for(int j=0;j<22;j++)for(int i=1;i<lim;i++)if((i&(1<<j))&&f[i^(1<<j)]!=-1)f[i]=f[i^(1<<j)];
	for(int i=1;i<=n;i++)printf("%d ",f[(lim-1)^a[i]]);
	return 0;
}