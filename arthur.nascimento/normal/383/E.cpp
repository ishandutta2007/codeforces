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

int f[1<<24];

int dp[1<<24];

void print(int mask){
	for(int i=0;i<24;i++) if(mask & (1<<i))
		printf("%c",'a'+i);
}

int get(int mask){

	if(dp[mask]+1)
		return dp[mask];

	if(__builtin_popcount(mask) <= 3){

		int v[3];
		v[0] = mask&-mask;
		mask -= v[0];
		v[1] = mask&-mask;
		mask -= v[1];
		v[2] = mask&-mask;
		mask += v[0]+v[1];

		int ret = 0;

		for(int i=0;i<8;i++){

			int t = 0, ok = 1;
			for(int j=0;j<3;j++) if(i & (1<<j)){
				t += v[j];
				if(v[j] == 0)ok  =0;
			}
			if(ok) ret += f[t];

		}

		/*print(mask);
		debug(" ret %d\n",ret);
		getchar();*/
		return dp[mask] = ret; 
					
	}

	int ret = 0;
	
	int a = mask&-mask;
	mask -= a;
	int b = mask&-mask;
	mask -= b;
	int c = mask&-mask;
	mask += a+b;

	ret = f[a+b+c] + get(mask-a) + get(mask-b) + get(mask-c) - get(mask-a-b) - get(mask-a-c) - get(mask-b-c) + get(mask-a-b-c);

	/*print(mask);
	debug(" ret %d\n",ret);
	getchar();*/
	return dp[mask] = ret;
	
}

main(){

		int n;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			char a,b,c;
			scanf(" %c%c%c",&a,&b,&c), a -= 'a', b -= 'a', c -= 'a';
			f[(1<<a)|(1<<b)|(1<<c)]++;
		}

		memset(dp,-1,sizeof(dp));

		int ans = 0;

		for(int i=0;i<(1<<24);i++)
			ans ^= ((n-get(i))*(n-get(i)));

		printf("%d\n",ans);

}