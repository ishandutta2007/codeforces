#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,t,a[4];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		sort(a+1,a+4);
		printf("%d\n",a[1]+a[3]-a[2]+1);
	}
}