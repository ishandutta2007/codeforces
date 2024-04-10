// I'll Crush you !
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
const int N = 1e2 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N][N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T --) {
		ll n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];

		ll ans = 0;
		set<pll> st;
		vector<ll> V;
		for(int i = 0; i <= n - 1 - i; i++){
			for(int j = 0; j <= m - 1 - j; j++){
				st.clear();
				st.insert({i, j});
				st.insert({n - 1 - i, j});
				st.insert({i, m - 1 - j});
				st.insert({n - 1 - i, m - 1 - j});
				V.clear();
				for(auto x : st) V.pb(a[x.F][x.S]);
				sort(all(V));
				
				ll med = V[V.size() / 2];
				for(auto x : V) ans += abs(med - x);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}