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
	int n, m;
	cin >> n >> m;
	vector<int>T(n);
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c; --b;
		++T[b];
	}
	rep(i, n) if(!T[i]) {
		rep(j, n) if(i!=j) cout << i+1 << " " << j+1 << '\n';
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}