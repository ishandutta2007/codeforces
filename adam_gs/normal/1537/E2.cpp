#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
void solve() {
	int n, k;
	string x;
	cin >> n >> k >> x;
	int ans=1;
	rep(i, n) {
		if(x[i]<x[i%ans]) ans=i+1;
		else if(x[i]>x[i%ans]) break;
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