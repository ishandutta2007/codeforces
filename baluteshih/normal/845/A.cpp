#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<2*n;i++) scanf("%d",&arr[i]);
	sort(arr,arr+2*n);
	printf("%s\n",arr[n]>arr[n-1] ? "YES" : "NO");
}