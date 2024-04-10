#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int n,K;
bool dp[55][55];
ll a[55];

bool ok(ll mask, int d) {
	dp[0][n] = 1;
	for (int k = 1; k <= K; k++) for (int p = 0; p < n; p++) {
		dp[k][p] = 0;
		ll sum = 0;
		for (int r = p+1; r <= n; r++) {
			sum += a[r-1];
			if (((sum >> d) & (mask >> d)) == (mask >> d)) dp[k][p] |= dp[k-1][r];
		}
	}
	return dp[K][0];
}

int main() {
	cin >> n >> K;
	FOR(i,n) cin >> a[i];
	ll res = 0;
	for (int d = 58; d >= 0; d--) {
		if (ok(res | (1LL<<d), d)) res |= 1LL << d;
	}
	cout << res << "\n";
	return 0;
}