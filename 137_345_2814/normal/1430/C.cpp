#include<cstdio>
using namespace std;
int T,n;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int tp=n;
		for(int i=n-1;i>=1;i--)tp=(tp+i+1)/2;
		printf("%d\n",tp);
		tp=n;
		for(int i=n-1;i>=1;i--)printf("%d %d\n",tp,i),tp=(tp+i+1)/2;
	}
}