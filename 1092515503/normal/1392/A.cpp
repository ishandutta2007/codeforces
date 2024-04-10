#include<bits/stdc++.h>
using namespace std;
int T,n,a[200100],mx;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),mx=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
		bool ok=true;
		for(int i=1;i<=n;i++)ok&=(mx==a[i]);
		printf("%d\n",ok?n:1);
	}
	return 0;
}