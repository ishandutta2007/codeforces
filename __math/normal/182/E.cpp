#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <string.h>
#include <cassert>

#ifdef _DEBUG
#define typeof(X) std::identity<decltype(X)>::type //C++0x (for vs2010)
#else
#define typeof(X) __typeof__(X) // for gcc
#endif

#define sz(a)  int((a).size())
#define FOREACH(it, c) for (typeof((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define FOR(i,count) for (int i = 0; i < (count); i++)
#define V_CIN(v) do{for(int i = 0; i < sz(v); i++) cin >> (v)[i];}while(0)
#define all(c) (c).begin(),(c).end()

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
const int MODULO = 1000000007;
const int INF = 100000000; //1e8

typedef pair<int,int> Pii;

int n,l;
int dp[201][3001];
int a[200],b[200];

int table[200][200];

int main(){
	iostream::sync_with_stdio(false);

	cin>>n>>l;
	FOR(i,n) cin>>a[i]>>b[i];

	FOR(i,n){
		dp[i][a[i]] = 1;
		if(a[i] == b[i]) {a[i+n] = b[i+n] = INF; continue;}
		a[i+n] = b[i];
		b[i+n] = a[i];
		dp[i+n][b[i]] = 1;
	}

	FOR(i,l + 1) FOR(j,n*2){
		if(a[j] > i) continue;
		FOR(k,n*2){
			if( ((k < n) ? k : k - n) == ((j < n) ? j : j - n) ) continue;
			if( a[j] != b[k] ) continue;
			dp[j][i] += dp[k][i - a[j]];
			if(dp[j][i] > MODULO) dp[j][i] -= MODULO;
		}
	}

	ll ans = 0;
	FOR(i,n*2){
		ans += dp[i][l];
	}

	cout << ans % MODULO << endl;

	return 0;
}