#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int INF=2e9+7;
void solve() {
	int ans=INF;
	int m;
	cin >> m;
	int T[m][2], sum[m][2];
	rep(i, m) cin >> T[i][0];
	rep(i, m) cin >> T[i][1];
	rep(i, m) {
		sum[i][0]=T[i][0];
		sum[i][1]=T[i][1];
		if(i) {
			sum[i][0]+=sum[i-1][0];
			sum[i][1]+=sum[i-1][1];
		}
	}
	rep(i, m) { // jesli alice poszla w dol w i-tym
		int akt=0;
		if(i) akt+=sum[i-1][1];
		akt=max(akt, sum[m-1][0]-sum[i][0]);
		ans=min(ans, akt);
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}