#include<bits/stdc++.h>
#define N 100100
using namespace std;
pair<int,int> a[N];
int ans[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,x;
		scanf("%d%d%d",&n,&m,&x);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i].first);
			a[i].second=i;
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			ans[a[i].second]=(i%m)+1;
		}
		puts("YES");
		for(int i=0;i<n;i++) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}