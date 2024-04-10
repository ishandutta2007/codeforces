#include <bits/stdc++.h>

#define maxn 110

#define maxK 4100

#define ll long long

#define pb push_back

#define pii pair<int,int>

#define mod 1000000007 

#define debug(args...) fprintf(stderr,args)

using namespace std;



main(){

	int nt;
	scanf("%d",&nt);
	while(nt--){

		int n;
		scanf("%d",&n);

		int mx = 0, s = 0;
		for(int i=0,a;i<n;i++){
			scanf("%d",&a);
			mx = max(mx,a);
			s += a;
		}

		if(2*mx > s || s%2 == 1)
			printf("T\n");
		else
			printf("HL\n");

	}

}