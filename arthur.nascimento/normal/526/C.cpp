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

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;
}

main(){

		long long c,a1,a2,w1,w2;
		cin >> c >> a1 >> a2 >> w1 >> w2;

		long long ans = 0;
		for(int i=0;i<=2000000 && w1*i<=c;i++){
			long long cur = a1 * i;
				cur += a2 * ((c-w1*i)/w2);
				ans = max(ans,cur);
		}

			swap(w1,w2);
			swap(a1,a2);
		for(int i=0;i<=2000000 && w1*i<=c;i++){
			long long cur = a1 * i;
				cur += a2 * ((c-w1*i)/w2);
				ans = max(ans,cur);
		}

		cout << ans << endl;
		return 0;

		
		if(w1 >= 1000){

			
			for(int i=0;w1*i<=c;i++){
				long long cur = a1 * i;
				cur += a2 * ((c-w1*i)/w2);
				ans = max(ans,cur);
			}

			cout << ans << endl;
			return 0;

		}

		int g = gcd(w1,w2);

		int d1 = g / w1;
		int d2 = g / w2;

		long long tt1 = a1 * d1;
		long long tt2 = a2 * d2;

		if(tt1 > tt2){
			swap(d1,d2);
			swap(a1,a2);
			swap(w1,w2);
		}

		for(int i=0;i<=tt1 && w1*i<=c;i++){
			long long cur = a1 * i;
				cur += a2 * ((c-w1*i)/w2);
				ans = max(ans,cur);
		}

		cout << ans << endl;

}