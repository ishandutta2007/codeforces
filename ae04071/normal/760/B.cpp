#include <stdio.h>

int n, m, k;

bool Check(int c)
{
	long long sum=0;
	long long tmp=c-1;
	sum+=c;
	long long len=k-1;
	if(len==tmp) {
		sum+=tmp*(tmp+1)/2;
	}
	else if(len<tmp) {
		long long t=tmp-len;
		sum+=tmp*(tmp+1)/2-t*(t+1)/2;
	}
	else {
		long long t= len-tmp;
		sum+=tmp*(tmp+1)/2+t;
	}

	len=n-k;
	if(len==tmp) {
		sum+=tmp*(tmp+1)/2;
	}
	else if(len<tmp) {
		long long t=tmp-len;
		sum+=tmp*(tmp+1)/2-t*(t+1)/2;
	}
	else {
		long long t= len-tmp;
		sum+=tmp*(tmp+1)/2+t;
	}

	return sum<=m;
}

int main()
{
	scanf("%d %d %d",&n,&m,&k);
	int lo=1, up=1e9+1;
	while(up-lo>1) {
		int md=(lo+up)/2;
		if(Check(md)) {
			lo=md;
		}
		else
			up=md;
	}
	printf("%d\n",lo);

	return 0;
}