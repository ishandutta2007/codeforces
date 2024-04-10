#include<cstdio>
#include<algorithm>
using namespace std;
int t,a[5],ans,tot,pus;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a[1],&a[2],&a[3],&ans);
		sort(a+1,a+4);
		ans-=a[3]-a[1]+a[3]-a[2];
		if(ans<0||ans%3) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}