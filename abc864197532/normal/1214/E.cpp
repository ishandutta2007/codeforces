#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
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
const int mod = 998244353, x = 864197532, N = 8000, logN = 17;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <pii> a(n);
    fop (i,0,n) cin >> a[i].X, a[i].Y = i + 1;
    sort(all(a));
    reverse(all(a));
    vector <pii> edge;
	vector <int> p(a[0].X + 1);
	p[0] = a[0].Y * 2;
	fop (i,1,a[0].X) {
		p[i] = a[i].Y * 2;
		edge.eb(p[i - 1], p[i]);
	}
	p.back() = a[0].Y * 2 - 1;
	edge.eb(p[p.size() - 2], p.back());
	fop (i,1,a[0].X) {
		if (i + a[i].X - 1 == p.size() - 1) p.pb(a[i].Y * 2 - 1);
		edge.eb(a[i].Y * 2 - 1, p[i + a[i].X - 1]);
	}
	fop (i,a[0].X,n) {
		if (a[i].X == 1) {
			edge.eb(a[0].Y * 2, a[i].Y * 2);
			edge.eb(a[i].Y * 2 - 1, a[i].Y * 2);
		} else {
			edge.eb(a[0].Y * 2, a[i].Y * 2);
			edge.eb(p[a[i].X - 2], a[i].Y * 2 - 1);
		}
	}
	for (auto A : edge) {
		cout << A.X << ' ' << A.Y << endl;
	}
}