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
#define maxn 2020
#define sq(x) ((x)*(x))

using namespace std;

char v[2][maxn];
char str[maxn];

int dp[2][2][maxn][maxn];

int n,m;

int get(int p,int ord,int a,int b){
	if(a < 0 || a == n || b < 0 || b == m)
		return 0;
	if(dp[p][ord][a][b]+1)
		return dp[p][ord][a][b];
	if(v[p][a] != str[b])
		return 0;
	dp[p][ord][a][b] = 1 + get(p,ord,a+(ord?1:-1),b+1);
	//debug("dp[%d][%d][%d][%d] = %d\n",p,ord,a,b,dp[p][ord][a][b]);
	return dp[p][ord][a][b];
}

int dp2[2][2][maxn][maxn];

int get2(int lado,int p,int pos,int match){
	if(match == m)
		return 1;
	if(pos == -1 || pos == n)
		return 0;
	if(dp2[lado][p][pos][match]+1)
		return dp2[lado][p][pos][match];
	if(match == m-1){
		if(v[p][pos] == str[match])
			return 1;
		return 0;
	}
	if(v[p][pos] != str[match])
		return 0;
	int ret = 0;
	if(v[p^1][pos] == str[match+1])
		ret += get2(lado,p^1,pos+(lado?1:-1),match+2);
	ret += get2(lado,p,pos+(lado?1:-1),match+1);
	ret %= mod;
	if(match%2 == m%2){
		int u = (m-match)/2;
		if(u != 1 && get(p,lado,pos,match) >= u && get(p^1,lado^1,pos+(u-1)*(lado?1:-1),match+u) >= u)
			ret++;
		ret %= mod;
	}
	debug("dp2[%d][%d][%d][%d] = %d\n",lado,p,pos,match,ret);
	return dp2[lado][p][pos][match] = ret;
}

main(){
	
	scanf(" %s %s %s",v[0],v[1],str);

	n = strlen(v[0]);
	m = strlen(str);

	memset(dp,-1,sizeof(dp));
	memset(dp2,-1,sizeof(dp2));

	int ans = 0;

	for(int a=0;a<=1;a++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				debug("a %d i %d j %d ans %d\n",a,i,j,ans);
				int sz = max(i,j)-min(i,j)+1;
				if(i <= j){
					if(get(a,1,i,0) < sz)
						continue;
					if(v[a^1][j] != str[sz])
						continue;
					if(sz + 1 == m){
						ans++;
						continue;
					}
					ans += get2(1,a^1,j+1,sz+1);
					ans %= mod;
					int falta = m-sz;
					if(falta <= sz){
						if(get(a^1,0,j,sz) == falta)
							ans++;
						continue;
					}
					if(get(a^1,0,j,sz) >= sz)
						ans += get2(0,a^1,i-1,2*sz);
					ans %= mod;
				}
				else {
					if(get(a,0,i,0) < sz)
						continue;
					if(v[a^1][j] != str[sz])
						continue;
					if(sz + 1 == m){
						ans++;
						continue;
					}
					ans += get2(0,a^1,j-1,sz+1);
					ans %= mod;
					int falta = m-sz;
					if(falta <= sz){
						if(get(a^1,1,j,sz) == falta)
							ans++;
						continue;
					}
					if(get(a^1,1,j,sz) >= sz)
						ans += get2(1,a^1,i+1,2*sz);
					ans %= mod;
				}
			}

	debug("ans %d\n",ans);

	for(int a=0;a<=1;a++)
		for(int d=0;d<=1;d++)
			for(int i=0;i<n;i++){
				if(m == 1 && d == 1)
					continue;
				if(get(a,d,i,0) == m)
					ans++;
			}

	printf("%d\n",ans%mod);

}