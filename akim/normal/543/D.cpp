#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
#define sqr(a) ((a)*(a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;


const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 200100;

vector<int> rb[maxn];
vector<ll> pref[maxn];
vector<ll> suff[maxn];
ll dp[maxn];
ll ans[maxn];
bool pm[maxn];

ll binpow(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) {
			ret = ret * a % mod;
		}
		a = a * a % mod; b >>= 1ll;
	}
	return(ret);
}

void dfs(int u) {
	pm[u] = 1;
	dp[u] = 1;
	for(int i = 0; i < (int)rb[u].size(); i++) if(!pm[rb[u][i]]) {
		dfs(rb[u][i]);
		dp[u] = dp[u] * (dp[rb[u][i]] + 1ll) % mod;
	}

	pref[u].pb(1);
	for(int i = 0; i < (int)rb[u].size(); i++) if(!pm[rb[u][i]]) {
		pref[u].pb(pref[u].back() * (dp[rb[u][i]] + 1) % mod);
	}
	pref[u].ppb();

	suff[u].pb(1);
	for(int i = (int) rb[u].size() - 1; i >= 0; i--) if(!pm[rb[u][i]]) {
		suff[u].pb(suff[u].back() * (dp[rb[u][i]] + 1) % mod);
	}
	suff[u].ppb();

	reverse(suff[u].begin(), suff[u].end());
	pm[u] = 0;
}

void rec(int u, ll mn = 1) {
	ll val = mn * dp[u] % mod;
	ans[u] = val;
	pm[u] = 1;
	for(int i = 0, cnt = 0; i < (int)rb[u].size(); i++) if(!pm[rb[u][i]]) {
		rec(rb[u][i], (mn * (suff[u][cnt] * pref[u][cnt] % mod) + 1ll) % mod);
		cnt++;
	}
}

int main() {

	#ifdef SOL
	{
//		freopen("input.txt","r",stdin);
//		freopen("output.txt","w",stdout);
	}
	#else
	srand(time(0));
	const string file = "";
	if(!file.empty()) {
		freopen((file + ".in").c_str(),"r",stdin);
		freopen((file + ".out").c_str(),"w",stdout);
	}
	#endif

	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v); v--;
		rb[v].pb(i);
		rb[i].pb(v);
	}

	dfs(0);
	rec(0);

	for(int i = 0; i < n; i++) {
		printf("%I64d ", ans[i]);
	}

	return(0);
}

// by Kim Andrey