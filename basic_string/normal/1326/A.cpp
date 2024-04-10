#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			puts("-1");
			continue;
		}
		putchar('5');
		for(int i=1;i<n;++i)putchar('7');
		puts("");
	}
	return 0;
}