#include <stdio.h>

int n, arr[100];
bool vis[100];

int Cycle(int st)
{
	int l=1;
	int node=arr[st];
	vis[st]=true;
	while(node != st) {

		if(vis[node]) return -1;
	 	l++;
	 	vis[node]=true;
	 	node=arr[node];
	 }
	 return l;
}

long long GCD(long long a, long long b)
{
	int max=(a>b)?a:b, min=(a<b)?a:b;
	while(min != 0) {
		int temp=max%min;
		max = min;
		min=temp;
	}
	return max;
}

long long LCM(long long a, long long b) {
	return a*b/GCD(a,b);
}

int main()
{
	scanf("%d",&n);
	for(int i=0; i<n;i++) {
		scanf("%d", arr+i);
		arr[i]--;
	}

	long long res=1;
	for(int i=0;i<n;i++) {
		if(!vis[i]) {
			long long l = Cycle(i);
			if(l == -1) {
				printf("-1\n");
				return 0;
			}
			if(l%2==0) l/=2;
			res = LCM(res, l);
		}
	}
	printf("%lld\n",res);

	return 0;
}