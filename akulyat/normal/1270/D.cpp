#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
ifstream in;
ofstream out;
 
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;;
const long long inf = ml * ml * ml + 7;
 
 
ll n, k;
vector<ll> m;
bool viv = false;

pll ask(set<ll> a) {
	cout << "? ";
	for (auto i : a)
		cout << i + 1 << ' ';
	cout << endl;
	ll v1, v2;
	cin >> v1 >> v2;
	v1--;
	return {v1, v2};
}

void solve() {
	cin >> n >> k;
	set<ll> a;
	for (ll i = 0; i < k; i++)
		a.insert(i);
	pll a1 = ask(a);
	ll pos = a1.F;
	ll val = a1.S;

	a.erase(pos);
	a.insert(k);
	bool les = true;
	pll a2 = ask(a);
	ll val2 = a2.S;
	if (val2 > val)
		les = false;


	a.insert(pos);
	ll ans = 0;
	for (ll i = 0; i < k; i++)
		if (i != pos) {
			a.erase(i);
			pll ai = ask(a);
			ll vali = ai.S;
			if (!(les ^ vali == val))
				ans++;
			a.insert(i);
		}
	if (les = false)
		ans = k - 1 - ans;
	ans++;
	cout << "! " << ans << endl;
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
//    cin >> t;
    while (t--)
    	solve();


    return 0;
}