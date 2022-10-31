#include<utility>
#include<algorithm>
#include<cstdio>
#define N 110
using namespace std;
pair<int,int> a[N];
int main(){
	int n,i,j,k,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d%d",&a[i].first,&a[i].second);
	sort(a,a+n);
	j=0;
	while(a[j].first<0) j++;
	if(j<n-j){
		for(k=0;k<2*j+1&&k<n;k++) ans+=a[k].second;
	}
	else{
		for(k=n-1;k>=n-2*(n-j)-1&&k>=0;k--){
			ans+=a[k].second;
		}
	}
	printf("%d\n",ans);
	return 0;
}