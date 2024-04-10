#include <iostream>
#include <algorithm>
using namespace std;
int arr[200005];
int main()
{
	int n,one=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		one+=(arr[i]==1);
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	if (one && one!=n)
	swap(arr[1],arr[n-one]);
	for (int i=0;i<n;i++)
	printf("%d ",arr[i]);
}