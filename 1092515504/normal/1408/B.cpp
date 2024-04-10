#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[110],diff;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),m--,diff=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=2;i<=n;i++)diff+=(a[i]-a[i-1]>=1);
		if(!diff)puts("1");
		else if(!m)puts("-1"); 
		else printf("%d\n",(diff-1)/m+1); 
	}
	return 0;
}