#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17, K = 350;

int ans = 0, n;

void solveBit(vector <int> a, int bit) {
	fop (i,0,n) a[i] %= (1 << bit + 1);
	sort(all(a));
	/*
	2^k <= a < 2^(k + 1)
	2^(k + 1) + 2^k <= a < 2^(k + 2) - 1 
	0 1 3 5 7 9
	4 5
	*/
	int cnt = 0;
	fop (i,0,n) {
		cnt += lower_bound(a.begin() + i + 1, a.end(), (1 << bit + 1) - a[i]) - lower_bound(a.begin() + i + 1, a.end(), (1 << bit) - a[i]);
		cnt += a.end() - lower_bound(a.begin() + i + 1, a.end(), (1 << bit) + (1 << bit + 1) - a[i]);
	}
	if (cnt & 1) ans |= (1 << bit);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    fop (i,0,30) {
    	solveBit(a, i);
	}
	cout << ans << endl;
}