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
 
const ll md = 1e9 + 7;
const ll delta = 25439;
const int xn = 2e5 + 10;
const int xm = 1e3 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll qq, n, ps[xn][2][2], mx[xn][2][2], mn[xn][2][2], ans;
string a;
 
int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		cin >> a;
		int n = int(a.size());
		a = '.' + a;
		memset(ps, 0, sizeof ps);
		memset(mx, 0, sizeof mx);
		memset(mn, 0, sizeof mn);
		for (int i = 1; i <= n + 1; i ++){
			ps[i][0][0] = ps[i - 1][0][0];
			ps[i][0][1] = ps[i - 1][0][1];
			if (i == n + 1) break;
			if (a[i] == 'D') ps[i][0][0] ++;
			else if (a[i] == 'A') ps[i][0][0] --;
			else if (a[i] == 'S') ps[i][0][1] ++;
			else ps[i][0][1] --;
		}
		ps[n + 1][1][1] = ps[n + 1][1][0] = 0;
		for (int i = n; i >= 0; i --){
			ps[i][1][0] = ps[i + 1][1][0];
			ps[i][1][1] = ps[i + 1][1][1];
			if (i == 0) break;
			if (a[i] == 'D') ps[i][1][0] ++;
			else if (a[i] == 'A') ps[i][1][0] --;
			else if (a[i] == 'S') ps[i][1][1] ++;
			else ps[i][1][1] --;
		}
		for (int i = 1; i <= n; i ++){
			mx[i][0][0] = max(mx[i - 1][0][0], ps[i][0][0]);
			mx[i][0][1] = max(mx[i - 1][0][1], ps[i][0][1]);
			mn[i][0][0] = min(mn[i - 1][0][0], ps[i][0][0]);
			mn[i][0][1] = min(mn[i - 1][0][1], ps[i][0][1]);
		}
		mx[n + 1][1][0] = mx[n + 1][1][1] = -inf;
		mn[n + 1][1][0] = mn[n + 1][1][1] = inf;
		for (int i = n; i >= 1; i --){
			mx[i][1][0] = max(mx[i + 1][1][0], ps[i][0][0]);
			mx[i][1][1] = max(mx[i + 1][1][1], ps[i][0][1]);
			mn[i][1][0] = min(mn[i + 1][1][0], ps[i][0][0]);
			mn[i][1][1] = min(mn[i + 1][1][1], ps[i][0][1]);
		}
		ans = (mx[n][0][0] - mn[n][0][0] + 1) * (mx[n][0][1] - mn[n][0][1] + 1);
		for (int i = 0; i <= n; i ++){
			ll m = inf;
			ll x = max(mx[i][0][0], mx[i + 1][1][0] + 1);
			x = max(x, ps[i][0][0] + 1);
			ll y = min(mn[i][0][0], mn[i + 1][1][0] + 1);
			m = min(m, x - y + 1);
			x = max(mx[i][0][0], mx[i + 1][1][0] - 1);
			y = min(mn[i][0][0], mn[i + 1][1][0] - 1);
			y = min(y, ps[i][0][0] - 1);
			m = min(m, x - y + 1);
			ans = min(ans, m * (mx[n][0][1] - mn[n][0][1] + 1));
			m = inf;
			x = max(mx[i][0][1], mx[i + 1][1][1] - 1);
			y = min(mn[i][0][1], mn[i + 1][1][1] - 1);
			y = min(y, ps[i][0][1] - 1);
			m = min(m, x - y + 1);
			x = max(mx[i][0][1], mx[i + 1][1][1] + 1);
			x = max(x, ps[i][0][1] + 1);
			y = min(mn[i][0][1], mn[i + 1][1][1] + 1);
			m = min(m, x - y + 1);
			ans = min(ans, m * (mx[n][0][0] - mn[n][0][0] + 1));
		}
		cout << ans << endl;
	}
	
	
	return 0;
}