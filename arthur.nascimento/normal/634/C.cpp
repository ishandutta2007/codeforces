#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define maxn 300300

typedef long long ll;
using namespace std;

ll va[maxn];
ll vb[maxn];

int T[2][maxn];

void update(int idx,int val,int r){
	idx++;
	while(idx < maxn){
		T[r][idx] += val;
		idx += idx&-idx;
	}
}

ll query(int idx,int r){
	if(idx < 0)	return 0;
	int ret = 0;
	idx++;
	while(idx){
		ret += T[r][idx];
		idx -= idx&-idx;
	}
	return ret;
}

main(){

	int n,k,a,b,q;
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);

	while(q--){

		int t;
		scanf("%d",&t);

		if(t == 1){

			int d,s;
			scanf("%d%d",&d,&s), d--;
			int old = va[d];
			va[d] = min((ll)a,va[d]+s);
			update(d,va[d]-old,0);
			old = vb[d];
			vb[d] = min((ll)b,vb[d]+s);
			update(d,vb[d]-old,1);

		}

		else {

			int d;
			scanf("%d",&d), d--;
			ll ans = query(d-1,1) + query(n,0) - query(d+k-1,0);
			cout << ans << endl;

		}

	}

}