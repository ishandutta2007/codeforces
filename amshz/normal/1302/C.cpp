# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 1e2+10;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n, m, k, q, B[xn];
ll dp[xn][2];
pii A[xn], Nearest[xn];
vector <pii> adj[xn];

void Build(){
	for (int i = 0; i < k; i++){
		int x = A[i].S;
		int l = -1, r = q, mid;
		while (r - l > 1){
			mid = (l + r) / 2;
			if (B[mid] <= x) l = mid;
			else r = mid;
		}
		if (l == -1) Nearest[i].F = -1;
		else Nearest[i].F = B[l];
		l = -1, r = q, mid;
		while (r - l > 1){
			mid = (l + r) / 2;
			if (B[mid] < x) l = mid;
			else r = mid;
		}
		if (r == q) Nearest[i].S = -1;
		else Nearest[i].S = B[r];
	}
}

ll dist(int ii, int jj){
	pii i = A[ii], j = A[jj];
	swap(i.F, i.S);
	swap(j.F, j.S);
	ll x = Nearest[ii].F, ans = inf;
	if (x != -1) ans = min(ans, abs(i.F - x) + abs(j.F - x));
	x = Nearest[ii].S;
	if (x != -1) ans = min(ans, abs(i.F - x) + abs(j.F - x));
	x = Nearest[jj].F;
	if (x != -1) ans = min(ans, abs(i.F - x) + abs(j.F - x));
	x = Nearest[jj].S;
	if (x != -1) ans = min(ans, abs(i.F - x) + abs(j.F - x));
	return ans + abs(i.S - j.S);
}



int main(){
	fast_io;
	
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++) cin >> A[i].F >> A[i].S;
	for (int i = 0; i < q; i++) cin >> B[i];
	
	bool fl1 = false;
	for (int i = 0; i < k; i++) if (A[i].F == 1 && A[i].S == 1) fl1 = true;
	
	if (!fl1) A[k] = {1, 1}, k++;
	
	
	sort(B, B + q);
	sort(A, A + k);
	
	Build();
	
	for (int i = 0; i < k; i++){
		if (i > 0 && i < k - 1 && A[i - 1].F == A[i].F && A[i + 1].F == A[i].F) continue;
		adj[A[i].F].pb({A[i].S, i});
	}
	int last = -1;
	for (int i = 1; i <= n; i++){
		if (!adj[i].size()) continue;
		if (last == -1){
			ll d = 0;
			if (adj[i].size() == 2) d = abs(adj[i][0].F - adj[i][1].F);
			for (int j = 0; j < adj[i].size(); j++){
				int ind = adj[i][j].S, x = adj[i][j].F, dx = j;
				dp[ind][0] = x - 1;
				if (adj[i].size() == 2) dx = 1 - j;
				dp[ind][1] = d + adj[i][dx].F - 1;
			}
			last = i;
			continue;
		}
		for (int j = 0; j < adj[i].size(); j++){
			ll mn = inf;
			for (int p = 0; p < adj[last].size(); p++){
				int ind1 = adj[i][j].S, ind2 = adj[last][p].S;
				mn = min(mn, dist(ind1, ind2) + dp[ind2][1]);
			}
			dp[adj[i][j].S][0] = mn;
		}
		ll d = 0;
		if (adj[i].size() == 2) d = abs(adj[i][0].F - adj[i][1].F);
		for (int j = 0; j < adj[i].size(); j++){
			int ind = adj[i][j].S, dx = adj[i][1-j].S;
			if (adj[i].size() == 1) dx = adj[i][j].S;
			dp[ind][1] = dp[dx][0] + d;
		}
		last = i;
	}
	int up = 0;
	for (int i = 0; i < k; i++) up = A[i].F;
	ll ans = inf;
	for (int i = 0; i < adj[up].size(); i++){
		int ind = adj[up][i].S;
		ans = min(ans, dp[ind][1]);
	}
	
	cout << ans << endl;
	
	
	return 0;
}