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
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

bool comp(pii a,pii b){
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

main(){

		vector<pii> v;
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			v.pb(pii(a,b));
		}

		sort(v.begin(),v.end(),comp);

		int last = -1;

		for(int i=0;i<n;i++){

			if(v[i].second >= last) last = v[i].second;
			else last = v[i].first;

		}

		printf("%d\n",last);

}