#include <bits/stdc++.h>
using namespace std;

char s[1010];

main(){

	int nt;
	scanf("%d",&nt);
	while(nt--){
		
		int n;
		scanf("%d",&n);
		
		scanf(" %s",s);
		
		int ans = -1;
		
		for(int i=0;i<n-1;i++)
			if(s[i] != s[i+1]) ans = i;
		
		if(ans == -1)
			printf("-1 -1\n");
		else
			printf("%d %d\n",ans+1,ans+2);
	
	}



}