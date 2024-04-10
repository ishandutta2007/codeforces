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
const int LIM=2e5+7;
int sum[LIM][6];
void solve() {
	int n, m;
	string s, w[6];
	w[0]="abc";
	w[1]="acb";
	w[2]="bac";
	w[3]="bca";
	w[4]="cab";
	w[5]="cba";
	cin >> n >> m >> s;
	rep(i, n) {
		rep(j, 6) {
			if(s[i]!=w[j][i%3]) ++sum[i][j];
			if(i) sum[i][j]+=sum[i-1][j];
		}
	}
	while(m--) {
		int l, r;
		cin >> l >> r; --l; --r;
		int ans=LIM;
		rep(i, 6) {
			int akt=sum[r][i];
			if(l) akt-=sum[l-1][i];
			ans=min(ans, akt);
		}
		cout << ans << '\n';
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}