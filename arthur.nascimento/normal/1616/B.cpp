#include <bits/stdc++.h>

 

#define maxn 400400

#define pb push_back

#define debug 

#define mid ((ini+fim)/2)

#define ll long long

#define pii pair<int,int>

 

using namespace std;

int v[maxn];

char s[maxn];


main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n;
		scanf("%d",&n);
		scanf(" %s",s);

		int eq = 0;

		if(n > 1 && s[0] == s[1]) eq = 1;

		if(eq){
			printf("%c%c\n",s[0],s[0]);
			continue;
		}

		int i = 0;
		while(i+1 < n && s[i+1] <= s[i]) i++;

		for(int j=0;j<=i;j++) printf("%c",s[j]);
		for(int j=i;j>=0;j--) printf("%c",s[j]);
		printf("\n");

	}

}