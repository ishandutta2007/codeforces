# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 8e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, m, ans = inf, dp[xn][xm], Cost;
pii num[xn];
bool Mark[xn], part[xn];

 
int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> num[i].A >> num[i].B;
	sort(num + 1, num + n + 1);
	for (int i = 1; i <= n; i ++){
		int L = num[i].A - num[i].B;
		int R = num[i].A + num[i].B;
		L = max(1, L);
		R = min(m, R);
		for (int j = L; j <= R; j ++) Mark[j] = true;
	}
	part[0] = true;
	for (int i = 1; i <= m; i ++) if (part[i - 1] || Mark[i]) part[i] = true;
	for (int i = 0; i <= m; i ++){
		for (int j = 0; j <= n; j ++){
			if (i == 0) continue;
			dp[i][j] = inf;
			if (j == 0) continue;
			if (Mark[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			if (num[j].A > i && num[j].A - num[j].B <= i){
				dp[i][j] = min(dp[i][j], dp[max(0, num[j].A - num[j].B - 1)][j]);
				continue;
			}
			if (num[j].A > i){
				dp[i][j] = min(dp[i][j], num[j].A - num[j].B - 1);
				continue;
			}
			Cost = max(0, i - num[j].A - num[j].B);
			int R = i;
			int L = max(1, num[j].A - num[j].B - Cost);
			dp[i][j] = min(dp[i][j], dp[L - 1][j - 1] + Cost);
			dp[i][j] = min(dp[i][j], Cost + L - 1);
		}
	}
	cout << dp[m][n] << endl;
	
	return 0;
}