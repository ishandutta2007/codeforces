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
#include <complex>

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
#define maxn 2*1100000
#define mod 1000000007

using namespace std;

typedef complex<double> C;

C poly1[maxn], poly2[maxn], val[maxn], result[maxn];

int r[maxn];
int v[maxn];

void fft(int deg, C *rd, C *wr, int step, int w){
	if(deg == 1){
		*wr = *rd;
		return;
	}

	fft(deg/2, rd, wr, 2*step, w);
	fft(deg/2, rd+step, wr+deg/2, 2*step, w);

	C omega = 1, omega_n = exp(C(0, w*2*acos(-1)/deg));

	for(int i = 0; i < deg/2; ++i){
		C x = wr[i], y = wr[i+deg/2];
		wr[i] = x+omega*y;
		wr[i+deg/2] = x-omega*y;
		omega = omega * omega_n;
	}
}

int mul(int d1, int d2){
	int d = d1 + d2;

	while(d & (d-1)) d++;

	for(int i = d1; i < d; ++i)
		poly1[i] = C(0,0);

	for(int i = d2; i < d; ++i)
		poly2[i] = C(0,0);

	fft(d, poly1, val, 1, 1);
	fft(d, poly2, result, 1, 1);

	for(int i = 0; i < d; ++i)
		val[i] *= result[i];

	fft(d, val, result, 1, -1);

	for(int i = 0; i < d; ++i)
		result[i] /= C(d,0);
		
	for(int i=0;i<d;i++)
		r[i] = (int)round(result[i].real());

	return d;
}

main(){

		int n,m;
		scanf("%d%d",&n,&m);

		for(int i=0;i<n;i++){
			int u;
			scanf("%d",&u);
			v[u] = 1;
			poly1[u] = poly2[u] = C(1,0);
		}

		poly1[0] = poly2[0] = 1;

		mul(m,m);

		vector<int> ans;
		int ok = 1;

		for(int i=1;i<m;i++){
			if(v[i] == 0 && r[i] != 0) ok = 0;
			if(r[i] == 2) ans.pb(i);
		}

		if(!ok)
			printf("NO\n");
		else {
			printf("YES\n");
			printf("%d\n",ans.size());
			for(int i=0;i<ans.size();i++)
				printf("%d ",ans[i]);
			printf("\n");
		}

}