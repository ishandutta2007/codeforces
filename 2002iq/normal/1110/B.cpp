#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	for (int i=n-1;i>0;i--)
	arr[i]=arr[i]-arr[i-1]-1;
	sort(arr+1,arr+n);
	int ans=n;
	for (int i=1;i<=n-k;i++)
	ans+=arr[i];
	printf("%d",ans);
}