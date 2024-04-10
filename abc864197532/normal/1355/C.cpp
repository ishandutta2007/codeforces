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
const int mod = 998244353, x = 864197532, N = 800000;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	/*
	1 3 6 10
	3 : 1
	4 : 2
	5 : 3
	6 : 3
	7 : 3
	8 : 2
	9 : 1
	
	x + y > z
	y > z - x
	b ~ c > (c ~ d) - (a ~ b)
	b ~ c > c - b : 1
	        c - b + 1 : 2
	
	1 : 1
	2 : 2
	3 : 1
	*/
	vector <lli> pre(N, 0), pre2(N, 0);
	int s = c - b, t = d - a, A = b - a, B = d - c, C = min(A, B);
	fop (i,s,t + 1) {
	    if (i < s + C) pre[i] = i - s + 1;
	    else if (i > t - C) pre[i] = t - i + 1;
	    else pre[i] = C + 1;
	}
	fop (i,1,N) {
	    pre2[i] = pre2[i - 1] + pre[i - 1];
	}
	lli ans = 0;
	fop (i,b,c+1) {
	    ans += pre2[i];
	}
	cout << ans << endl;
}