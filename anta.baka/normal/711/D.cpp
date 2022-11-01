#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

ll c[100], p[100][100], dp[101][101][101],
	pmin[101][101][101], smin[101][101][101];

const ll M = (ll)1e9 + 7;

ll ppow(ll n, ll p) {
	if(p == 1) return n;
	if(p % 2 == 0) {
		ll srt = ppow(n, p / 2);
		return (srt * srt) % M;
	}
	return (ppow(n, p-1) * n) % M;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	vector<pii> us(n, mp(-1, 0));
	vector<int> cyc;
	int k = 0;
	for(int i = 0, col = -1; i < n; i++)
		if(us[i].first == -1) {
			col++;
			us[i] = mp(col, 0);
			int cur = i;
			while(true) {
				if(us[a[cur]].first != -1) {
					if(us[cur].first == us[a[cur]].first) {
						cyc.pb(us[cur].second - us[a[cur]].second + 1);
						k += cyc.back();
					}
					break;
				}
				us[a[cur]].first = col;
				us[a[cur]].second = us[cur].second + 1;
				cur = a[cur];
			}
		}
	ll ans = 1;
	k = n - k;
	if(k != 0)
		ans = (ans * ppow(2ll, k)) % M;
	for(int p : cyc)
		ans = (ans * (ppow(2, p) - 2)) % M;
	cout << ans;
}