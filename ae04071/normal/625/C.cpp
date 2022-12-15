#include <stdio.h>

int n, k;
int res[500][500];

int main()
{
	scanf("%d %d",&n, &k);
	k--;
	int ss=n*n;
	for(int i=0;i<n;i++) {
		for(int j=n-1;j>=k;j--){
			res[i][j]=ss--;
		}
	}

	ss=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<k;j++) {
			res[i][j]=ss++;
		}
	}

	int sum=0;
	for(int i=0;i<n;i++)
		sum+=res[i][k];
	printf("%d\n",sum);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}

	return 0;
}