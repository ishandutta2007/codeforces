#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	string T[8];
	rep(i, 8) cin >> T[i];
	rep(i, 8) {
		bool ok=true;
		rep(j, 8) if(T[i][j]=='B') ok=false;
		if(ok) {
			cout << "R\n";
			return;
		}
	}
	cout << "B\n";
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}