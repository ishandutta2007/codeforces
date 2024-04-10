#include <bits/stdc++.h>
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
// head

int main() {
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pii> co(k);
	map<pii, set<int>> pt;
	for(int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		co[i] = mp(x,y);
		pt[mp(1,y-x)].insert(i);
		pt[mp(-1,y+x)].insert(i);
	}
	vector<ll> ans(k, -1);
	int x0 = 0, y0 = 0;
	int a = 1, b = 0;
	ll t = 0;
	while(true) {
		if(pt.count(mp(a,b)) > 0) {
			set<int> o = pt[mp(a,b)];
			for(auto it = o.begin(); it != o.end(); it++) {
				int i = *it;
				int x = co[i].ff;
				int y = co[i].ss;
				ans[i] = t + abs(x0 - x);
				pt[mp(1,y-x)].erase(i);
				pt[mp(-1,y+x)].erase(i);
			}
		}
		int x1 = 0, y1 = b;
		int x2 = (m - b) / a, y2 = m;
		int x3 = n, y3 = a*n + b;
		int x4 = -b / a, y4 = 0;
		if((x1 != x0 || y1 != y0) && y1 >= 0 && y1 <= m) {
			t += abs(x1 - x0);
			x0 = x1;
			y0 = y1;
		} else if((x2 != x0 || y2 != y0) && x2 >= 0 && x2 <= n) {
			t += abs(x2 - x0);
			x0 = x2;
			y0 = y2;
		} else if((x3 != x0 || y3 != y0) && y3 >= 0 && y3 <= m) {
			t += abs(x3 - x0);
			x0 = x3;
			y0 = y3;
		} else {
			t += abs(x4 - x0);
			x0 = x4;
			y0 = y4;
		}
		if(a == 1) {
			a = -1;
			b = y0 + x0;
		} else {
			a = 1;
			b = y0 - x0;
		}
		if(x0 == 0 && (y0 == 0 || y0 == m) || x0 == n && (y0 == 0 || y0 == m))
			break;
	}
	for(int i = 0; i < k; i++)
		cout << ans[i] << '\n';
}