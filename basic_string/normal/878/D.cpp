#include<bits/stdc++.h>
using namespace std;
const int N=1e5+19;
bitset<4096>b[N];
int a[N][13],c[13];
int main(){
	int n,m,q,i,j,k,l,t;
	scanf("%d%d%d",&n,&m,&q),t=m;
	for(i=0;i<m;++i)for(j=1;j<=n;++j)scanf("%d",a[j]+i);
	for(i=0;i<m;++i)for(j=(1<<m)-1;~j;--j)b[i+1][j]=j&(1<<i);
	while(q--){
		scanf("%d%d%d",&i,&j,&k);
		if(i==1)b[++t]=b[j]&b[k];
		else if(i==2)b[++t]=b[j]|b[k];
		else{
			for(i=0;i<m;++i)c[i]=i;
			sort(c,c+m,[&](int x,int y){return a[k][x]<a[k][y];});
			for(i=l=0;;++i)if(l|=1<<c[i],b[j][l]){
				printf("%d\n",a[k][c[i]]);
				break;
			}
		}
	}
	return 0;
}