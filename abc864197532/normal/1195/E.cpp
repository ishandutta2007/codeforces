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
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 3000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector <vector <lli>> num(N, vector <lli> (N));
	int n, m, a, b, x, y, z;
	cin >> n >> m >> a >> b >> num[0][0] >> x >> y >> z;
	fop (i,1,n * m) num[i / m][i % m] = (num[(i - 1) / m][(i - 1) % m] * x + y) % z;
	vector <vector <lli>> dp(N, vector <lli> (N));
	fop (j,0,m) {
	    deque <int> dq;
	    fop (i,0,n) {
	        if (i >= a and dq.size() and dq.front() == i - a) dq.pop_front();
	        while (dq.size() and num[dq.back()][j] > num[i][j]) dq.pop_back();
	        dq.push_back(i);
	        if (i >= a - 1) dp[i - a + 1][j] = num[dq.front()][j];
	    }
	}
	lli ans = 0;
	fop (i,0,n - a + 1) {
	    deque <int> dq;
	    fop (j,0,m) {
	        if (j >= b and dq.size() and dq.front() == j - b) dq.pop_front();
	        while (dq.size() and dp[i][dq.back()] > dp[i][j]) dq.pop_back();
	        dq.push_back(j);
	        if (j >= b - 1) ans += dp[i][dq.front()];
	    }
	}
	cout << ans << endl;
}