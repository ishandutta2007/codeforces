#include<bits/stdc++.h>
using namespace std;
const int N=1009;
bitset<N>b[N],e[N],u;
bool v[N];
int main(){
	int n,i,j,k,l,t=0;
	scanf("%d",&n);
	if(n==2)puts("1 2"),exit(0);
	for(i=1;i<=n;++i)for(scanf("%d",&k),e[i][i]=1;k--;)scanf("%d",&j),b[i][j]=1;
	for(i=1;i<=n;++i)for(j=1;j<i;++j)if(u=b[i]&b[j],u.count()==2){
		k=u._Find_first(),l=u._Find_next(k);
		if(!e[k][l])e[k][l]=e[l][k]=v[k]=v[l]=1,printf("%d %d\n",k,l),++t;
	}
	if(!t){for(i=2;i<=n;++i)printf("1 %d\n",i);exit(0);}
	if(t==1){
		for(i=1;i<=n;++i)if(b[i].count()<n){
			for(j=1;j<=n;++j)if(!v[j])printf("%d %d\n",j,b[i][j]?k:l);
			exit(0);
		}
	}
	for(i=1;i<=n;++i)if(!v[i]){
		for(j=1,k=N,l=0;j<=n;++j)if(b[j][i]&&b[j].count()<k)k=b[j].count(),l=j;
		for(j=1;j<=n;++j)if(!v[j])b[l][j]=0;
		for(j=1;j<=n;++j)if(v[j]&&b[l]==e[j]){printf("%d %d\n",i,j);break;}
	}
	return 0;
}