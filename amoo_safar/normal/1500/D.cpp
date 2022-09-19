// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll Mod = 1000000007LL;
const int N = 1500 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int a[N][N];

vector<pii> V[2][N];
int dp[2][N];
int ans[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		ans[1] ++;
		dp[0][i] = 1;
		V[0][i].pb({0, a[0][i]});
	}
	for(int i = 1; i < n; i++){
		int ii = i & 1;
		for(int j = 0; j < n; j++){
			V[ii][j].clear();
			V[ii][j].pb({0, a[i][j]});
			for(auto &x : V[ii ^ 1][j])
				V[ii][j].pb({x.F + 1, x.S});
			if(j > 0){
				for(auto &x : V[ii ^ 1][j - 1])
					V[ii][j].pb({x.F + 1, x.S});
				for(auto &x : V[ii][j - 1])
					V[ii][j].pb({x.F + 1, x.S});
			}
			vector<pii> &X = V[ii][j];
			vector<pii> gd;
			sort(all(X));
			int fl;

			// set<int> vis;
			for(auto el : X){
				fl = 0;
				for(auto &u : gd)
					if(u.S == el.S) fl = 1;
				if(fl)
					continue;
				// if(i == 1 && j == 2) cerr << "? " << el.F <<  ' ' << el.S << '\n';
				// if(vis.count(el.S)) continue;
				// vis.insert(el.S);
				gd.pb(el);
				if(gd.size() == q + 1) break;
			}
			X = gd;
			int res = (X.size() == q + 1 ? X[q].F : min(i, j) + 1);
			res = min(res, min(i, j) + 1);
			ans[res] ++;
			// cerr << "!!! "  << i << ' ' << j << ' ' << res << '\n';
		}
	}
	for(int i = n - 1; i >= 1; i--) ans[i] += ans[i + 1];
	for(int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);

	return 0;
}