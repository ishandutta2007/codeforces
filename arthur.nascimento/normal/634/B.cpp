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

long long s, x;

long long dp[51][2];

ll get(int pos,int c){
	if(dp[pos][c]+1)
		return dp[pos][c];
	if(pos == 50){
		if(c == 0)
			return 1;
		return 0;
	}

	ll X = x & (1LL<<pos);
	ll S = s & (1LL<<pos);
	X = X ? 1 : 0;
	S = S ? 1 : 0;

	ll ret = 0;
	for(int a=0;a<2;a++)
		for(int b=0;b<2;b++){
			if((a^b) != X)
				continue;
			if((a+b+c)%2 != S)
				continue;
			if(pos == 0)
				debug("!! %d %d\n",a,b);
			ret += get(pos+1,(a+b+c)/2);
		}

	debug("dp %d %d = %d\n",pos,c,ret);
	return dp[pos][c] = ret;

}

main(){

	for(int i=0;i<=50;i++)
		for(int j=0;j<2;j++)
			dp[i][j] = -1;

	cin >> s >> x;

	ll ans = get(0,0);
	if(s == x)
		ans -= 2;
	cout << ans << endl;

}