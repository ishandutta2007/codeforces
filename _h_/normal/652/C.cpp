#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <random>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> int(a);)
#define allof(v) v.begin(),v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<bool> vb;
typedef long double ld;

int main(){
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vi ps(n), sp(n+1);
	rep(i,0,n){
		cin >> ps[i];
		sp[ps[i]] = i;
	}
	vector<vi> dp(22, vi(n,n+1));
	rep(_,0,m){
		int a,b;
		cin >> a >> b;
		a = sp[a], b = sp[b];
		if(a > b) swap(a,b);
		dp[0][a] = min(dp[0][a], b);
	}
	rep(i,1,22) rep(a,0,n){
		int aa = a + (1<<(i-1));
		dp[i][a] = min(dp[i-1][a], aa>n ? n+1 : dp[i-1][aa]);
	}
	auto rmq = [&](int l, int r){
		int i = 31 - __builtin_clz(r-l);
		return min(dp[i][l], dp[i][r-(1<<i)]);
	};
	ll ans = 0;
	rep(i,0,n){
		int lo = i+1, hi = n+1;
		while(lo+1 < hi){
			int mi = (lo+hi)/2;
			int r = rmq(i,mi);
			if(r < mi)
				hi = mi;
			else
				lo = mi;
		}
		ans += lo - i;
	}
	cout << ans << endl;
}