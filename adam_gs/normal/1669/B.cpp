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
	int ile[n];
	rep(i, n) ile[i]=0;
	rep(i, n) {
		int a;
		cin >> a; --a;
		++ile[a];
	}
	rep(i, n) if(ile[i]>2) {
		cout << i+1 << '\n';
		return;
	}
	cout << -1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}