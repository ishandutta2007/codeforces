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

	
		scanf("%s",s);
		int n = strlen(s);

		int ok = 1;
		int sum = 0;

		for(int i=0;i<n;i++){
			if(s[i] == 'A') sum++;
			else sum--;
			if(sum < 0) ok = 0;
		}

		if(s[n-1] == 'A') ok = 0;

		if(ok) printf("YES\n");
		else printf("NO\n");

	}

}