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
	int T[3];
	rep(i, 3) cin >> T[i];
	sort(T, T+3);
	if(T[0]+T[1]==T[2]) {
		cout << "YES\n";
		return;
	}
	if(T[1]==T[0] || T[1]==T[2]) {
		int x=T[0]^T[1]^T[2];
		if(x%2==0) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}