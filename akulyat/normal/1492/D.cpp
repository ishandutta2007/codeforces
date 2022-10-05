#include <bits/stdc++.h>
#pragma GCC optimize ("O3", "unroll-all-loops")
#pragma GCC target ("sse4.2")

using namespace std;

#define F first
#define S second
typedef long long       ll;
typedef long double     ld;
typedef pair<ll, ll>   pll; 
typedef pair<int, int> pii; 

ifstream in;
ofstream out;

const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool viv = false;

void print(vector<ll> a, vector<ll> b) {
	cout << "Yes\n";
	for (auto i : a)
		cout << i;
	cout << endl;
	for (auto i : b)
		cout << i;
	cout << endl;
}

void solve() {
	int a, b, k;	
	cin >> a >> b >> k;
	int sum = a + b;
	vector<ll> va(sum), vb(sum);
	va[0] = vb[0] = 1;	
	b--;
	if (!b && k)
		return void(cout << "No\n");
	if (!a && k)
		return void(cout << "No\n");
	if (k >= sum)
		return void(cout << "No\n");
	if (k == 0) {
		for (int i = 1; i < b + 1; i++)
			va[i] = vb[i] = 1;
		print(va, vb);
		return;
	}
	if (k == sum - 1) 
		return void(cout << "No\n");

	va[1] = 1;
	vb[1 + k] = 1;
	b--;
	for (int i = 0; i < sum; i++) {
		if (b && !va[i] && !vb[i]) {
			va[i] = vb[i] = 1;
			b--;
		}
	}
	assert(!b);
	return void(print(va, vb));
}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
// 	cin >> t;
	while (t--)
		solve();

	return 0;
}