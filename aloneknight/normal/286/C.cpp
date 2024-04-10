#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,tp,a[N],b[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),a[x]=-a[x];
	for(int i=n;i;i--)if(a[i]!=b[tp])b[++tp]=abs(a[i]),a[i]=-b[tp];else tp--;
	if(tp)puts("NO");
	else 
	{
		puts("YES");
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
	}
	return 0;
}