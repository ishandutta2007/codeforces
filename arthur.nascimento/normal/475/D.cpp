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

#define inf (999999999)
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pff pair<long double,long double>
#define eps 1e-6
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...)//fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100

using namespace std;

map<int,long long> ans;

int v[100100];
int dp[20][100100];

int gcd(int a,int b){
	return b ? gcd(b,a%b) : a;}


int lg[100100];
int get(int a,int b){
	int t = b-a+1;
	int l = lg[t];
	int u =  1 << l;
	debug("ab %d %d\n",a,b);
	debug("ret gcd %d %d t = %d\n",dp[l][a],dp[l][b-u+1],l);
	debug("dp %d %d = %d\n",l,b-u+1,dp[l][b-u+1]);
	return gcd(dp[l][a], dp[l][b-u+1]);
}

main(){

		lg[0] = -1;
		for(int i=1;i<100100;i++){
			lg[i] = lg[i-1];
			if(i == (i&-i))lg[i]++;
		}

		int n,q;
		scanf("%d",&n);

		for(int i=0;i<n;i++){
			scanf("%d",v+i);
			dp[0][i] = v[i];
		}

		for(int i=1;i<20;i++)
			for(int j=0;j+(1<<i)-1<n;j++){
				
				dp[i][j] = gcd(dp[i-1][j],dp[i-1][j+(1<<(i-1))]);
				debug("calc %d %d %d\n",i,j,dp[i][j]);
			}

		for(int i=0;i<n;i++){

			int cur = v[i];
			int last = i;
			debug("i=%d\n",i);
			debug("!! %d\n",get(0,2));

			while(last < n){

				int low = last;
				int up = n-1;
				while(low!=up){
					int mid = (low+up+1)/2;
					if(get(i,mid) == cur)
						low = mid;
					else
						up = mid-1;
				}
				debug("cur %d ateh %d\n",cur,low);
				ans[get(i,low)] += low-last+1;
				last = low+1;
				cur = get(i,last);
			}

		}

		scanf("%d",&q);
		while(q--){
			int t;
			scanf("%d",&t);
			printf("%I64d\n",ans[t]);
		}

}