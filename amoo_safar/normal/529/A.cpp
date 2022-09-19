#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;
const ll Base = 101;

ll n, ps[Maxn], ph[Maxn << 1], pw[Maxn];
ll pmn[Maxn], smn[Maxn];
vector<ll> gd;
str s;

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

ll get(int l, int r){
	return (ph[r] - mul(ph[l], pw[r - l]) + Mod) % Mod;
}
int les(int i, int j){
	int l = 0, r = n, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(get(i, i + mid) == get(j, j + mid)) l = mid;
		else r = mid;
	}
	if(s[(i + l) % n] == '(') return i;
	return j;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for(int i = 1; i < Maxn; i++) pw[i] = mul(Base, pw[i - 1]);
	
	cin >> s;
	n = s.size();
	
	ll co = 0, cc = 0;
	for(auto x : s) co += (x == '(');
	for(auto x : s) cc += (x == ')');
	
	ll ans = n + n + n;
	
	for(int i = 1; i <= n; i++) ps[i] = ps[i - 1] + (s[i - 1] == '(' ? +1 : -1);
	for(int i = 1; i <= n; i++) pmn[i] = min(pmn[i - 1], ps[i]);
	smn[n] = ps[n];
	for(int i = n - 1; i >= 0; i--) smn[i] = min(smn[i + 1], ps[i]);

	for(int i = 0; i < n; i++) ans = min(ans, n + (co - 2 * min(smn[i] - ps[i], pmn[i] + (ps[n] - ps[i])) - cc) );
	for(int i = 0; i < n; i++) if(ans == n + (co - 2 * min(smn[i] - ps[i], pmn[i] + (ps[n] - ps[i])) - cc)) gd.pb(i);
	
	for(int i = 1; i <= n + n; i++) ph[i] = (ph[i - 1] * Base + s[(i - 1) % n]) % Mod;
	ll st = gd.back();
	
	for(auto x : gd) st = les(st, x);
	
	ll nd = (ans - n - abs(co - cc)) / 2;
	for(int i = 0; i < nd + max(0LL, cc - co); i++) cout << '(';
	for(int i = 0; i < n; i++) cout << s[(i + st) % n];
	for(int i = 0; i < nd + max(0LL, co - cc); i++) cout << ')';
	return 0;
}