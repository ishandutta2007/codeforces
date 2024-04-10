#include <bits/stdc++.h>

#define maxn 400400

#define pb push_back

#define debug 

#define ll long long

#define pii pair<int,int>

using namespace std;



char s[maxn];



int a[maxn];

int b[maxn];



int v[maxn];



main(){



	int n;

	scanf("%d",&n);



	int lo = 0, hi = 1e7;



	while(lo < hi){

		debug("lo %d hi %d\n",lo,hi);

		int mid = (lo+hi)/2;
		if(mid == 0){lo = 1;break;}

		printf("? %d\n",mid);

		fflush(stdout);

		int ans;

		scanf("%d",&ans);

		if(ans == 1) hi = mid;

		else lo = mid+1;

	}



	int S = lo - (n-1);



	int resp = lo;



	for(int i=2;i<=n;i++){



		int L = S + (n-i);

		int R = S + (n-1);



		int x;

		for(int j=L;j<=R;j++)

			if(j%i == 0)

				x = j;



		printf("? %d\n",x/i);

		fflush(stdout);



		int ans;

		scanf("%d",&ans);



		if(ans == i) resp = min(resp,x);

	

	}



	printf("! %d\n",resp);

	fflush(stdout);



}