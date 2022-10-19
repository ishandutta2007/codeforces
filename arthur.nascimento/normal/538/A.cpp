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

char s[12] = "CODEFORCES";
char v[110];

main(){

		int ok = 0;

		scanf(" %s",v);

		int n = strlen(v);
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++){

				int u = 0;
				int t = 1;
				
				for(int k=0;k<n;k++) if(k < i || k > j){
					if(u == 10)t=0;
					if(v[k] != s[u])t = 0;
					u++;
				}

				if(u != 10)t = 0; 
				if(t)ok = 1;
				

			}

		if(ok)printf("YES\n");
		else printf("NO\n");

}