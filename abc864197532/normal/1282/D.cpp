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
const int mod = 998244353, x = 864197532, N = 200087;

int main () {
	int A, B;
	cout << string(300, 'a') << endl;
	cin >> A;
	if (A == 0) exit(0);
	cout << string(300, 'b') << endl;
	cin >> B;
	if (B == 0) exit(0);
	A = 300 - A, B = 300 - B;
	string tmp = string(A + B, 'a');
	int t, tt = B;
	fop (i,0,A+B - 1) {
		tmp[i] = 'b';
		cout << tmp << endl;
		cin >> t;
		if (t - 1 == tt) tmp[i] = 'a';
		tt = min(t, tt);
	}
	if (tt == 1) tmp.back() = 'b';
	cout << tmp << endl;
	cin >> t;
	exit(0);
}