# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <ll, ll> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e3 + 10;
const int xm = 1e4 + 10;
const int SQ = 500;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll gcd(ll a, ll b){
	if (b > a) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
 
int n, sz;
ll a[xn], k, g[xn][xm], b[xn];
pii dp[xn][xm];
bool par[xn][xm];
vector <ll> vec;
vector <int> ans;
unordered_map <ll, ll> Mp;
 
int main(){
	fast_io;
	
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) b[i] = a[i], a[i] = gcd(k, a[i]);
	
	if (k == 1){
		cout << 1 << endl;
		int mn = 1;
		for (int i = 1; i <= n; i ++)
			if (b[i] < b[mn]) mn = i;
		cout << mn << endl;
		return 0;
	}
	for (ll i = 1; i <= sqrt(k); i ++){
		if (k % i) continue;
		vec.push_back(i);
		if (k / i != i) vec.push_back(k / i);
	}
	sort(vec.begin(), vec.end());
	sz = vec.size() - 1;
	for (int i = 0; i < vec.size(); i ++) Mp[vec[i]] = i;
	
	for (int i = 0; i <= 1e3; i ++) for (int j = 0; j < vec.size(); j ++) dp[i][j] = {inf, inf};
	dp[0][0] = {0, 0};
	
	for (int i = 1; i <= n; i ++){
		for (int j = 0; j < vec.size(); j ++){
			dp[i][j] = dp[i - 1][j];
			ll g = gcd(a[i], vec[j]);
			pii New = dp[i - 1][Mp[vec[j] / g]];
			New.first ++;
			New.second += b[i];
			if (New < dp[i][j])
				dp[i][j] = New, par[i][j] = true;
		}
	}
	if (dp[n][sz].first == inf){
		cout << -1 << endl;
		return 0;
	}
	int x = n, y = sz;
	while (x){
		if (par[x][y]){
			ans.push_back(x);
			ll Num = vec[y];
			ll g = gcd(a[x], Num);
			y = Mp[Num / g];
		}
		x --;
	}
	cout << ans.size() << endl;
	for (int ind : ans) cout << ind << sep;
	cout << endl;
	
	return 0;
}