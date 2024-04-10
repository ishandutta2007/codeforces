#include<bits/stdc++.h>
using namespace std;
int f[400009];
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main(){
	int n,m,p,q,i,j;
	scanf("%d%d%d",&n,&m,&q);
	p=n+m;
	for(i=1;i<=p;++i)f[i]=i;
	while(q--)scanf("%d%d",&i,&j),f[getf(i)]=getf(j+n);
	for(i=1,j=0;i<=p;++i)if(f[i]==i)++j;
	printf("%d",j-1);
	return 0;
}