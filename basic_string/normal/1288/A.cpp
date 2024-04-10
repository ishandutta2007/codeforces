#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,n,d,i,l;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&d),l=sqrt(d)*1.5+100;
		for(i=0;i<=l;++i){
			if(d*1.0/(i+1)+i<n+1e-9){
				puts("YES");
				goto ggg;
			}
		}
		puts("NO");
		ggg:;
	}
	return 0;
}