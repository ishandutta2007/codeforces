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
const int xn = 2e2 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, a[xn][xn];

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < 4; i ++) for (int j = 0; j < 4; j ++) cin >> a[i][j];
	for (int i = 0; i < 4; i ++){
		if (min(a[i][0], a[i][1]) + min(a[i][2], a[i][3]) <= n){
			n -= min(a[i][0], a[i][1]);
			cout << i + 1 << sep << min(a[i][0], a[i][1]) << sep << n << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}