// Amsal Shoma Ro Gaedan Ye Amal Pasandidas !
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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll n, m, k;
ll c[N];
ll idx[N];

ll po[N][4];
ll ps[4][N];
vector<ll> V[4];
vector<pll> Al;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> c[i];
	ll a, b,v;
	cin >> a;
	for(int i = 1; i <= a; i++){
		cin >> v;
		idx[v] ++;
	}
	cin >> b;
	for(int i = 1; i <= b; i++){
		cin >> v;
		idx[v] += 2;
	}
	for(int i = 1; i <= n; i++){
		V[idx[i]].pb(c[i]);
		Al.pb({c[i], i});
	}
	for(int i = 0; i < 4; i++){
		sort(all(V[i]));
		ps[i][0] = 0;
		for(int j = 1; j <= (int) V[i].size(); j++) ps[i][j] = ps[i][j - 1] + V[i][j - 1];
	}
	sort(all(Al));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 4; j++){
			po[i][j] = po[i - 1][j] + (idx[Al[i - 1].S] == j ? 1 : 0);
		}
	}
	ll ans = Inf;
	ll p0, p1, p2, p3;
	for(int i = 0; i <= (int) V[3].size(); i++){
		ll pa = max(0ll, k - i);
		ll pb = max(0ll, k - i);
		if(pa > V[1].size()) continue;
		if(pb > V[2].size()) continue;
		if(i + pa + pb > m) continue;

		int L = -1, R = n + 1;
		int mid;
		while(L + 1 < R){
			mid = (L + R) >> 1;
			p0 = po[mid][0];
			p1 = max(pa, po[mid][1]);
			p2 = max(pb, po[mid][2]);
			p3 = i;
			if(p0+p1+p2+p3 < m) L = mid;
			else R = mid;
		}
		mid = R;
		p0 = po[mid][0];
		p1 = max(pa, po[mid][1]);
		p2 = max(pb, po[mid][2]);
		p3 = i;
		if(p0 + p1 + p2 + p3 != m) continue;
		ans = min(ans, ps[0][p0]+ps[1][p1]+ps[2][p2]+ps[3][p3]);
	}

	cout << (ans == Inf ? -1 : ans) << '\n';
	return 0;
}