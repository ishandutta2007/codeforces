#include<bits/stdc++.h>
using namespace std;
const int N=5009;
int x[N],y[N];
bool f[N];
long long pf(int x){return x*1ll*x;}
int main(){
	int n,o=1,u,i,j;
	long long v,w;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
	for(i=1,printf("1 ");i<n;printf("%d ",o=u),++i){
		for(f[o]=j=1,v=0;j<=n;++j)if(!f[j]&&(w=pf(x[j]-x[o])+pf(y[j]-y[o]))>v)v=w,u=j;
	}
	return 0;
}