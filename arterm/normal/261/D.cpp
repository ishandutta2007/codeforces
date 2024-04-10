#include <cstdio>
#include <vector>

#define M 100100

using namespace std;

int n,m,k,t,b[M],d[M];

void read(void){
	scanf("%d%d%d%d",&k,&n,&m,&t);
	t=min(t,min(n,m));	
}

void kill(void){
	for (int i=0; i<n; ++i)
	scanf("%d",b+i);
	
	for (int j=0; j<=m; ++j)
	d[j]=0;
	
	for (int i=0; i<t; ++i)
	for (int j=0; j<n; ++j)
	if (1+d[b[j]-1]>d[b[j]]){
		int x=b[j],k=x+1;
		d[x]=d[x-1]+1;
		while (k<=m && d[k]<d[x])
		d[k++]=d[x];
	}
	
	int ans=0;
	for (int j=0; j<=m; ++j)
	ans=max(ans,d[j]);
	
	printf("%d\n",ans);
	
}

int main()
{
	read();
	for (int i=0; i<k; ++i)
	kill();
	return 0;
}