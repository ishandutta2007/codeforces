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
#define pll pair<long long,long long>
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
 
using namespace std;

pll T[200200];

void update(int idx,int val,int val2){
	idx++;
	while(idx < 200200){
		T[idx].first += val;
		T[idx].second += val2;
		idx += idx&-idx;
	}
}

pll sum(int idx){
	idx++;
	pll ret (0,0);
	while(idx){
		ret.first += T[idx].first;
		ret.second += T[idx].second;
		idx -= idx&-idx;
	}
	return ret;
}

int v[100100];

main(){

		int n,q;
		scanf("%d%d",&n,&q);

		vector<pll> query;
		set<int> st;

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			st.insert(v[i]);
		}

		for(int i=0;i<q;i++){
			int t;
			scanf("%d",&t);
			if(t == 1){
				int a,b;
				scanf("%d%d",&a,&b);
				a--;
				st.insert(b);
				query.pb(pll(a,b));
			}
			else{
				long long a;
				scanf("%I64d",&a);
				query.pb(pll(-1,a));
			}
		}

		map<int,int> mp;

		mp[*(st.begin())] = 0;
		int w = 0;

		for(set<int> :: iterator it = ++st.begin(); it != st.end(); it++)
			mp[*it] = ++w;

		for(int i=0;i<n;i++)
			update(mp[v[i]],v[i],1);

		for(int i=0;i<q;i++){

			if(query[i].first+1){

				int a = query[i].first;
				int b = query[i].second;

				update(mp[v[a]],-v[a],-1);
				update(mp[b],b,1);

				v[a] = b;
				continue;
			}

			long double a=0, b=1e16;

			for(int j=0;j<100;j++){

				long double m = (a+b)/2;

				long long u = (long long)m;

				set<int> :: iterator it = --st.upper_bound(min(1000001000LL,u));

				pll k = sum(mp[*it]);

				long double val = m * k.second - k.first;

				debug("*it = %d mp = %d\n",*it,mp[*it]);
				debug("u = %I64d k = %I64d %I64d\n",u,k.first,k.second);
				debug("val = %lf\n",(double)val);

				if(val >= query[i].second)
					b = m;
				else
					a = m;
			
			}

			printf("%lf\n",(double)a);

		}

}