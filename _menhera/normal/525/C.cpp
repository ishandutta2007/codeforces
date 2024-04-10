#include<cstdio>
#include<algorithm>
using namespace std;
int N;
long long a[100100];
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%lld",a+i);
	sort(a,a+N);
	reverse(a,a+N);
	long long tom=0;
	long long ans=0;
	for(int i=0;i<N-1;i++)
	{
		if(a[i]>a[i+1]+1) continue;
		if(!tom)
		{
			tom=a[i+1];
			i++;
		}
		else
		{
			ans+=a[i+1]*tom;
			i++;
			tom=0;
		}
	}
	printf("%lld",ans);
}