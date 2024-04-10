#include<cstdio>
#include<algorithm>
#define N 200100
using namespace std;
int a[N];
int main(){
	int n,ans=1023456789;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<n/2;i++){
		if(a[i+n/2]-a[i]<ans) ans=a[i+n/2]-a[i];
	}
	printf("%d\n",ans);
	return 0;
}