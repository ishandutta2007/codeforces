#include <stdio.h>

int main()
{
	long long n,k,a,b;
	scanf("%lld %lld %lld %lld", &n, &k, &a, &b);

	long long max, min;
	char mach, mich;
	if(a>b) {
		max=a, mach='G';
		min=b, mich='B';
	}
	else {
		max=b, mach='B';
		min=a, mich='G';
	}

	if(max>(min+1)*k) {
		printf("NO\n");
		return 0;
	}

	while(max) {
		long long cnt=0;
		while(cnt<k && max>0) {
			max--;
			printf("%c",mach);
			cnt++;
		}
		cnt=0;
		while(cnt<k && min>0 && min*k>=max) {
			min--;
			printf("%c",mich);
			cnt++;
		}
	}

	return 0;
}