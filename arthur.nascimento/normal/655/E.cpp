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
#define maxn 2002000
#define mod 1000000007

typedef long long ll;
using namespace std;

char str[maxn];

int last[200];
char t[30];

ll dp[200];

main(){

	int n,k;
	scanf("%d%d %s",&n,&k,str);
	int m = strlen(str);

	for(int i='a';i<'a'+k;i++)
		last[i] = -1;
	for(int i=0;i<m;i++)
		last[str[i]] = i;

	vector<pii> v;

	for(int i='a';i<'a'+k;i++)
		v.pb(pii(last[i],i));

	sort(v.begin(), v.end());

	for(int i=0;i<k;i++)
		t[i] = v[i].second;

	for(int i=m;i<m+n;i++)
		str[i] = t[(i-m)%k];

	n += m;

	ll s = 0;

	for(int i=n-1;i>=0;i--){

		ll aux = dp[str[i]];
		dp[str[i]] = s+1;
		s -= aux;
		s += dp[str[i]];
		s %= mod;
		if(s < 0) s += mod;

	}

	cout << ((s+1)%mod) << endl;

}