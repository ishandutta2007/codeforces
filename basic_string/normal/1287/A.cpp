//
#include<bits/stdc++.h>
using namespace std;
char c[10009];
int main(){
	register int T,n,i,s,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",c);
		i=t=s=0;
		while(c[i]=='P'&&i<n)++i;
		if(i==n){
			printf("%d\n",0);
			continue;
		}
		for(;i<n;++i){
			if(c[i]=='A')t=t>s?t:s,s=0;
			else ++s;
		}
		t=t>s?t:s;
		printf("%d\n",t); 
	}
	return 0;
}