#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
int licz(vector<vector<int>>V) {
	int pot=1, n=V.size(), ans=0;
	rep(i, n) pot*=4;
	rep(i, pot) {
		vector<vector<int>>T;
		int akt=i;
		rep(j, n) {
			int x=akt%4; akt/=4;
			vector<int>tmp;
			rep(l, V[j].size()) tmp.pb(V[j][(l+x)%V[j].size()]);
			T.pb(tmp);
		}
		int sum=0;
		rep(j, V[0].size()) {
			int ma=0;
			rep(l, n) ma=max(ma, T[l][j]);
			sum+=ma;
		}
		ans=max(ans, sum);
	}
	return ans;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>T, V;
	vector<pair<int,int>>P;
	rep(i, n) {
		vector<int>tmp;
		rep(j, m) {
			int a;
			cin >> a;
			tmp.pb(a);
		}
		T.pb(tmp);
	}
	rep(j, m) {
		int ma=0;
		rep(i, n) ma=max(ma, T[i][j]);
		P.pb({ma, j});
	}
	sort(all(P));
	reverse(all(P));
	rep(i, min(m, 4)) {
		vector<int>tmp;
		rep(j, n) tmp.pb(T[j][P[i].nd]);
		V.pb(tmp);
	}
	cout << licz(V) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}