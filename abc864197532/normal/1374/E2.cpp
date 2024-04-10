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
const int mod = 1e9 + 7, x = 864197532, N = 2000001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, tmp, a, b;
    cin >> n >> m >> k;
    vector <pii> both, A, B, em;
    fop (i,0,n) {
    	cin >> tmp >> a >> b;
    	if (a && b) both.eb(tmp, i);
    	else if (a) A.eb(tmp, i);
    	else if (b) B.eb(tmp, i);
    	else em.eb(tmp, i);
	}
	sort(all(both));
	sort(all(A));
	sort(all(B));
	sort(all(em));
	multiset <int> s1;
	multiset <int, greater<int>> s2;
	int ans1 = -1, ans2 = 0, ans3 = 0, ans_a = -1, ans_b = -1;
	lli ans = 1ll << 60;
	for (int i = 0; i <= min(k, int(both.size())); ++i) {
		int j = k - i, need = m - i - 2 * j;
		if (j > A.size() || j > B.size() || need < 0) continue;
		if (ans1 == -1) {
			ans1 = 0;
			fop (_,0,both.size()) {
				if (_ < i) ans1 += both[_].X;
				else s1.insert(both[_].X);
			} 
			fop (_,0,A.size()) {
				if (_ < j) ans2 += A[_].X;
				else s1.insert(A[_].X);
			}
			fop (_,0,B.size()) {
				if (_ < j) ans2 += B[_].X;
				else s1.insert(B[_].X);
			}
			fop (_,0,em.size()) s1.insert(em[_].X);
		} else {
			ans1 += both[i - 1].X;
			if (s1.count(both[i - 1].X)) s1.erase(s1.lower_bound(both[i - 1].X));
			else ans3 -= both[i - 1].X, s2.erase(s2.lower_bound(both[i - 1].X));
			ans2 -= A[j].X;
			ans2 -= B[j].X;
			s1.insert(A[j].X);
			s1.insert(B[j].X);
		}
		while (s2.size() < need) {
			int a = *s1.begin();
			ans3 += a;
			s2.insert(a);
			s1.erase(s1.begin());
		}
		while (s1.size() && *s1.begin() < *s2.begin()) {
			int a = *s1.begin(), b = *s2.begin();
			s1.erase(s1.begin());
			s2.erase(s2.begin());
			s1.insert(b);
			s2.insert(a);
			ans3 += a - b;
		}
		if (ans > ans1 + ans2 + ans3) {
			ans = ans1 + ans2 + ans3;
			ans_a = i;
			ans_b = j;
		}
	}
	if (ans == 1ll << 60) {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	vector <pii> ttmp;
	fop (i,0,both.size()) {
		if (i < ans_a) cout << both[i].Y + 1 << ' ';
		else ttmp.pb(both[i]);
	}
	fop (i,0,A.size()) {
		if (i < ans_b) cout << A[i].Y + 1 << ' ';
		else ttmp.pb(A[i]);
	}
	fop (i,0,B.size()) {
		if (i < ans_b) cout << B[i].Y + 1 << ' ';
		else ttmp.pb(B[i]);
	}
	for (pii A : em) ttmp.pb(A);
	sort(all(ttmp));
	fop (i,0,m - ans_a - ans_b * 2) cout << ttmp[i].Y + 1 << ' ';
	cout << endl; 
}