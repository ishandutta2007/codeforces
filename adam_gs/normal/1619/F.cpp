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
	int n, m, k;
	cin >> n >> m >> k;
	int x=n-(n/m)*m, akt=0;
	rep(i, k) {
		rep(j, x) {
			cout << (n+m-1)/m << " ";
			rep(l, (n+m-1)/m) {
				cout << akt+1 << " ";
				akt=(akt+1)%n;
			}
			cout << '\n';
		}
		int p=akt;
		rep(j, m-x) {
			cout << n/m << " ";
			rep(l, n/m) {
				cout << p+1 << " ";
				p=(p+1)%n;
			}
			cout << '\n';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}