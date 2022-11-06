#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int n,q,a[N],t[N],d[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int o,p,x;scanf("%d",&o);
		if(o==1)scanf("%d%d",&p,&x),a[p]=x,t[p]=i;
		else scanf("%d",&x),d[i]=x;
	}
	for(int i=q-1;i>=0;i--)d[i]=max(d[i],d[i+1]);
	for(int i=1;i<=n;i++)printf("%d ",max(a[i],d[t[i]]));
	return 0;
}