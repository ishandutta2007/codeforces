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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<unsigned long long,unsigned long long>
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

int sd(long long u){
	int ret = 0;
	while(u){
		ret += u%10;
		u/=10;
	}
	return ret;
}

long long get(long long a){

	int d = 0;
	long long aux2 = 1;
	while(aux2 <= a){
		aux2 *= 10;
		d++;
	}

	debug("d = %d\n",d);

	long long p10 = 1;
	long long ret = 0;
	long long aux = a;

	for(int i=0;i<d;i++){

		long long cy = a / (p10*10);
		int dig = aux%10;
		aux/=10;
		
		ret += cy * p10 * 45;
		for(int j=0;j<dig;j++)
			ret += p10 * j;

		ret += (long long)dig * (1+a%p10);
		p10 *= 10;

	}

	return ret;
}

main(){

	/*	while(1){
			int k;
			cin >> k;
			cout << get(k) << endl;
		}*/

		long long n;
		scanf("%I64d",&n);

		long long low = 1, up = 100000000000000000LL;

		while(low != up){

			long long mid = (low+up+1)/2;

			long long y = get(mid);
			debug("get %I64d = %I64d\n",mid,y);
			if(y <= n)
				low = mid;
			else
				up = mid-1;

		}
		
		long long a = 1, b = low;
		long long S = get(low);

		while(S != n){

			while(S < n){
				b++;
				S += sd(b);
			}
			while(S > n){
				S -= sd(a);
				a++;
			}

		}

		printf("%I64d %I64d\n",a,b);

}