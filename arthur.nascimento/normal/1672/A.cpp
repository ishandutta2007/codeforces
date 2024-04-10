#include <bits/stdc++.h>
#define maxn 400400
#define pb push_back
#define debug 
#define mid ((ini+fim)/2)
#define ll long long
#define pii pair<int,int>

char s[maxn];

main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n;
		scanf("%d",&n);

		int tot = 0;

		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			tot += a-1;
		}

		if(tot%2 == 1) printf("errorgorn\n");
		else printf("maomao90\n");

	}

}