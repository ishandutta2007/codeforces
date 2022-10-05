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
 
 
ll n, t, a, b;
vector<ll> m;
bool viv = false;

void solve() {
	cin >> n >> t;
	ll sum = 0;
	m.clear();
	m.resize(n);
	for (auto &i : m)
		cin >> i, sum += i;
	if (sum <= t) {
		cout << "0\n";
		return;
	}
	ll now = 0;
	ll who = 0;
	while (now <= t)
		now += m[who], who++;
//	who--;
	if (who == 0) {
		cout << "1\n";
		return;
	}
	ll z = max_element(m.begin(), m.begin() + who) - m.begin();
	z++;
	cout << z << '\n';
}


int main() {
//	viv = true;
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    	solve();


    return 0;
}