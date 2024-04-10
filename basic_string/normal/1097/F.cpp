#include<bits/stdc++.h>
using namespace std;
const int N=7009;
bitset<N>f[N],g[N],a[100009];
bool b[N];
int p[N],u[N];
int main(){
	int q,i,j,k,t=0;
	for(i=2,scanf("%*d%d",&q),u[1]=1;i<N;++i){
		if(!b[i])u[p[++t]=i]=1;
		for(j=1;j<=t&&(k=i*p[j])<N;++j)if(b[k]=1,i%p[j])u[k]=u[i];else break;
	}
	for(i=1;i<N;++i)for(j=i;j<N;j+=i)f[j][i]=1,g[i][j]=u[j/i];
	while(q--){
		scanf("%d%d%d",&i,&j,&k);
		if(i==1)a[j]=f[k];
		else if(i==2)scanf("%d",&i),a[j]=a[k]^a[i];
		else if(i==3)scanf("%d",&i),a[j]=a[k]&a[i];
		else putchar((a[j]&g[k]).count()%2+'0');
	}
	return 0;
}