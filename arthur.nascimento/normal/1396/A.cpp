#include <bits/stdc++.h>

#define maxn 100100

#define maxK 4100

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define mod 1000000007 

#define debug(args...) fprintf(stderr,args)

using namespace std;


ll v[maxn];


main(){

	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++)
		scanf("%lld",v+i);

	if(n == 1){
		printf("1 1 0 1 1 0 1 1 %lld\n",-v[0]);
		return 0;
	}

	printf("1 %d\n",n);

	for(int i=0;i<n;i++)
		printf("%lld ",-(ll)v[i] * n);

	printf("\n1 %d\n",n-1);

	for(int i=0;i<n-1;i++)
		printf("%lld ",(ll) v[i] * (n-1));

	printf("\n%d %d\n",n,n);

	v[n-1] -= (v[n-1] * n);

	printf("%lld\n",-v[n-1]);

}