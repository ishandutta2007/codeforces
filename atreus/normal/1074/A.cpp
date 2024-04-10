#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 4;
const int inf = (int)1e9;

map <int, int> mp;
int x[maxn];
pair <pii, int> hori[maxn];

int main(){
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	sort (x, x + n);
	for (int i = 0; i < m; i++)
		cin >> hori[i].F.F >> hori[i].F.S >> hori[i].S;
	sort (hori, hori + m);
	for (int i = 0; i < m; i++) {
		int x1 = hori[i].F.F, x2 = hori[i].F.S, y = hori[i].S;
		if (!mp.count (y)) {
			if (x1 != 1)
				break;
			mp[y] = x2;
		}
		else {
			if (x1 > mp[y])
				break;
			mp[y] = max (mp[y], x2);
		}
	}
	vector <int> v;
	for (auto u : mp) {
		v.PB (u.S);
	}
	sort (v.begin(), v.end());
	x[n] = 1000 * 1000 * 1000;
	int ans = inf;
	int ptr = 0, k = v.size();
	for (int i = 0; i <= n; i++) {
		while (ptr < k and v[ptr] < x[i])
			ptr ++;
		ans = min (ans, i + k - ptr);
	}
	cout << ans << endl;
}