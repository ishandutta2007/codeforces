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
#define maxn 200200
#define sq(x) ((x)*(x))	

using namespace std;

char str[maxn];

main(){

		int n;
		scanf("%d",&n);

		scanf(" %s",str);

		int ans = 0;
		for(int i=0;i<n;i++)
			for(int k=1;k<n;k++){
				if(i + 4*k > n)continue;
				int u = 1;
				for(int j=i;j<=i+4*k;j+=k)
					if(str[j] != '*')u = 0;
				if(u)ans=1;
			}

		if(ans)printf("yes\n");
		else printf("no\n");

}