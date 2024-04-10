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
const int mod = 998244353, x = 864197532, N = 100000;

int ask (int a, int b, int c, int d) {
	cout << a << b << c << d << endl;
	cin >> a >> b;
	return a;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <int> v;
	fop (i,0,9) if (ask(i, i, i, i) == 1) {
		v.pb(i);
	}
	if (v.size() < 4) v.pb(9);
	int tmp = ask(v[0], v[0], v[0], v[1]);
	if (tmp == 0) swap(v[0], v[3]);
	else if (tmp == 2) swap(v[1], v[3]);
	else {
		tmp = ask(v[2], v[2], v[2], v[3]);
		if (tmp == 0) swap(v[2], v[3]);
	}
	tmp = ask(v[0], v[0], v[1], v[3]);
	if (tmp == 1) {
		swap(v[0], v[2]);
	} else if (tmp == 3) {
		swap(v[1], v[2]);
	}
	ask(v[0], v[1], v[2], v[3]);
	ask(v[1], v[0], v[2], v[3]);
}