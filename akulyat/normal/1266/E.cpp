#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair<ll, ll> pll;

//ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;


ll n, i, j, q, sum, ans;
vector<ll> m, in;
map<ll, ll> mp;
bool viv = false;

void del(ll ls, ll lt) {
	ll lu = mp[ls * ml + lt];
	in[lu]++;
	if (in[lu] > 0)
		ans++;
	mp[ls * ml + lt] = 0;
}

void add(ll ls, ll lt, ll lu) {
	if (lu == 0)
		return;
	in[lu]--;
	if (in[lu] >= 0)
		ans--;
	mp[ls * ml + lt] = lu;
}

void read() {
    cin >> n;
    in.resize(n + 1, 0);
    for (i = 0; i < n; i++) {
        ll a;
        cin >> a;
        sum += a;
        m.push_back(a);
        in[i + 1] = a;
    }
    ans = sum;
    cin >> q;
    for (ll i = 0; i < q; i++) {
    	ll ls, lt, lu;
    	cin >> ls >> lt >> lu;
    	if (mp[ls * ml + lt] != 0)
    		del(ls, lt);
    	add(ls, lt, lu);
    	cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    read();

    return 0;
}