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
#define maxn 200200
#define mod 1000000007

typedef long long ll;
using namespace std;

int T[maxn];

void update(int idx){
	idx++;
	while(idx < maxn){
		T[idx]++;
		idx += idx&-idx;
	}
}

int sum(int idx){
	idx++;
	int ret = 0;
	while(idx){	ret += T[idx];
		idx -= idx&-idx;
	}
	return ret;
}

int v[maxn];

main(){

	int n,k;
	scanf("%d%d",&n,&k);

	for(int i=0;i<n;i++)
		v[i] = i;

	for(int i=0;i<min(k,n/2);i++)
		swap(v[i],v[n-i-1]);

	ll ans = 0;

	for(int i=n-1;i>=0;i--){
		ans += sum(v[i]);
		update(v[i]);
	}

	cout << ans << endl;

}