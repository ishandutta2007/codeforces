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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 50, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    fop (i,0,n) cin >> a[i];
    vector <int> one, other;
    vector <pii> edge;
    fop (i,0,n) {
    	if (a[i] == 1) one.pb(i);
    	else other.pb(i);
	}
	if (other.empty()) {
		cout << "NO\n";
	} else {
		if (one.size() <= 2) {
			while (one.size() < 2) one.pb(other.back()), other.pop_back();
			cout << "YES " << n - 1 << endl << n - 1 << endl;
			cout << one[0] + 1 << ' ' << other[0] + 1 << endl;
			fop (i,0,other.size() - 1) {
				cout << other[i] + 1 << ' ' << other[i + 1] + 1 << endl; 
			}
			cout << other.back() + 1 << ' ' << one[1] + 1 << endl;
		} else {
			vector <pii> edge;
			edge.eb(one[0] + 1, other[0] + 1);
			fop (i,0,other.size() - 1) {
				edge.eb(other[i] + 1, other[i + 1] + 1);
			}
			edge.eb(other.back() + 1, one[1] + 1);
			for (int i : other) a[i] -= 2;
			int now = 0;
			fop (i,2,one.size()) {
				while (now < other.size() && !a[other[now]]) now++;
				if (now == other.size()) break;
				edge.eb(one[i] + 1, other[now] + 1);
				a[other[now]]--;
			}
			if (now == other.size()) cout << "NO\n";
			else {
				cout << "YES " << other.size() + 1 << endl;
				cout << edge.size() << endl;
				for (pii A : edge) cout << A.X << ' ' << A.Y << endl;
			}
		}
	}
}