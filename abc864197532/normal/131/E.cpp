#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 300087, logN = 17;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <pii> input(m);
	vector <int> ans(m, 0), id(m);
	vector <pii> row[N], col[N], a[N], b[N];
	fop (i,0,m) {
		cin >> input[i].X >> input[i].Y;
		input[i].X--, input[i].Y--;
		row[input[i].X].pb({input[i].Y, i});
		col[input[i].Y].pb({input[i].X, i});
		a[input[i].X + input[i].Y].pb({input[i].X, i});
		b[input[i].X - input[i].Y + 100087].pb({input[i].Y, i});
	}
	fop (i,0,N) if (row[i].size() > 1) {
		sort(all(row[i]));
		fop (j,0,row[i].size()) {
			if (j == 0 or j == row[i].size() - 1) ans[row[i][j].Y]++;
			else ans[row[i][j].Y] += 2;
		}
	}
	fop (i,0,N) if (col[i].size() > 1) {
		sort(all(col[i]));
		fop (j,0,col[i].size()) {
			if (j == 0 or j == col[i].size() - 1) ans[col[i][j].Y]++;
			else ans[col[i][j].Y] += 2;
		}
	}
	fop (i,0,N) if (a[i].size() > 1) {
		sort(all(a[i]));
		fop (j,0,a[i].size()) {
			if (j == 0 or j == a[i].size() - 1) ans[a[i][j].Y]++;
			else ans[a[i][j].Y] += 2;
		}
	}
	fop (i,0,N) if (b[i].size() > 1) {
		sort(all(b[i]));
		fop (j,0,b[i].size()) {
			if (j == 0 or j == b[i].size() - 1) ans[b[i][j].Y]++;
			else ans[b[i][j].Y] += 2;
		}
	}
	vector <int> anss(9, 0);
	fop (i,0,m) anss[ans[i]]++;
	for (int i : anss) cout << i << ' ';
}