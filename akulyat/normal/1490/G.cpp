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

ll n, q;
vector<ll> v;
vector<pll> qr;
bool viv = false;


void solve() {
	cin >> n >> q;
	v.resize(n);
	for (auto &i : v)
		cin >> i;
	qr.resize(q);
	for (auto &i : qr)
		cin >> i.F;
	for (int i = 0; i < q; i++)
		qr[i].S = i;
	sort(qr.begin(), qr.end());

	vector<ll> ans(q, -1);
	ll mx = 0;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		mx = max(sum, mx);
	}
	if (sum > 0) {
		for (int i = 0; i < q; i++) {
			ans[qr[i].S] = 0;
			if (qr[i].F > mx) {
				ans[qr[i].S] += ((qr[i].F - mx + sum - 1) / sum) * n;
				qr[i].F -= ((qr[i].F - mx + sum - 1) / sum) * sum;
			}
		}
	}
	if (viv) {
		cout << "\t";
		for (auto i : ans)
			cout << i << ' ';
		cout << endl;
	}
	sort(qr.begin(), qr.end());

	sum = 0;
	int nxt = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
		while (nxt < q && qr[nxt].F <= sum) {
			if (viv)
				cout << "\teat " << qr[nxt].F << " by " << sum << endl;
			if (ans[qr[nxt].S] == -1)
				ans[qr[nxt].S] = i;
			else
				ans[qr[nxt].S] += i;
			nxt++;
		}
	}

	for (auto i : ans)
		cout << i << ' ';
	cout << '\n';


}

int main() {
	// viv = true;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t = 1; 
	cin >> t;
	while (t--)
		solve();

	return 0;
}