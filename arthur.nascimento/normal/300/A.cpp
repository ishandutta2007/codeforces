#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define debug
#define eps 1e-9
using namespace std;

main(){
	
	int qqr_neg = 0;
	
	int n;
	scanf("%d",&n);
	
	int v[n];
	int pos = 0;
	
	for(int i=0;i<n;i++){
		scanf("%d",v+i);
		
		if(v[i]>0)pos++;
	}
	
	sort(v,v+n);
	
	if(v[n-1] <= 0){
	
		printf("1 %d\n",v[0]);	
		printf("2 %d %d\n",v[1],v[2]);
		printf("%d ",n-3);
		for(int i=3;i<n;i++)
			printf("%d ",v[i]);
		printf("\n");
	
		return 0;
		
	}
	
	printf("1 %d\n",v[0]);
	printf("1 %d\n",v[n-1]);
	printf("%d ",n-2);
	for(int i=1;i<n-1;i++)
		printf("%d ",v[i]);
		

	
	}