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
const int mod = 1e9 + 7, X = 864197532, N = 100000, logN = 18, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	/*
	big - small == 0 || big - small == 1
	*/
	int n, m;
	cin >> n >> m;
	vector <int> v(n);
	fop (i,0,n) {
		cin >> v[i];
		if (v[i] > m) v[i] = 1;
		else if (v[i] == m) v[i] = 0;
		else v[i] = -1;
	}
	int pre = 0;
	lli ans = 0;
	map <int, int> m1;
	m1[0]++;
	int p = 0;
	fop (i,0,n) {
		if (!v[i]) {
			p = i;
			break;
		}
		pre += v[i];
		m1[pre]++;
	}
	fop (i,p,n) {
		pre += v[i];
		ans += m1[pre - 1] + m1[pre];
	}
	cout << ans << endl;
}