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
#define eps 1e-8
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 500500

using namespace std;

pii v[maxn];
int t[maxn];

main(){

		set<int> st;
		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			st.insert(i);
			scanf("%d",&v[i].first);
			t[i] = v[i].first;
			v[i].second = i;
		}

		sort(v,v+n);
		reverse(v,v+n);

		int low = v[0].second, up = v[0].second;

		long long ans = 0;

		for(int i=1;i<n;i++){

			if(st.find(v[i].second) == st.end()) continue;

			int p = v[i].second;

			if(p > up)
				up = p;
			else if(p < low)
				low = p;
			else assert(0);

			int last;
			int f = 0;

			if(*++st.find(low) != up)
				ans += min(t[low],t[up]);

			debug(": %d ~ %d\n",low,up);
			
			for(set<int> :: iterator it = ++st.find(low); *it != up;){

				debug("*it = %d\n",*it);
				if(f++){
					if(t[*it] > min(t[low],t[up])) ans += min(t[low],t[up]);
					else if(last > min(t[low],t[up])) ans += min(t[low],t[up]);
					else ans += max(last,t[*it]);
				}
				last = t[*it];
				set<int> :: iterator aux = it;
				aux++;
				st.erase(it);
				it = aux;

			}

		}

		printf("%I64d\n",ans);

}