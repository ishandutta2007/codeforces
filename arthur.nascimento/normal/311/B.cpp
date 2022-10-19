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
#define mod 95542721
#define maxn 100100
using namespace std;
typedef long long ll;

long long dp[101][maxn];

int pos[maxn];

int t[maxn];

ll ps[maxn];

inline ll get(int a,int b){
	ll ret = ps[b];
	if(a) ret -= ps[a-1];
	return ret;
}

inline void eval(int init,int fim,int l,int r,int p){
	if(init > fim)
		return;
	int mid = (init+fim)/2;
	int opt;
	ll ans = 99999999999999LL;
	for(int i=max(mid,l);i<=r;i++){

		ll u = (ll) (i-mid+1) * t[i] - get(mid,i) + dp[p-1][i+1];

		if(u < ans){
			ans = u;
			opt = i;
		}
	}
	dp[p][mid] = ans;
	eval(init,mid-1,l,opt,p);
	eval(mid+1,fim,opt,r,p);
}

char ch;
int rt;
inline int read(){
	rt = 0;
	while((ch=getchar()) >= '0')
		rt = 10*rt+ch-'0';
	return rt;
}

main(){

	int n,m,p;
	n = read();
	m = read();
	p = read();

	pos[0] = 0;
	for(int i=1;i<n;i++){
		int u = read();
		pos[i] = pos[i-1] + u;
	}

	for(int i=0;i<m;i++){
		int h = read();
		t[i] = read() - pos[h-1];
	}

	sort(t,t+m);

	ps[0] = t[0];
	for(int i=1;i<m;i++)
		ps[i] = ps[i-1] + t[i];

	for(int i=0;i<m;i++)
		dp[0][i] = 99999999999999LL;

	for(int i=1;i<=p;i++)
		eval(0,m-1,0,m-1,i);

	cout << dp[p][0] << endl;

}