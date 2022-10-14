#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printa(a) {\
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
const int x = 864197532, N = 100087, logN = 18;

vector <int> adj[N];

int main () {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int a[6] = {4, 8, 15, 16, 23, 42}, b[4];
	fop (i,1,5) {
		cout << "? " << i << ' ' << i + 1 << endl;
		cin >> b[i - 1];
	}
	do {
		int c = 0;
		fop (i,0,4) {
			if (a[i] * a[i + 1] == b[i]) c++;
		}
		if (c < 4) continue;
		cout << "! ";
		fop (i,0,6) cout << a[i] << " \n"[i == 5];
		break;
	} while (next_permutation(a, a + 6));
}