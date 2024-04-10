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
const int xn = 1e2 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, T, a[xn], b[xn], dp[xn][xn][xn][3], sum, ted[3], ans;
vector <int> vec;

void check(int x){
	vec.clear();
	for (int i = 0; i < n; i ++)
		if (x&(1 << i)) vec.push_back(i);
	sum = 0;
	for (int v : vec) sum += a[v];
	if (sum != T) return;
	memset(ted, 0, sizeof ted);
	for (int v : vec) ted[b[v] - 1] ++;
	ans = jaam(ans, dp[ted[0]][ted[1]][ted[2]][0]);
	ans = jaam(ans, dp[ted[0]][ted[1]][ted[2]][1]);
	ans = jaam(ans, dp[ted[0]][ted[1]][ted[2]][2]);
}

int main(){
	fast_io;
	
	cin >> n >> T;
	for (int i = 0; i < n; i ++) cin >> a[i] >> b[i];
	
	dp[1][0][0][0] = 1;
	dp[0][1][0][1] = 1;
	dp[0][0][1][2] = 1;
	for (ll i = 0; i <= 50; i ++){
		for (ll j = 0; j <= 50; j ++){
			for (ll k = 0; k <= 50; k ++){
				if (i + j + k < 2) continue;
				for (ll p = 0; p < 3; p ++){
					if (p == 0){
						if (!i) continue;
						dp[i][j][k][p] += zarb(i, dp[i - 1][j][k][1]);
						dp[i][j][k][p] += zarb(i, dp[i - 1][j][k][2]);
					}
					else if (p == 1){
						if (!j) continue;
						dp[i][j][k][p] += zarb(j, dp[i][j - 1][k][0]);
						dp[i][j][k][p] += zarb(j, dp[i][j - 1][k][2]);
					}
					else{
						if (!k) continue;
						dp[i][j][k][p] += zarb(k, dp[i][j][k - 1][0]);
						dp[i][j][k][p] += zarb(k, dp[i][j][k - 1][1]);
					}
				}
			}
		}
	}
	for (int i = 0; i < pow(2, n); i ++) check(i);
	cout << ans << endl;
	return 0;
}