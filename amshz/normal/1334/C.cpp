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
const int xn = 5e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq, n;
ll ans;
pair <ll, ll> num[xn];


int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> num[i].A >> num[i].B;
		if (n == 1){
			cout << num[0].A << endl;
			continue;
		}
		ll dx = 0, mn = min(num[0].A, num[n - 1].B);
		for (int i = 1; i < n; i ++){
			ll s = min(num[i].A, num[i - 1].B);
			if (s < mn) dx = i, mn = s;
		}
		ans = 0;
		for (int i = 0; i < n; i ++){
			int k = (i + dx) % n;
			ans += num[k].A;
			num[(k + 1) % n].A = max(0LL, num[(k + 1) % n].A - num[k].B);
		}
		cout << ans << endl;
	}
	
	
	return 0;
}