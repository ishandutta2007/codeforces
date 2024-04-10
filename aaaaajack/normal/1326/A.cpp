#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n==1) puts("-1");
		else{
			printf("8");
			for(int i=0;i<n-1;i++) printf("%d",9);
			puts("");
		}
	}
	return 0;
}