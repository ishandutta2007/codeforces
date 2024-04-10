#include <iostream>
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

#define INF (1<<30)
#define pii pair<int,int>
#define eps 1e-9

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

using namespace std;

char ch[100100];

set<unsigned long long>ans;

int bsearch(unsigned long long b,unsigned long long init,unsigned long long fim,unsigned long long n){

	
	unsigned long long meio = (init + fim)/2;

	if(init +1 == fim)
		return max(bsearch(b,init,init,n), bsearch(b,fim,fim,n));

	if(n % meio == 0 && b + meio == n / meio)
		return meio;

	if(init == fim)
		return -1;
	
	if(b + meio > n / meio)
		return bsearch(b,init,meio,n);

	return bsearch(b,meio,fim,n);
	


}

main(){

   unsigned long long n;
   cin >> n;

	unsigned long long y = sqrt(8*n + 1);

	if( (y+1)*(y+1) == 8*n + 1)
		y++;
	
	if(y*y == 8*n + 1)
		if( ((y+1)/2) % 2 == 1)
			ans.insert((y+1)/2);

   unsigned long long last = 0;

   for(unsigned long long i=2;i;i*=2){

	if(i < last)break;
	if(i > n+1)break;
	last = i;

	unsigned long long r = bsearch(2*i-3,1,100000000000LL,2*n);
	
		
		if(r+1)
			if(r % 2)
				ans.insert(i*r);
			
		
	
   	}
   

	for(set<unsigned long long> :: iterator it = ans.begin(); it != ans.end(); it++)
		cout << (*it) << endl;
   
	if(ans.empty())
		printf("-1\n");
    
}