#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")

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
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 


ll n;
vector<ll> v;
bool viv = false;


void solve() {
	cin >> n;
	for (int i = 0; i < kk; i++)
		v.push_back(i * (i - 1) / 2);
	string s;
	char b = 'a';
	for (int i = v.size() - 1; i > 1; i--) {
		while (n >= v[i]) {
			n -= v[i];
			assert(b <= 'z');
			for (int j = 0; j < i; j++)
				s += b;
			b++;
		}
	}
	if (s.size() == 0)
		s = "a";
	cout << s << endl;

}


int main() {
//	viv = true;
	srand(time(0));
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while (t--)
		solve();

	return 0;
}