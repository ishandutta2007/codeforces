#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
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
const int mod = 1000007, x = 864197532, N = 200000;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <pll> point(m);
    fop (i,0,m) cin >> point[i].X >> point[i].Y;
    vector <int> count(n + 1, 1);
    fop (i,0,m) fop (j,i + 1, m) if (point[i].Y != point[j].Y) {
		int c = 0;
		fop (k,0,m) {
			if ((point[k].X - point[i].X) * (point[k].Y - point[j].Y) == (point[k].X - point[j].X) * (point[k].Y - point[i].Y)) {
				c++;
			}
		}
		lli yy = point[j].Y - point[i].Y, xx = point[j].X - point[i].X;
		lli g = __gcd(xx, yy);
		xx /= g, yy /= g;
		if (point[j].Y % yy == 0) {
			lli xxx = point[j].X - xx * point[j].Y / yy;
			if (xxx >= 1 and xxx <= n) count[xxx] = max(count[xxx], c);
		}
	}
	lli ans = 0;
	fop (i,1,n + 1) ans += count[i];
	cout << ans << endl;
	
}