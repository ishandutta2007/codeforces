#include <stdio.h>

int n,t,k;
int arr[200001];
int idx_chi[200001];

int main()
{
	scanf("%d %d %d", &n,&t, &k);

	int sum=0, ne_lf=0;
	for(int i=1;i<=t;i++){ 
		scanf("%d",arr+i);
		sum+=arr[i];
		if(i!=1 && arr[i-1]>arr[i])
			ne_lf+=arr[i-1]-arr[i];
	}

	ne_lf+=arr[t];
	if(sum!=n-1 || sum-(t-1)<k || ne_lf>k) {
		printf("-1\n");
		return 0;
	}

	for(int i=1;i<t;i++){
		idx_chi[i]=arr[i];
		if(arr[i]>arr[i+1]){
			idx_chi[i]=arr[i+1];
			k-=arr[i]-arr[i+1];
		}
	}

	k-=arr[t];
	for(int i=1;i<t;i++) {
		if(k==0) {
			break;
		}
		if(k>idx_chi[i]-1) {
			k-=idx_chi[i]-1;
			idx_chi[i]=1;
		}
		else {
			idx_chi[i]-=k;
			break;
		}
	}

	printf("%d\n",n);
	for(int i=1;i<=arr[1];i++) 
		printf("%d %d\n", 1, 1+i);

	sum=1;
	for(int i=1;i<t;i++) {
		int idx=1;
		for(int j=1;j<=arr[i+1];j++) {
			printf("%d %d\n", sum+idx, sum+arr[i]+j);
			if(idx<idx_chi[i]) idx++;
		}
		sum+=arr[i];
	}

	return 0;
}