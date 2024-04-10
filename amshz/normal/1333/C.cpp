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
const int xn = 2e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, num[xn], part[xn], ptr = 0, ans;
map <ll, bool> Mark;

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> num[i];
	for (int i = 1; i <= n; i ++) part[i] = part[i - 1] + num[i];
	Mark[0] = true;
	for (ll i = 1; i <= n; i ++){
		while (true){
			ptr ++;
			if (ptr > n || Mark[part[ptr]]){
				ptr --;
				break;
			}
			Mark[part[ptr]] = true;
		}
		ans += ptr - i + 1;
		Mark[part[i - 1]] = false;
	}
	cout << ans << endl;
	
	return 0;
}