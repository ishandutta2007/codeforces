#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define INF (int) 1e9 + 7;
#define left left_fenwick
#define right right_fenwick
#define fc first
#define sc second
#define pb push_back
#define endl '\n'

pair <ll, ll> ans;

void rec(ll m, ll cnt, ll cur) {
	if (m == 0) {
		ans = max(ans, mp(cnt, cur));
	} else {
		ll l = 0, r = 100000 + 7, v;
		while (l < r - 1) {
			v = (l + r) >> 1;
			if (v * v * v <= m) {
				l = v;
			} else {
				r = v;
			}
		}
		v = l;
		rec(m - v * v * v, cnt + 1, cur + v * v * v);
		if (v - 1) {
			rec((v * v * v) - 1 - (v - 1) * (v - 1) * (v - 1), cnt + 1, cur + (v - 1) * (v - 1) * (v - 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	//ifstream cin("sum.in");
	//ofstream cout("sum.out");
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ll m;
	cin >> m;	
	rec(m, 0, 0);
	cout << ans.fc << " " << ans.sc << endl;
}