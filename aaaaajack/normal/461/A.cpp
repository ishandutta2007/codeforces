#include<cstdio>
#include<algorithm>
#include<functional>
#define N 300100
using namespace std;
long long a[N];
int main(){
	int n,i;
	long long ans;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%I64d",&a[i]);
	}
	sort(a,a+n,greater<long long>());
	for(i=1;i<n;i++) a[i]+=a[i-1];
	ans=a[n-1];
	for(i=1;i<n;i++) ans+=a[i];
	printf("%I64d\n",ans);
	return 0;
}