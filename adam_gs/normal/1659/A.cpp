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
	int n, a, b;
	cin >> n >> a >> b;
	int x=(a+b)/(b+1)+1, c=a-(a/(b+1))*(b+1);
	rep(i, b+1) {
		rep(j, a/(b+1)) cout << "R";
		if(c) {
			--c;
			cout << "R";
		}
		if(i<b) cout << "B";
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}