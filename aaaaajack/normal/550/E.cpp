#include<cstdio>
#define N 100100
using namespace std;
int a[N];
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	if(a[n-1]==1){
		printf("NO\n");
	}
	else{
		for(i=0;i<n-1&&a[i]==1;i++);
		if(i==n-1){
			printf("YES\n");
			for(i=0;i<n-1;i++) printf("1->");
			printf("0\n");
		}
		else if(i==n-2){
			printf("NO\n");
		}
		else{
			printf("YES\n");
			for(j=0;j<i;j++){
				printf("1->");
			}
			printf("(0->(");
			for(j=i+1;j<n-2;j++){
				printf("%d->",a[j]);
			}
			printf("%d))",a[n-2]);
			printf("->0\n");
		}
	}
	return 0;
}