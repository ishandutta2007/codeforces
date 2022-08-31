#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
int n,m,i,w[100001],deg[100001],M;
set <int> C[100001];
int main()
{
	int a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		a=w[a],b=w[b];
		if(a!=b&&C[a].find(b)==C[a].end()){
			C[a].insert(b);
			C[b].insert(a);
			deg[a]++,deg[b]++;
		}
	}
	a=w[1];
	for(i=1;i<=n;i++){
		if(deg[w[i]]>M)M=deg[w[i]],a=w[i];
		if(deg[w[i]]==M&&a>w[i])a=w[i];
	}
	printf("%d\n",a);
}