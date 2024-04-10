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
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;
const double eps = 1e-11;

bool same (double a, double b) {
	return abs(a - b) < eps;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int tmp[n];
	int cnt[m + 1], aa[m + 1];
	fop (i,0,m+1) cnt[i] = aa[i] = 0;
	fop (i,0,n) {
		cin >> tmp[i];
		if (tmp[i] <= m) cnt[tmp[i]]++;
	}
	fop (i,1,m+1) {
		for (int j = i; j <= m; j += i) {
			aa[j] += cnt[i];
		}
	}
	int id = 1, now = 0;
	fop (i,1,m+1) {
		if (aa[i] > now) {
			now = aa[i];
			id = i;
		}
	}
	cout << id << ' ' << now << endl;
	fop (i,0,n) {
		if (id % tmp[i] == 0) cout << i + 1 << ' ';
	}
	cout << endl;
}