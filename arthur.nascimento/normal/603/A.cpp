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
#define mod 1000000007
#define maxn 100100
using namespace std;
typedef long long ll;

int dp[maxn][2][3];
char str[maxn];
int n;

int get(int pos,int last,int flip){
	if(flip == 3)
		return 0;
	if(dp[pos][last][flip]+1)
		return dp[pos][last][flip];
	if(pos == n)
		return 0;
	int ret = get(pos,last,flip+1);
	int cur = str[pos]-'0';
	if(flip == 1)
		cur ^= 1;
	if(cur == last^1)
		ret = max(ret, 1 + get(pos+1,cur,flip));
	else
		ret = max(ret, get(pos+1,last,flip));
	return dp[pos][last][flip] = ret;
}

main(){

	scanf("%d",&n);
	scanf(" %s",str);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",max(get(0,0,0),get(0,1,0)));

}