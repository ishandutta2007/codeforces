#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;
int a[N],b[N];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		b[i]=min(b[i-1]+1,a[i]);
	}
	for(int i=n;i>=1;i--){
		b[i]=min(b[i],b[i+1]+1);
	}
	for(int i=1;i<=n;i++) ans=max(ans,b[i]);
	printf("%d\n",ans);
	return 0;
}