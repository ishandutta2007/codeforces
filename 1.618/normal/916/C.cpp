#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define inf_prime 209987
#define inf 999999999

using namespace std;
typedef long long ll;

int n,m;
int main(){
	scanf("%d%d",&n,&m);
	
	if(n==2){
		printf("2 2\n1 2 2\n");
		return 0;
	}
	
	printf("2 209987\n");
	printf("1 %d 2\n",n);
	for(int i=2;i<n-1;i++){
		printf("%d %d 2\n",i,n);
	}
	int rem = inf_prime - 2*(n-2);
	printf("%d %d %d\n",n-1,n,rem);
	int cur = n-1;
	bool f = 0;
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n-1;j++){
			if(cur == m){
				f = 1;
				break;
			}
			printf("%d %d %d\n",i,j,inf);
			cur++;
		}
		if(f) break;
	}
	
	return 0;
}