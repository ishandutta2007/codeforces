# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> ld;
typedef pair <ld, ld> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e4+10;
const int xm = 5e1+10;
const int SQ = 200;
const int sq = 1e3+10;
const ll inf = 1e18+10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll lcm(ll a, ll b){
	return a * b / __gcd(a, b);
}

int n, m, sz[xm];
bool flag[xn];
vector <int> adj[xm];
 
 
 
int main(){
	fast_io;
	
	cin >> m >> n;
	int x;
	for (int i = 0; i < m; i++){
		cin >> sz[i];
		for (int j = 0; j < sz[i]; j++) cin >> x, adj[i].pb(x);
	}
	for (int i = 0; i < m; i++){
		for (int j = i + 1; j < m; j++){
			for (int k = 1; k <= n; k++) flag[k] = false;
			for (int k = 0; k < sz[i]; k++) flag[adj[i][k]] = true;
			bool fl1 = true;
			for (int k = 0; k < sz[j]; k++) if (flag[adj[j][k]]) fl1 = false;
			if (fl1){
				cout << "impossible" << endl;
				return 0;
			}
		}
	}
	
	cout << "possible" << endl;
	
	
	return 0;
}