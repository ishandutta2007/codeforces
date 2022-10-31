#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,l,r,x,ans=0;
	int c[20],i,j;
	scanf("%d%d%d%d",&n,&l,&r,&x);
	for(i=0;i<n;i++) scanf("%d",&c[i]);
	sort(c,c+n);
	for(i=1;i<(1<<n);i++){
		int sum=0,mn=1e9,mx=0;
		for(j=0;j<n;j++){
			if(i&(1<<j)){
				sum+=c[j];
				if(c[j]>mx) mx=c[j];
				if(c[j]<mn) mn=c[j];
			}
		}
		if(sum>=l&&sum<=r&&mx-mn>=x) ans++;
	}
	printf("%d\n",ans);
	return 0;
}