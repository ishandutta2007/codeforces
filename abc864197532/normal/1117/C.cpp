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
const int mod = 1e9 + 7, x = 864197532, N = 500001, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x1, y1, x2, y2, n;
	lli x, y;
    string s;
    cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
    x = x2 - x1;
    y = y2 - y1;
    lli dx[n + 1], dy[n + 1];
    dx[0] = dy[0] = 0;
    fop (i,0,n) {
    	dx[i + 1] = dx[i];
    	dy[i + 1] = dy[i];
    	if (s[i] == 'U') dy[i + 1]++;
    	if (s[i] == 'D') dy[i + 1]--;
    	if (s[i] == 'L') dx[i + 1]--;
    	if (s[i] == 'R') dx[i + 1]++;
	}
    auto ask = [&](lli t) {
    	lli xx = dx[n] * (t / n) + dx[t % n], yy = dy[n] * (t / n) + dy[t % n];
    	lli aa = abs(x - xx) + abs(y - yy); 
     	return aa <= t;
	}; 
    lli l = 0, r = 1ll << 60;
    while (r - l > 1) {
    	lli mid = l + r >> 1;
    	if (ask(mid)) r = mid;
    	else l = mid;
	}
	if (r == 1ll << 60) r = -1;
	cout << r << endl;
}