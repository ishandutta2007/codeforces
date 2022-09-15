#include<bits/stdc++.h>
using namespace std;
int arr[101010];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; ++i) scanf("%d",arr+i);
	int maxv = *max_element(arr,arr+N);
	int minv = *min_element(arr,arr+N);
	int ans = N;
	for(int i=0; i<N; i++)
	{
		if(arr[i]== maxv || arr[i] == minv) ans--;
	}
	printf("%d\n",ans);
	return 0;
}