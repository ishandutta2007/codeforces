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
#define max3(a,b,c) max(max(a,b),c)
#define mod 1000000007

typedef long long ll;
using namespace std;

double dp[52][maxn];
 	
int t[maxn];

double ps[maxn];
double ps1[maxn];

inline double get(int a,int b){
	double r = ps[b];
	if(a) r -= ps[a-1];
	return r;
}

inline double get1(int a,int b){
	double r = ps1[b];
	if(a) r -= ps1[a-1];
	return r;
}

double ans[maxn];
int n;
inline double eval(int a,int b){
	double ret = ans[a];
	if(b != n-1){
		ret -= ans[b+1];
		ret -= get(a,b) * get1(b+1,n-1);
	}
//	debug("eval %d %d = %lf\n",a,b,ret);
	return ret;
}	

void go(int a,int b,int l,int r,int k){
	int mid = (a+b)/2;
	if(a > b) return;
	int opt;
	double best = 1e18;
	for(int i=max(mid,l);i<=r;i++){
		double cur = eval(mid,i);
		if(i != n-1) cur += dp[k-1][i+1];
		if(cur < best){
			best = cur;
			opt = i;
		}
	}
	dp[k][mid] = best;
	go(a,mid-1,l,opt,k);
	go(mid+1,b,opt,r,k);
}

main(){

	int K;
	scanf("%d%d",&n,&K);

	for(int i=0;i<n;i++)
		scanf("%d",t+i);

	ps[0] = t[0];
	ps1[0] = 1.0 / t[0];

	for(int i=1;i<n;i++){
		ps[i] = ps[i-1] + t[i];
		ps1[i] = ps1[i-1] + 1.0 / t[i];
	}

	ans[n-1] = 1;
	for(int i=n-2;i>=0;i--)
		ans[i] = ans[i+1] + 1.0 + (double) t[i] * get1(i+1,n-1);

	for(int i=0;i<n;i++)
		dp[1][i] = eval(i,n-1);
	for(int i=2;i<=K;i++)
		go(0,n-1,0,n-1,i);

	printf("%.10lf\n",dp[K][0]);

}