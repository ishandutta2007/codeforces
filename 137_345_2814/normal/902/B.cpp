#include<cstdio>
using namespace std;
int f[10001],n,v[10001],ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		if(v[f[i]]!=v[i])
		ans++;
	}
	printf("%d\n",ans);
}//233 666