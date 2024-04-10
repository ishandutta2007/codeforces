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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[N];
ll b[N], p[N];
int Main(){
	for(int i = 0; i < 6; i++) cin >> a[i];
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + 6);
	sort(b, b + n);
	ll ans = b[n - 1] - b[0];
	vector<pair<int, pair<int, int>>> V;
	ll mn = Inf;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 6; j++){
			V.pb({b[i] - a[j],{i, -j}});
		}
		mn = min(mn, b[i] - a[0]);
	}
	sort(all(V));
	reverse(all(V));
	int nt, id;
	for(auto x : V){
		//cerr << x.F << ' ' << mn << '\n';
		nt = -x.S.S;
		id = x.S.F;
		ans = min(ans, abs(x.F - mn));
		
		if(nt == 5) break;
		mn = min(mn, b[id] - a[nt + 1]);

	}
	cout << ans << '\n';
	return 0;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	//cin >> T;
	T = 1;
	while(T --) Main();
	return 0;
}