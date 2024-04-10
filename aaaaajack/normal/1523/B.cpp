#include<bits/stdc++.h>
#define N 1100
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a[N];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		printf("%d\n",n*3);
		for(int i=1;i<n;i+=2){
			printf("%d %d %d\n",1,i,i+1);
			printf("%d %d %d\n",2,i,i+1);
			printf("%d %d %d\n",1,i,i+1);
			printf("%d %d %d\n",1,i,i+1);
			printf("%d %d %d\n",2,i,i+1);
			printf("%d %d %d\n",1,i,i+1);
		}
	}
	return 0;
}