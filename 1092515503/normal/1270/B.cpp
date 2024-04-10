#include<bits/stdc++.h>
using namespace std;
int T,n,a[200100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		bool flag=false;
		for(int i=1,x;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1){
				if(abs(a[i]-a[i-1])>1){
					if(flag)continue;
					puts("YES");
					printf("%d %d\n",i-1,i);
					flag=true;
				}
			}
		}
		if(!flag)puts("NO");
	}
	return 0;
}