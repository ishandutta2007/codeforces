#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define INF 1000000000
// hello world :)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<vi> a(n, vi(3));
	map<ii, ii> best;
	map<ii, ii> rbest;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++)
			cin >> a[i][j];
		sort(all(a[i]));
		ii rect = ii(a[i][1], a[i][2]);
		ii ans = ii(a[i][0], i);
		if(ans > best[rect]) {
			rbest[rect] = best[rect];
			best[rect] = ans;
		} else if(ans > rbest[rect])
			rbest[rect] = ans;
	}
	int d = 0;
	int o = -1;
	for(int i = 0; i < n; i++)
		if(a[i][0] > d) {
			d = a[i][0];
			o = i;
		}
	int o1 = -1;
	for(int i = 0; i < n; i++) {
		ii rect = ii(a[i][1], a[i][2]);
		if(rbest[rect].X != 0 && best[rect].Y != i) {
			int D = min(a[i][1], a[i][0] + best[rect].X);
			if(D > d) {
				d = D;
				o = i;
				o1 = best[rect].Y;
			}
		}
	}
	if(o1 == -1)
		cout << "1\n" << o+1;
	else
		cout << "2\n" << o+1 << ' ' << o1+1;
}