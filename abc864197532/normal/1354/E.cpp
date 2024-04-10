#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
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
const int mod = 1e9 + 7, x = 864197532, N = 5001, logN = 17, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

long long modpow(int a, int b) {
	long long ans = 1;
	for (long long aa = a; b; b >>= 1, aa = aa * aa % mod) {
		if (b & 1) ans = ans * aa % mod;
	}
	return ans;
}

long long modinv (int b) {
	return modpow(b, mod - 2);
}

vector <int> adj[N];
vector <int> vis(N, -1);
bool is = true;
int c0 = 0, c1 = 0, now2 = 0;
vector <int> sss(N, -1);

void dfs(int v, int pa) {
    for (int u : adj[v]) {
        if (vis[u] == -1) vis[u] = 1 - vis[v], dfs(u, v);
        else if (vis[u] != 1 - vis[v]) is = false;
    }
    if (vis[v] == 1) c1++;
    else c0++;
    sss[v] = now2;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, n0, n1, n2, u, v;
	cin >> n >> m >> n0 >> n1 >> n2;
	fop (i,0,m) {
	    cin >> u >> v;
	    u--; v--;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	vector <pii> vv;
	fop (i,0,n) if (vis[i] == -1) {
	    vis[i] = 0;
	    dfs(i, -1);
	    vv.eb(c0, c1);
	    c0 = c1 = 0;
	    now2++;
	}
	if (!is) {
	    cout << "NO\n";
	    return 0;
	}
	vector <bool> ans(N, false);
	vector <vector <int>> tt(N);
	vector <int> now;
	int tmp = 0;
	fop (i,0,vv.size()) {
	    tmp += vv[i].X;
	    now.pb(vv[i].Y - vv[i].X);
	}
	ans[tmp] = true;
	tt[tmp] = vector <int>(vv.size(), 0);
	fop (i,0,now.size()) {
	    if (now[i] > 0) {
    	    FOP (j,N,1) {
    	        if (ans[j] and j + now[i] < N and !ans[j + now[i]]) {
    	            ans[j + now[i]] = true;
    	            tt[j + now[i]] = tt[j];
    	            tt[j + now[i]][i] = 1;
    	        }
    	    }
	    } else {
    	    fop (j,1,N) {
    	        if (ans[j] and j + now[i] > 0 and !ans[j + now[i]]) {
    	            ans[j + now[i]] = true;
    	            tt[j + now[i]] = tt[j];
    	            tt[j + now[i]][i] = 1;
    	        }
    	    }
	    }
	}
	if (ans[n1]) {
	    cout << "YES\n";
	    fop (i,0,n) {
	        if (tt[n1][sss[i]] != vis[i]) {
	            if (n0 > 0) cout << 1, n0--;
	            else cout << 3;
	        } else {
	            cout << 2;
	        }
	    }
	    cout << endl;
	} else if (ans[n - n1]) {
	    cout << "YES\n";
	    fop (i,0,n) {
	        if (tt[n - n1][sss[i]] == vis[i]) {
	            if (n0 > 0) cout << 1, n0--;
	            else cout << 3;
	        } else {
	            cout << 2;
	        }
	    }
	    cout << endl;
	} else {
	    cout << "NO\n";
	}
}