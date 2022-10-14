#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 998244353, abc = 864197532, N = 300087, K = 111, logN = 18;

vector <int> adj[26];
string ans;

void dfs(int v) {
    while (adj[v].size()) {
        int u = adj[v].back(); adj[v].pop_back();
        dfs(u);
        ans.pb('a' + u);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) for (int j = 0; j < k; ++j) {
        adj[i].pb(j);
    }
    dfs(0);
    string tans;
    while (tans.size() < n) tans += ans;
    while (tans.size() > n) tans.pop_back();
    cout << tans << endl;
}