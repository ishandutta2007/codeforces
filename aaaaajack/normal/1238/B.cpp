#include<bits/stdc++.h>
#define N 100100
using namespace std;
int a[N];
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int n,r,x;
		scanf("%d%d",&n,&r);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n,greater<int>());
		n=unique(a,a+n)-a;
		int ans=n;
		for(int i=0;i<n;i++){
			if((a[i]+r-1)/r<=i){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}