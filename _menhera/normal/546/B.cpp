#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int a[3010];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",a+i);
	sort(a,a+N);
	int ans=0;
	for(int i=1;i<N;i++)
	{
		while(a[i-1]>=a[i])
		{
			a[i]++;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}