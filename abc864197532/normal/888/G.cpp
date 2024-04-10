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

lli min_xor (const vector <int> &a, int l1, int r1, int l2, int r2, int bit) {
	if (l1 >= r1 || l2 >= r2) return 1 << 30;
	if (bit < 0) return 0;
	int m1, m2;
	for (m1 = l1; m1 < r1 && !(a[m1] & (1 << bit)); ++m1);
	for (m2 = l2; m2 < r2 && !(a[m2] & (1 << bit)); ++m2);
	if ((m1 == l1 && m2 == r2) || (m1 == r1 && m2 == l2)) return min_xor(a, l1, r1, l2, r2, bit - 1) ^ (1 << bit);
	return min(min_xor(a, l1, m1, l2, m2, bit - 1), min_xor(a, m1, r1, m2, r2, bit - 1));
}


lli get_ans(const vector <int> &a, int l, int r, int bit) {
	if (l == r || bit < 0) return 0;
	int m;
	for (m = l; m < r && !(a[m] & (1 << bit)); ++m);
	lli ans = get_ans(a, l, m, bit - 1) + get_ans(a, m, r, bit - 1);
	if (m != l && m != r) {
		ans += min_xor(a, l, m, m, r, bit);
	}
	return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i];
    sort(all(a));
    cout << get_ans(a, 0, n, 29) << endl;
}