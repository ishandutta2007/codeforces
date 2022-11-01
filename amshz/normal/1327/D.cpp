# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
 
int qq, n, a[xn], c[xn], ans, m;
vector <int> Vec, adj[xn];
bool Mark[xn], flag[xn];

void DFS(int v){
	Mark[v] = true;
	Vec.push_back(v);
	if (!Mark[a[v]])	DFS(a[v]);
}
 
int main(){
	fast_io;
	
	for (int i = 1; i <= 2e5; i ++)
		for (int j = i; j <= 2e5; j += i) 
			adj[j].push_back(i);
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= n; i ++) cin >> c[i];
		ans = n;
		for (int i = 0; i <= n; i ++) Mark[i] = false;
		for (int i = 1; i <= n; i ++){
			if (Mark[i]) continue;
			Vec.clear();
			DFS(i);
			m = Vec.size();
			for (int k : adj[m]){
				for (int j = 0; j < k; j ++) flag[j] = true;
				for (int j = k; j < m; j ++) flag[j % k] &= (c[Vec[j]] == c[Vec[j - k]]);
				for (int j = 0; j < k; j ++) if (flag[j]) ans = min(ans, k);
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}