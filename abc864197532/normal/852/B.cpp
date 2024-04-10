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
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500007;

void mul (vector <vector <long long>> &a, vector <vector <long long>> b) {
	int n = a.size();
	vector <vector <long long>> c = a;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j] = 0;
			for (int k = 0; k < n; ++k) {
				a[i][j] += (c[i][k] * b[k][j] % mod);
				if (a[i][j] >= mod) a[i][j] -= mod;
			}
		}
	}
}

vector <vector <long long>> modpow_martix(vector <vector <long long>> a, long long b) {
	int n = a.size();
	vector <vector <long long>> ans(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans[i].push_back(i == j ? 1 : 0);
		}
	}
	for (; b; b >>= 1, mul(a, a)) {
		if (b & 1) mul(ans, a);
	}
	return ans;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	/*
	4 6 3
	2 1 3
	3 4 1
	4 2       5
	6 1       5
	3 3       4
	1 (l - 1)
	dp[i][j] = dp[i - 1][k] * count(k - j);
	dp[i][0]   0 2 1 dp[i - 1][0] 
	dp[i][1] = 1 0 2 dp[i - 1][1] 
	dp[i][2]   2 1 0 dp[i - 1][2] 
	m = 3
	  1 1 1     0     1
	[ 1 1 1 ] [ 1 ] [ 2 ]
	  1 1 1     2     0
	*/
	int n, l, m, tmp;
	cin >> n >> l >> m;
	vector <vector <lli>> ma(m, vector<lli>(m, 0));
	vector <lli> cnt1(m, 0), cnt2(m, 0), cnt3(m, 0), in(n, 0), cnt4(m, 0);
	fop (i,0,n) {
		cin >> tmp;
		cnt1[tmp % m]++;
	}
	fop (i,0,n) {
		cin >> in[i];
		cnt4[in[i] % m]++;
	}
	fop (i,0,m) fop (j,0,m) {
		ma[j][(m - i + j) % m] += cnt4[i];
	}
	fop (i,0,n) {
		cin >> tmp;
		tmp += in[i];
		cnt2[tmp % m]++;
	}
	fop (i,0,m) fop (j,0,m) {
		(cnt3[(i + j) % m] += cnt1[i] * cnt2[j]) %= mod;
	}
	vector <vector <lli>> aa = modpow_martix(ma, l - 2);
	lli ans = 0;
	fop (i,0,m) (ans += cnt3[i] * aa[0][i]) %= mod;
	cout << ans << endl;
}