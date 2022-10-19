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

using namespace std;

int T[maxn];

void update(int idx){
	idx++;
	while(idx < maxn){
		T[idx]++;
		idx += idx&-idx;
	}
}

int query(int idx){
	idx++;
	int ret = 0;
	while(idx){
		ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}

int ans[maxn];

main(){

		int n;
		scanf("%d",&n);

		vector<pii> v;

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			v.pb(pii(u,i+1));
		}

		sort(v.begin(), v.end());

		int ptr = 0;

		for(int i=0;i<n;i++){

			int u = v[i].second;
			while(ptr < i && v[ptr].first < v[i].first){
				update(v[ptr].second);
				ptr++;
			}

			debug("u=%d\n",u);

			for(int j=1;j<n;j++){

				if((long long)j*(v[i].second-1)+2 > n) break;

				int A = j*(v[i].second-1)+2;
				int B = j*v[i].second + 1;
				B = min(B,n);
				debug("j=%d %d..%d\n",j,A,B);

				ans[j] += query(B) - query(A-1);

			}


		}

		for(int i=1;i<n;i++)
			printf("%d ",ans[i]);

}