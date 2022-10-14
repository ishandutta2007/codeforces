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
const int mod = 1e9 + 7, x = 864197532, N = 500007, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector <int> a(n);
	fop (i,0,n) cin >> a[i];
	/*
	1 2 4 3
	2 1 4 3
	4 2 1 3
	2 4 1 3
	*/
	vector <pii> Q(q);
	fop (i,0,q) cin >> Q[i].X >> Q[i].Y;
	vector <pii> nQ;
	fop (i,0,q) {
		while (nQ.size() && nQ.back().Y <= Q[i].Y) nQ.pop_back();
		nQ.pb(Q[i]);
	}
	deque <int> pq;
	vector <int> tmp;
	fop (i,0,nQ[0].Y) tmp.pb(a[i]);
	sort(all(tmp));
	while (tmp.size()) pq.push_front(tmp.back()), tmp.pop_back();
	fop (i,1,nQ.size()) {
		FOP (j,nQ[i - 1].Y, nQ[i].Y) {
			if (nQ[i - 1].X == 1) {
				a[j] = pq.back();
				pq.pop_back();
			} else {
				a[j] = pq.front();
				pq.pop_front();
			}
		}
	}
	FOP (j,nQ.back().Y, 0) {
		if (nQ.back().X == 1) {
			a[j] = pq.back();
			pq.pop_back();
		} else {
			a[j] = pq.front();
			pq.pop_front();
		}
	}
	for (int i : a) cout << i << ' ';
}