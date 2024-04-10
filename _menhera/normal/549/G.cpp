#include<cstdio>
#include<algorithm>
using namespace std;
int N;
int arr[200200];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",arr+i);
		arr[i]+=i;
	}
	sort(arr,arr+N);
	for(int i=0;i<N-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			puts(":(");
			return 0;
		}
	}
	for(int i=0;i<N;i++)
		printf("%d ",arr[i]-i);
	return 0;
}