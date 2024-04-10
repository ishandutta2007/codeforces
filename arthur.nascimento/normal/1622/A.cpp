#include <bits/stdc++.h>

 

#define maxn 400400

#define pb push_back

#define debug 

#define mid ((ini+fim)/2)

#define ll long long

#define pii pair<int,int>

 

using namespace std;


main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int v[3];
		for(int i=0;i<3;i++) scanf("%d",v+i);
		sort(v,v+3);

		if(v[0] == v[1] && v[2]%2 == 0) printf("YES\n");
		else if(v[1] == v[2] && v[0]%2 == 0) printf("YES\n");
		else if(v[2] == v[0] + v[1]) printf("YES\n");
		else printf("NO\n");

		
	}

}