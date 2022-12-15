#include <stdio.h>
#include <queue>

int n, arr[100000];
bool vis[100001];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);

	int sz=n;
	for(int i=0;i<n;i++) {
		vis[arr[i]]=true;
		while(vis[sz]) {
			printf("%d ",sz--);
		}
		printf("\n");
	}
	return 0;
}