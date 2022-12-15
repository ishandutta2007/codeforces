#include <stdio.h>
#include <algorithm>

int n,m;
int arr[100000];

int main(){
	int min;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
		min=(i==0)?arr[i]:std::min(arr[i],min);
	}
	for(int i=0;i<n;i++)
		arr[i]-=min;

	long long cnt=0;
	for(int i=0;i<n;i++) {
		if(arr[i]%m){
			printf("-1\n");
			return 0;
		}
		cnt+=arr[i]/m;
	}
	printf("%lld\n",cnt);

	return 0;
}