# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 5e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}

ll n, a[xn];
vector <int> adj[xn];
vector <ll> vec;
ll ans, t;
bool Mark[xn];

void DFS(int v){
	Mark[v] = true;
	t ++;
	for (int u : adj[v]){
		if (Mark[u]) continue;
		DFS(u);
	}
}

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		adj[i].push_back(a[i]);
	}
	
	for (int i = 1; i <= n; i ++){
		if (Mark[i]) continue;
		t = 0;
		DFS(i);
		vec.push_back(t);
	}
	sort(vec.begin(), vec.end());
	if (vec.size() > 1){
		for (int i = 0; i < vec.size() - 1; i ++){
			if (i == vec.size() - 2) vec[i] += vec[i + 1];
			ans += ll(vec[i]) * ll(vec[i]);
		}
	}
	else ans = n * n;
	cout << ans << endl;
	
	return 0;
}