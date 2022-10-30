#include<cstdio>
#include<algorithm>
#include<functional>
#define N 100100
using namespace std;
int a[N],b[N];
int main(){
	int m,n,i;
	long long ans,sa=0,sb=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++) scanf("%d",&a[i]),sa+=a[i];
	for(i=0;i<n;i++) scanf("%d",&b[i]),sb+=b[i];
	sort(a,a+m,greater<int>());
	sort(b,b+n,greater<int>());
	if(a[0]>b[0]){
		ans=sb;
		for(i=1;i<m;i++){
			ans+=min((long long)a[i],sb);
		}
	}
	else{
		ans=sa;
		for(i=1;i<n;i++){
			ans+=min((long long)b[i],sa);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}