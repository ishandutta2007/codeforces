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

ll a[5], b[5];

ll Get(){
	ll res;
	cin >> res;
	assert(res != -1);
	if(res == 0) exit(0);
	return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a[1] >> a[2] >> a[3];
	cout << "First" << endl;
	ll d = *max_element(a + 1, a + 4);
	cout << d << endl;

	ll r = Get();
	a[r] += d;
	b[1] = a[1];
	b[2] = a[2];
	b[3] = a[3];
	sort(a + 1, a + 4);

	d = (a[2] - a[1]) + 2 * (a[3] - a[2]);
	cout << d << endl;

	r = Get();
	b[r] += d;
	sort(b + 1, b + 4);
	cout << b[2] - b[1] << endl;
	r = Get();
	assert(false);
	return 0;
}