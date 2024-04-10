# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 2e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, m, ans[xn];
pii a[xn];
ll sum, last;

int main(){
	fast_io;

	cin >> n >> m;
	for (int i = 0; i < m; i ++){
		cin >> a[i].A;
		sum += a[i].A;
		a[i].B = i;
	}
	sum -= n;
	if (sum < 0){
		cout << -1 << endl;
		return 0;
	}
	//sort(a, a + m);
	//reverse(a, a + m);
	for (int i = 0; i < m; i ++){
		if (i == 0){
			last = 1;
			ans[a[i].B] = 1;
			continue;
		}
		ll ted = min(sum, a[i - 1].A - 1);
		sum -= ted;
		last = last + a[i - 1].A - ted;
		ans[a[i].B] = last;
		if (ans[a[i].B] + a[i].A - 1 > n){
			cout << -1 << endl;
			return 0;
		}
	}
	if (sum){
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < m; i ++) cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}