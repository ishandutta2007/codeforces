#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
string x;
int n, k;
bool mniejszy(int a, int b) {
	rep(i, k) {
		if(x[i%a]<x[i%b]) return true;
		if(x[i%a]>x[i%b]) return false;
	}
	return true;
}
void solve() {
	cin >> n >> k >> x;
	int ans=1;
	for(int i=2; i<=n; ++i) {
		if(!mniejszy(ans, i)) ans=i;
	}
	rep(i, k) cout << x[i%ans];
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}