#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
bool f(vector<vector<int>>&V, int n, int m, int x) {
	rep(i, n) {
		bool ok=false;
		rep(j, m) if(V[j][i]>=x) ok=true;
		if(!ok) return false;
	}
	int ma=0;
	rep(i, m) {
		int ile=0;
		rep(j, n) if(V[i][j]>=x) ++ile;
		ma=max(ma, ile);
	}
	return ma>=2;
}
void solve() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>>V;
	rep(i, m) {
		vector<int>P;
		rep(j, n) {
			int a;
			cin >> a;
			P.pb(a);
		}
		V.pb(P);
	}
	int p=0, k=1000000000;
	while(p<k) {
		int sr=(p+k+1)/2;
		if(f(V, n, m, sr)) p=sr; else k=sr-1;
	}
	cout << p << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}