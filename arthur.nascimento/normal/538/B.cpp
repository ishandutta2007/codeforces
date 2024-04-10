#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define inf (9999999999999999LL)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back	
#define mod 1000000007
#define maxn 10100

using namespace std;

main(){

		int n;
		scanf("%d",&n);

		int mx = 0;

		vector<int> v;
		while(n){
			mx = max(mx,n%10);
			v.pb(n%10);
			n/=10;
		}

		printf("%d\n",mx);

		for(int i=0;i<mx;i++){

			vector<int> a;

			for(int j=0;j<v.size();j++){
				if(v[j]){
					a.pb(1);
					v[j]--;
				}
				else
					a.pb(0);
			}

			reverse(a.begin(), a.end());

			int f = 0;

			for(int j=0;j<a.size();j++){
				if(f || a[j]) printf("%d",a[j]);
				if(a[j]) f = 1;
			}

		printf(" ");

		}

		

}