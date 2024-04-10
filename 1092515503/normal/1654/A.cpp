#include<bits/stdc++.h>
using namespace std;
int T,n,a[1010],mx,smx;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),mx=smx=-1;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(mx<a[i])smx=mx,mx=a[i];
			else smx=max(smx,a[i]);
		}
		printf("%d\n",mx+smx);
	}
	return 0;
}