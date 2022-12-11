#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int mod = 1000000007;

int main() {
	ll n,m;
	cin >> n >> m;
	ll R = sqrt(n);
	ll res = 1LL * (n%mod) * ((m-R+1)%mod) % mod;
	if (R > m+1) res=0;
	for (ll k = 1; k < R && k <= m; k++) {
		res = (n%k+res)%mod;
	}
	//cout << res << "\n";
	for (ll a=1; a <= n/R; a++) {
		ll mink = n/(a+1)+1, maxk = n/a;
		mink = max(mink, R);
		maxk = min(maxk, m);
		if (mink > maxk) continue;
		//cout << a << " " << mink << " " << maxk << "\n";
		ll X = mink+maxk, Y = maxk-mink+1, Z = a;
		if (X%2) Y/=2;
		else X/=2;
		X %= mod; Y%= mod; Z %= mod;
		res -= X*Y%mod * Z % mod;
		if (res < 0) res += mod;
	}
	//ll r2=0;
	//for (ll k = 1; k <= m; k++) r2 += n%k;
	//r2 %= mod;
	cout << res << "\n";
	return 0;
}