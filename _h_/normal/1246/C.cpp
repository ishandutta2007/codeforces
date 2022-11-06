// written by aitch
// on 2019 10/26 at 17:47:34
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<ll> vl;

const ll md = 1e9+7;

void modadd(ll &x, ll d){
	x = (x + d) % md;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	if(n+m == 2){
		cout << 1 << endl;
		return 0;
	}

	vector<string> lab(n);
	trav(s, lab) cin >> s;

	vector<vi> ri(n, vi(m+1)), dw(n+1, vi(m));
	rrep(i,0,n) rrep(j,0,m){
		int di = lab[i][j] == 'R';
		ri[i][j] = ri[i][j+1] + di;
		dw[i][j] = dw[i+1][j] + di;
	}

	vector<vector<ll>> gor(n+1, vl(m+1)), god(n+1, vl(m+1));
	gor[0][0] = 1;
	god[0][0] = 1;
	gor[1][0] = -1;
	god[0][1] = -1;

	rep(i,0,n) rep(j,0,m){
		modadd(god[i][j+1], god[i][j]);
		modadd(gor[i+1][j], gor[i][j]);

		modadd(god[i][j+1], gor[i][j]);
		modadd(god[i][m-ri[i][j+1]], -gor[i][j]);

		modadd(gor[i+1][j], god[i][j]);
		modadd(gor[n-dw[i+1][j]][j], -god[i][j]);
	}

	ll ans = gor[n-1][m-1] + god[n-1][m-1];
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}