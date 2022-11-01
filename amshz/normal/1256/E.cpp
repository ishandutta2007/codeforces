# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, ll> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 3e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, dp[xn], ans[xn], c[xn], part[xn], ptr, S = 1;
pii num[xn];

 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> num[i].A, num[i].B = i;
	sort(num + 1, num + n + 1);
	dp[0] = 0;
	c[0] = - num[1].A;
	part[0] = {0};
	for (int i = 1; i <= n; i ++){
		part[i] = part[i - 1];
		if (i < 3) continue;
		dp[i] = num[i].A + c[part[i - 3]];
		c[i] = dp[i] - num[i + 1].A;
		if (c[i] < c[part[i]]) part[i] = i;
	}
	ptr = n;
	while (ptr){
		for (int i = part[ptr - 3] + 1; i <= ptr; i ++) ans[num[i].B] = S;
		S ++;
		ptr = part[ptr - 3];
	}
	cout << dp[n] << sep << S - 1 << endl;
	for (int i = 1; i <= n; i ++) cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}