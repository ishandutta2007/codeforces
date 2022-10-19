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

#define inf (999999999999LL)
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
#define maxn 500500
#define mod 1000000007

using namespace std;

main(){

		long long a,b,c,d;
		cin >> a >> b >> c >> d;
		long double A=a, B=b, C=c, D=d;

		long double low = 0, up = (long double)max(max(abs(a),abs(b)),max(abs(c),abs(d)));

		for(int i=0;i<10000;i++){

			long double mid = (low+up)/2;

			vector<long double> ad;
			ad.pb((A+mid)*(D+mid));
			ad.pb((A+mid)*(D-mid));
			ad.pb((A-mid)*(D+mid));
			ad.pb((A-mid)*(D-mid));
			vector<long double> bc;
			bc.pb((B+mid)*(C+mid));
			bc.pb((B+mid)*(C-mid));
			bc.pb((B-mid)*(C+mid));
			bc.pb((B-mid)*(C-mid));
			sort(ad.begin(), ad.end());
			sort(bc.begin(), bc.end());

			if(ad[3] < bc[0] || ad[0] > bc[3])
				low = mid;
			else
				up = mid;

		}

		printf("%.12lf\n",(double)low);

}