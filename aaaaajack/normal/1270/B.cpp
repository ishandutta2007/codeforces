#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,x;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		bool flag=false;
		for(int i=0;i<n-1;i++){
			if(abs(a[i+1]-a[i])>=2){
				puts("YES");
				printf("%d %d\n",i+1,i+2);
				flag=true;
				break;
			}
		}
		if(!flag) puts("NO");
	}
	return 0;
}