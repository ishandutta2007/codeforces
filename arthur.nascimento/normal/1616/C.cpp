#include <bits/stdc++.h>

 

#define maxn 400400

#define pb push_back

#define debug 

#define mid ((ini+fim)/2)

#define ll long long

#define pii pair<int,int>

 

using namespace std;

int v[maxn];

main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++)
			scanf("%d",v+i);

		int mx = 2; if(n == 1) mx = 1;

		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){

				int cur = 0;

				double r = (double) (v[j] - v[i]) / (j - i);

				for(int k=0;k<n;k++){
					double need = v[i] + r * (k - i);
					if(fabs(need-v[k]) < 1e-3) cur++;
				}

				mx = max(mx,cur);

			}

		printf("%d\n",n-mx);

	}

}