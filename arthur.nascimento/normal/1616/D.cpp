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

		for(int i=0;i<n;i++) scanf("%d",v+i);

		int x;
		scanf("%d",&x);

		for(int i=0;i<n;i++) v[i] -= x;

		int ans = 0;

		ll mn = 1e15;

		for(int i=0;i<n;i++){

			if(mn + v[i] < 0){
				ans++;
				mn = 1e15;
			}
			else {
				mn = min((ll)v[i], mn+v[i]);
			}
			
		}

		printf("%d\n",n-ans);

	}

}