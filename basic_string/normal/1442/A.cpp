#include<bits/stdc++.h>
using namespace std;
long long a[30009];
int main(){
	int T,n,m,i,j,k;
	long long w=0; 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%lld",a+i);
		w=0;
		for(i=2;i<=n;++i){
			w+=max(a[i-1]-a[i],0ll);
		}
		if(w>a[1])puts("NO");
		else puts("YES");
	}
	return 0;
}