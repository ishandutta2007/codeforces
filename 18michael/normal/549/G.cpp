#include<cstdio>
#include<algorithm>
using namespace std;
int n;int a[200002];
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]+=i;
	sort(a+1,a+n+1);for(int i=1;i<=n;++i)a[i]-=i;
	for(int i=1;i<n;++i)if(a[i]>a[i+1])return 0&puts(":(");
	for(int i=1;i<=n;++i)printf("%d ",a[i]);return 0;
}