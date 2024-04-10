#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 3e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll t1, t2, t3;

ll Get(ll x, ll y){
	if(x < y) return t2;
	if(x == y) return t1;
	return t3;
}

ll a[N][N];
ll ps1[N][N], ps2[N][N], ps3[N][N], ps4[N][N];

set<pll> st;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, t;
	cin >> n >> m >> t;
	cin >> t1 >> t2 >> t3;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= m; j++)
			ps1[i][j] = ps1[i][j - 1] + Get(a[i][j - 1], a[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = m - 1; j >= 1; j--)
			ps2[i][j] = ps2[i][j + 1] + Get(a[i][j + 1], a[i][j]);
	for(int i = n - 1; i >= 1; i--)
		for(int j = 1; j <= m; j++)
			ps3[i][j] = ps3[i + 1][j] + Get(a[i + 1][j], a[i][j]);
	for(int i = 2; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ps4[i][j] = ps4[i - 1][j] + Get(a[i - 1][j], a[i][j]);

	ll mn = Inf;
	ll x1 = 1, y1 = 1, x2 = 3, y2 = 3;
	for(int i1 = 1; i1 <= n; i1++)
	for(int i2 = i1 + 2; i2 <= n; i2 ++){
		st.clear();
		for(int j = 2; j <= m; j++){
			ll V = ps1[i1][j] - ps4[i1][j] + ps4[i2][j] - ps2[i2][j];
			ll R = t - V;
			auto it = st.lower_bound({R, -1});
			pll Q;
			if(st.size()){
			if(it != st.end()){
				Q = *it;
				if(abs(t - (V + Q.F)) < mn){
					mn = abs(t - (V + Q.F));
					x2 = i2;
					x1 = i1;
					y2 = j;
					y1 = it -> S;
				}
			}
			if(it != st.begin()){
				it --;
				Q = *it;
				if(abs(t - (V + Q.F)) < mn){
					mn = abs(t - (V + Q.F));
					x2 = i2;
					x1 = i1;
					y2 = j;
					y1 = it -> S;
					//cout << V << " : " << (ps1[x1][y2]) + (- ps2[x2][y2]) + (ps4[x2][y2] - ps4[x1][y2])  << '\n';
					//cout << mn << '\n' << '\n';
				}
			}
			}
			st.insert({-ps1[i1][j-1] + ps3[i1][j-1] - ps3[i2][j-1] + ps2[i2][j-1], j -1});
		}
	}
	//cout << (ps1[x1][y2] - ps1[x1][y1]) + (ps2[x2][y1] - ps2[x2][y2]) + (ps3[x1][y1] - ps3[x2][y1]) + (ps4[x2][y2] - ps4[x1][y2]) << '\n';
	cout << x1 << " " << y1 << " " << x2 << " " << y2 << '\n';
	return 0;
}