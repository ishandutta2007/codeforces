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
const int xn = 3e3+10;
const int xm = 1e6+10;
const int inf = 1e9+10;

ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, p, s, dp[xn][xn], dp2[xn][xn];
pair <pii, int> a[xn];
bool par[xn][xn], par2[xn][xn];
vector <int> Ans1, Ans2;


bool cmp(pair <pii, int> i, pair <pii, int> j){
	return i.F.F > j.F.F;
}

 
int main(){
	fast_io;
	
	cin >> n >> p >> s;
	for (int i = 1; i <= n; i++) cin >> a[i].F.F, a[i].S = i;
	for (int i = 1; i <= n; i++) cin >> a[i].F.S;
	sort(a+1, a+n+1, cmp);
	
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0){
				dp[i][j] = dp[i - 1][j] + a[i].F.S;
				continue;
			}
			if (i == j){
				dp[i][j] = dp[i - 1][j - 1] + a[i].F.F;
				par[i][j] = true;
				continue;
			}
			dp[i][j] = max(dp[i - 1][j - 1] + a[i].F.F, dp[i - 1][j] + a[i].F.S);
			if (dp[i][j] == dp[i - 1][j - 1] + a[i].F.F) par[i][j] = true;
		}
	}
	for (int i = n; i >= 1; i--){
		for (int j = 0; j <= n - i + 1; j++){
			if (j == 0){
				dp2[i][j] = dp2[i + 1][j];
				continue;
			}
			if (j == n - i + 1){
				dp2[i][j] = dp2[i + 1][j - 1] + a[i].F.S;
				par2[i][j] = true;
				continue;
			}
			dp2[i][j] = max(dp2[i + 1][j - 1] + a[i].F.S, dp2[i + 1][j]);
			if (dp2[i][j] == dp2[i + 1][j - 1] + a[i].F.S) par2[i][j] = true;
		}
	}
	int mx = 0;
	for (int i = p; i <= p + s; i++) mx = max(mx, dp[i][p] + dp2[i + 1][s - i  +p]);
	for (int i = p; i <= p + s; i++){
		if (mx > dp[i][p] + dp2[i + 1][s - i + p]) continue;
		int x = i, y = p;
		while (x){
			if (par[x][y]) Ans1.pb(a[x].S), y--;
			else Ans2.pb(a[x].S);
			x--;
		}
		x = i+1, y = s - i + p;
		while (x <= n){
			if (par2[x][y]) Ans2.pb(a[x].S), y--;
			x++;
		}
		break;
	}
	sort(Ans1.begin(), Ans1.end());
	sort(Ans2.begin(), Ans2.end());
	
	
	cout << mx << endl;
	for (int i = 0; i < Ans1.size(); i++) cout << Ans1[i] << sep;
	cout << endl;
	for (int i = 0; i < Ans2.size(); i++) cout << Ans2[i] << sep;
	cout << endl;
	
	
	return 0;
}