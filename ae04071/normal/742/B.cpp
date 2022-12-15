#include <stdio.h>
#include <algorithm>

int n, arr[100000], x;
long long num[100001];

int main()
{
	scanf("%d %d",&n,&x);
	for(int i=0;i<n;i++) {
		scanf("%d", arr+i);
		num[arr[i]]++;
	}

	long long cnt=0;
	std::sort(arr,arr+n);
	if(x==0) {
		for(int i=1;i<=100000;i++) {
			if(num[i]==2) cnt++;
			else if(num[i]>2) cnt += num[i] * (num[i]-1) /2;
		}
		printf("%lld\n",cnt);
	}
	else {
		for(int i=1;i<=100000;i++) {
			if(num[i]==0)continue;
			int s= x^i;
			if(s<i) continue;
			if(s>100000) continue;
			cnt+=num[i]*num[s];
		}
		printf("%lld\n",cnt);
	}

	return 0;
}