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
#define maxn 10100

typedef long long ll;
using namespace std;

int dp[4][maxn];

char str[maxn];
int n;

set<string> S;

int get(int bad,int pos){
	if(pos == n) return 1;
	if(pos > n) return 0;
	if(dp[bad][pos]+1)
		return dp[bad][pos];
	int r = 0;
	if(bad != 2){
		int u = 1;
		if(str[pos] != str[pos+2] || str[pos+1] != str[pos+3]) u = 0;
		if(get(u*2,pos+2)){
			string p;
			p.pb(str[pos]);
			p.pb(str[pos+1]);
			S.insert(p);
			debug("%d %d + ",bad,pos);
			//cerr << p << endl;
			r = 1;
		}
	}
	if(bad != 3){
		int u = 1;
		if(str[pos] != str[pos+3] || str[pos+1] != str[pos+4] || str[pos+2] != str[pos+5]) u = 0;
		if(get(u*3,pos+3)){
			string p;
			p.pb(str[pos]);
			p.pb(str[pos+1]);
			p.pb(str[pos+2]);
			debug("%d %d + ",bad,pos);
			//cerr << p << endl;
			S.insert(p);
			r = 1;
		}
	}
	
	debug("dp %d %d = %d\n",bad,pos,r);	
	return dp[bad][pos] = r;
}

main(){
	
	scanf(" %s",str);
	n = strlen(str);
	
	memset(dp,-1,sizeof(dp));
	
	for(int i=5;i<n;i++)
		get(0,i);
		
	printf("%d\n",(int)S.size());
	for(set<string> :: iterator it = S.begin(); it != S.end(); it++)
		cout << *it << endl;
		
}