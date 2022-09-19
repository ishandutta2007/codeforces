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

set<pll> st[5];
ll p[N], a[N], b[N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++){
		st[a[i]].insert({p[i], i});
		st[b[i]].insert({p[i], i});	
		
	}
	ll m;
	cin >> m;
	ll c;
	for(int i = 0; i < m; i++){
		cin >> c;
		if(st[c].empty()) cout << "-1 ";
		else {
			int th = st[c].begin() -> S;
			st[a[th]].erase({p[th], th});
			st[b[th]].erase({p[th], th});
			cout << p[th] << ' ';
		}
	}
	return 0;
}