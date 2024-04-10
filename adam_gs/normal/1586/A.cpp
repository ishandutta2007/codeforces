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
bool pierwsza(int x) {
	for(int i=2; i*i<=x; ++i) if(x%i==0) return false;
	return true;
}
void solve() {
	int n;
	cin >> n;
	int T[n], sum=0;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
	}
	if(!pierwsza(sum)) {
		cout << n << '\n';
		rep(i, n) cout << i+1 << " ";
		cout << '\n';
		return;
	}
	rep(i, n) {
		if(!pierwsza(sum-T[i])) {
			cout << n-1 << '\n';
			rep(j, n) if(j!=i) cout << j+1 << " ";
			cout << '\n';
			return;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}