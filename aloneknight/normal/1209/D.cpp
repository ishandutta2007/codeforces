#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,ans,f[N];
int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),fnd(u)==fnd(v)?ans++:f[fnd(u)]=fnd(v);
	printf("%d\n",ans);return 0;
}