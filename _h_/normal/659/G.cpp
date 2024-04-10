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
#include <functional>
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
const ll md = 1e9+7;
const int inf = 1e9;
ll inv(ll a, ll b){
	return a-1 ? b-b*inv(b%a,a)/a : 1;
}

int main(){
	cin.sync_with_stdio(0);
	int nn;
	cin >> nn;
	vi hhs(nn);
	rep(i,0,nn) cin >> hhs[i];
	vector<vi> ss;
	int p = 0;
	++nn;
	hhs.pb(1);
	rep(i,0,nn){
		if(hhs[i] == 1){
			ss.pb(vi());
			rep(j,p,i) ss.back().pb(hhs[j]);
			p = i+1;
		}
	}

	ll ans = 0;	
	for(vi hs : ss){
		int n = hs.size();
		vl pr(n+1,1);
		rep(i,0,n)
			pr[i+1] = pr[i] * (min(hs[i], min(i==0 ? inf : hs[i-1], i==n ? inf : hs[i+1]))-1) % md;
		vl sum(n+1);
		rrep(i,0,n) sum[i] = (sum[i+1] + pr[i] * (min(hs[i],i==0?inf:hs[i-1]) - 1))%md;
		rep(i,0,n){
			ans += hs[i]-1;
			if(i == n-1){
				continue;
			}
			ans += (min(hs[i],hs[i+1])-1) * sum[i+1] % md * inv(pr[i+1],md) % md;
		}
	}
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}