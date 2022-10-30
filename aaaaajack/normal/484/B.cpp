#include<cstdio>
#include<algorithm>
#define N 200100
#define M 1000001
using namespace std;
int a[N];
bool b[M];
int main(){
	int n,i,j,ans=0;
	int *tmp,*pre;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=true;
	}
	sort(a,a+n);
	n=unique(a,a+n)-a;
	for(i=0;i<n;i++){
		pre=a+i;
		for(j=2*a[i];pre!=a+n-1;j+=a[i],pre=tmp){
			tmp=lower_bound(a,a+n,j);
			tmp--;
			if(tmp>pre){
				ans=max(ans,*tmp%a[i]);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}