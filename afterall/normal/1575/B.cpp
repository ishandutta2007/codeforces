// vaziat meshki-ghermeze !
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

const ld pi = acos(-1);
const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;


ld th[N];
ld ln[N];

int n, k;
int db;
bool Check(ld r){
	vector<pair<ld, int> > V;
	for(int i = 0; i < n; i++){
		if(ln[i] == 0){
			V.pb({0, 1});
			continue;
		}
		if(ln[i] > r + r) continue;
		ld br = acos(ln[i] / (r + r));
		// if(br < pi) br += pi;

		// if(db) cerr << "? " << th[i] << ' ' << br << '\n';
		ld ls = th[i] - br;

		while(ls < 0) ls += pi + pi;
		ld rs = th[i] + br;
		while(rs >= pi + pi) rs -= pi + pi;
		
		// if(db){
		// 	cerr << "!! " << ls << ' ' << rs << '\n';
		// }
		if(rs > ls){
			V.pb({ls, +1});
			V.pb({rs, -1});
		} else {
			V.pb({ls, +1});
			//
			V.pb({0, +1});
			V.pb({rs, -1});
		}
	}
	sort(all(V));
	int res = 0;
	for(auto x : V){
		res += x.S;
		if(res >= k) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	ld x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		th[i] = atan2(y, x);
		if(th[i] < 0) th[i] += pi + pi;
		ln[i] = sqrt(1ll * x * x + 1ll * y * y);
	}
	ld L = 0;
	ld mid, R = 200000;
	for(int _ = 0; _ < 100; _ ++){
		mid = (L + R) / 2;
		if(Check(mid)) R = mid;
		else L = mid;
	}
	// db = 1;
	// Check(R);
	cout << fixed << setprecision(16) << R << '\n';
	return 0;
}