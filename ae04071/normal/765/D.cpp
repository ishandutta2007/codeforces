#include <stdio.h>

int n, arr[100001];
bool self[100001];

int num[1000001], h[1000001];

int main()
{
	scanf("%d",&n);

	int cnt=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",arr+i);
		if(i==arr[i]) {
			self[i]=true;
			cnt++;
			num[i]=cnt;
			h[cnt]=i;
		}
	}

	for(int i=1;i<=n;i++) {
		if(!self[i]) {
			if(!self[arr[i]])  {
				printf("-1\n");
				return 0;
			}
			num[i]=num[arr[i]];
		}
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		printf("%d ",num[i]);
	puts("");
	for(int i=1;i<=cnt;i++)
		printf("%d ",h[i]);
	puts("");

	return 0;
}