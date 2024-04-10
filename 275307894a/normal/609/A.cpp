#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100039],ans,m;
int main(){
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(i=n;i>=1;i--){
		if(a[i]<m) m-=a[i],ans++;
		else {ans++;break;}
	}
	printf("%d",ans);
	return 0;
}