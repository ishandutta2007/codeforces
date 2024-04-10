#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, X = 864197532, N = 100000, logN = 18, K = 1e6 + 87;

struct Pt {
	lli x, y;
	Pt (lli _x = 0, lli _y = 0) : x(_x), y(_y) {}
	Pt operator + (const Pt &other) {
		return Pt(x + other.x, y + other.y);
	}
	Pt operator - (const Pt &other) {
		return Pt(x - other.x, y - other.y);
	}
	Pt operator * (const int &k) {
		return Pt(x * k, y * k);
	}
	Pt operator / (const int &k) {
		return Pt(x / k, y / k);
	}
	lli operator * (const Pt &other) { // dot
		return x * other.x + y * other.y;
	}
	lli operator ^ (const Pt &other) { // cross
		return x * other.y - y * other.x;
	}
	bool operator < (const Pt &other) {
		if (x == other.x) return y < other.y;
                return x < other.x;
	}
	bool operator == (const Pt &other) {
		return x == other.x && y == other.y;
	}
};

int get_direction(lli a) {
	return (a > 0 ? 1 : (a < 0 ? -1 : 0));
}

Pt get_Pt(Pt a, Pt b, lli x, lli y) {
	y += x;
	lli g = __gcd(x, y);
	x /= g, y /= g;
	Pt v = b - a;
	if (v.x % y || v.y % y) return Pt(K, K);
	return a + ((v / y) * x);
}

Pt banana(Pt a, Pt b, Pt c, Pt d) {
    if (((a - b) ^ (a - c)) == 0 && ((c - a) * (c - b)) <= 0) return c;
    if (((a - b) ^ (a - d)) == 0 && ((d - a) * (d - b)) <= 0) return d;
    if (((c - d) ^ (c - a)) == 0 && ((a - c) * (a - d)) <= 0) return a;
    if (((c - d) ^ (c - b)) == 0 && ((b - c) * (b - d)) <= 0) return b;
    lli A = (a - c) ^ (a - d), B = (b - c) ^ (b - d);
    lli C = (c - a) ^ (c - b), D = (d - a) ^ (d - b);
    if (get_direction(A) * get_direction(B) < 0 && get_direction(C) * get_direction(D) < 0) {
    	lli da = (a - c) ^ (a - d), db = (b - c) ^ (b - d);
    	return get_Pt(a, b, abs(da), abs(db));
	}
    return Pt(K, K);
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <pair <Pt, Pt>> v(n);
	lli ans = 0;
	fop (i,0,n) {
		cin >> v[i].X.x >> v[i].X.y >> v[i].Y.x >> v[i].Y.y;
		Pt tmp = v[i].Y - v[i].X;
		tmp.x = abs(tmp.x), tmp.y = abs(tmp.y);
		ans += __gcd(tmp.x, tmp.y) + 1;
	}
	fop (i,0,n) {
		vector <Pt> a;
		fop (j,0,i) {
			Pt inter = banana(v[i].X, v[i].Y, v[j].X, v[j].Y);
			if (inter.x != K) a.pb(inter);
		}
		sort(all(a));
		ans -= unique(all(a)) - a.begin();
	}
	cout << ans << endl;
}