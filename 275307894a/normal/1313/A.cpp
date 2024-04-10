#include<cstdio>
#include<algorithm>
using namespace std;
int t,a[5],ans;
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d%d%d",&a[1],&a[2],&a[3]);
		sort(a+1,a+4);
		if(a[1]>0) a[1]--,ans++;
		if(a[2]>0) a[2]--,ans++;
		if(a[3]>0) a[3]--,ans++;
		if(a[1]>0&&a[3]>0) a[1]--,a[3]--,ans++;
		if(a[2]>0&&a[3]>0) a[2]--,a[3]--,ans++;
		if(a[1]>0&&a[2]>0) a[1]--,a[2]--,ans++;
		if(a[1]>0&&a[2]>0&&a[3]>0) ans++;
		printf("%d\n",ans);
	}
}