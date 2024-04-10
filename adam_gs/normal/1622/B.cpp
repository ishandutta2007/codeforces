#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	string x;
	cin >> x;
	vector<pair<int,int>>A, B;
	rep(i, n) {
		if(x[i]=='1') {
			A.pb({T[i], i});
		} else {
			B.pb({T[i], i});
		}
	}
	sort(all(A));
	sort(all(B));
	int ans[n];
	rep(i, B.size()) ans[B[i].nd]=i+1;
	rep(i, A.size()) ans[A[i].nd]=B.size()+i+1;
	rep(i, n) cout << ans[i] << " ";
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}