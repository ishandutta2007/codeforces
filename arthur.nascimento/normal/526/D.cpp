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
#define maxn 2002000
#define sq(x) ((x)*(x))	

using namespace std;

int z[maxn];
char str[maxn];

void build(int n){ 
	int L = 0, R = 0;
	z[0] = n;
	for (int i = 1; i < n; i++) {
	  if (i > R) {
 	   L = R = i;
 	   while (R < n && str[R-L] == str[R]) R++;
 	   z[i] = R-L; R--;
 	 } else {
  	  int k = i-L;
  	  if (z[k] < R-i+1) z[i] = z[k];
  	  else {
		  L = i;
		  while (R < n && str[R-L] == str[R]) R++;
   	   z[i] = R-L; R--;
  	  }
 	 }
	}
}

int v[maxn];

main(){

		int n,k;
		scanf("%d%d",&n,&k);

		scanf(" %s",str);		
		build(n);
		for(int i=0;i<n;i++)
			debug("z %d = %d\n",i,z[i]);

		for(int i=1;i*k<=n;i++){

			int ok = 1;
			for(int j=0;j<k;j++)
				if(z[i*j] < i)ok = 0;

			if(!ok) continue;
			debug("i=%d\n",i);
			int a = i*k;
			int b = a + min(i,z[a]);

			debug("mrk %d %d\n",a-1,b-1);
			v[a-1]++;
			v[b]--;

		}
		
		int s = 0;
		for(int i=0;i<n;i++){
			s += v[i];
			if(s)printf("1");
			else printf("0");
		}
		printf("\n");
}