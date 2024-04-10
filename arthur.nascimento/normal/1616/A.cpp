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

		int n;
		scanf("%d",&n);

		set<int> S;

		for(int i=0;i<n;i++){
			int x;
			scanf("%d",&x);
			if(x < 0) x = -x;
			if(S.find(x) != S.end()) x = -x;
			S.insert(x);
		}

		printf("%d\n",S.size());
	
	}

}