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
const int mod = 998244353, x = 864197532, N = 100087;

int main () {
    int n, k, tmp;
    cin >> n >> k;
    int input[n], id[n + 1];
    fop (i,0,n+1) id[i] = -1;
    multiset <int> s;
    fop (i,0,n) cin >> input[i], s.insert(input[i]);
    fop (i,0,k) cin >> tmp, id[tmp] = i + 1;
    FOP (i,n+1,2) id[i - 1] = max(id[i - 1], id[i]);
    cout << endl;
    vector <vector <int>> ans;
    while (s.size()) {
        int t = *--s.end(); s.erase(--s.end());
        ans.pb({});
        ans.back().pb(t);
        int now = 2;
        while (true) {
        	auto it = s.upper_bound(id[now]);
        	if (it == s.begin()) break;
			--it; 
        	ans.back().pb(*it);
        	s.erase(it);
        	now++;
		}
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
    	cout << i.size() << ' ';
    	for (int j : i) cout << j << ' ';
    	cout << '\n';
	}
}