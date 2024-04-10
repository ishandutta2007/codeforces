#include<cstdio>
#include<algorithm>
#define N 200100
using namespace std;
int a[N];
int main(){
	int n,i;
	bool flag=true;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]+=i;
	}
	sort(a,a+n);
	for(i=1;i<n;i++){
		if(a[i]==a[i-1]) flag=false;
	}
	if(flag){
		for(i=0;i<n;i++){
			printf("%d ",a[i]-i);
		}
		putchar('\n');
	}
	else{
		printf(":(\n");
	}
	return 0;
}