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
const int xn = 2e5 + 10;
const int xm = 3e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, a[xn];

ll Solve(int L, int R, ll ind){
	if (ind == -1) return 0;
	int last = 0;
	for (int i = L; i <= R; i ++) if ((a[i]&(1LL << ind)) == 0) last = i;
	if (last == 0 || last == R) return Solve(L, R, ind - 1);
	return min(Solve(L, last, ind - 1), Solve(last + 1, R, ind - 1)) + (1LL << ind);
}

int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	cout << Solve(1, n, 30LL) << endl;
	
	return 0;
}