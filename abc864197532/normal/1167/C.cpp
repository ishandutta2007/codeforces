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
const int mod = 1e9 + 7, x = 864197532, N = 500007, logN = 20, K = 350;

int Dsu[N];

void init() {
	fop (i,0,N) Dsu[i] = i;
}

int Find(int x) {
	if (Dsu[x] == x) return x;
	return Dsu[x] = Find(Dsu[x]);
}

void Union(int x, int y) {
	Dsu[Find(x)] = Dsu[Find(y)];
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, tmp, tmp2;
    cin >> n >> m;
    init();
    fop (i,0,m) {
    	cin >> k;
    	if (k) cin >> tmp;
    	fop (i,1,k) {
    		cin >> tmp2;
    		Union(tmp - 1, tmp2 - 1);
		}
	}
	vector <int> cnt(n, 0);
	fop (i,0,n) cnt[Find(i)]++;
	fop (i,0,n) cout << cnt[Find(i)] << " \n"[i == n - 1];
}