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
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17, K = 350;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, tmp;
	cin >> n;
	vector <int> cnt(N + 1, 0);
	fop (i,0,n) cin >> tmp, cnt[tmp]++;
	int cnt4 = 0, cnt2 = 0;
	fop (i,1,N) {
		if (cnt[i] >= 4) {
			cnt4++;
		}
		cnt2 += cnt[i] / 2;
	}
	int q;
	cin >> q;
	while (q--) {
		char c;
		int i;
		cin >> c >> i;
		if (c == '+') {
			cnt[i]++;
			if (cnt[i] == 4) {
				cnt4++;
				cnt2++;
			} else if (cnt[i] % 2 == 0) {
				cnt2++;
			}
		} else {
			cnt[i]--;
			if (cnt[i] == 3) {
				cnt4--;
				cnt2--;
			} else if (cnt[i] % 2 == 1) {
				cnt2--;
			}
		}
		if (cnt4 >= 1 && cnt2 >= 4) cout << "YES\n";
		else cout << "NO\n";
	}
}