# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 1e3 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, k, ans;
pii a[xn];
vector <pii> A, B;

int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 0; i < n; i ++) cin >> a[i].A >> a[i].B;
	for (int i = 0; i < n; i ++){
		if (a[i].B >= 0) A.emplace_back(a[i].A, i);
		else{
			a[i].A = max(a[i].A, -a[i].B);
			B.emplace_back(a[i].A + a[i].B, i);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<pii>());
	for (pii x : A){
		if (x.A > k){
			cout << "NO" << endl;
			return 0;
		}
		k += a[x.B].B;
	}
	for (pii x : B){
		if (a[x.B].A > k){
			cout << "NO" << endl;
			return 0;
		}
		k += a[x.B].B;
		if (k < 0){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}