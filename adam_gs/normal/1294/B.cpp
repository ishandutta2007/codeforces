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
	pair<int,int>T[n];
	rep(i, n) cin >> T[i].st >> T[i].nd;
	sort(T, T+n);
	int r=0, u=0;
	string ans="";
	rep(i, n) {
		while(r<T[i].st) {
			ans+="R";
			++r;
		}
		while(u<T[i].nd) {
			ans+="U";
			++u;
		}
		if(r!=T[i].st || u!=T[i].nd) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n" << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}