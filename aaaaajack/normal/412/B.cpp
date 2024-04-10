#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int k,n,i;
	int a[200];
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	printf("%d\n",a[n-k]);
}