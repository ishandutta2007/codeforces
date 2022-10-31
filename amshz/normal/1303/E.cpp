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
const int xn = 4e2 + 10;
const int xm = 3e1 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
 
int qq, lst[xm][xn], n, m, k, dp[xn][xn];
string s, t, a, b, c, abc = "abcdefghijklmnopqrstuvwxyz";
bool flag;

void Check(){
	n = a.size() - 1, m = b.size() - 1, k = c.size() - 1;
	for (int i = 0; i <= m; i ++){
		for (int j = 0; j <= k; j ++){
			if (!i && !j) continue;
			dp[i][j] = inf;
			if (i){
				int last = dp[i - 1][j];
				if (last == inf) continue;
				dp[i][j] = min(dp[i][j], lst[b[i] - 'a'][last]);
			}
			if (j){
				int last = dp[i][j - 1];
				if (last == inf) continue;
				dp[i][j] = min(dp[i][j], lst[c[j] - 'a'][last]);
			}
		}
	}
	flag |= (dp[m][k] < inf);
}

void Solve(){
	cin >> a >> t;
	a = '.' + a;
	for (int i = 0; i < 26; i ++){
		int last = inf;
		for (int j = a.size() - 1; j >= 0; j --){
			lst[i][j] = last;
			if (a[j] == abc[i]) last = j;
		}
	}
	flag = false;
	for (int i = 0; i < t.size(); i ++){
		b = c = ".";
		for (int j = 0; j < i; j ++) b += t[j];
		for (int j = i; j < t.size(); j ++) c += t[j];
		Check();
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}
 
int main(){
	fast_io;
	
	cin >> qq;
	while (qq --) Solve();
	
	return 0;
}