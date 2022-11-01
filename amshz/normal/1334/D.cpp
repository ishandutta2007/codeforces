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
const int xn = -20 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll qq, n, l, r;
vector <int> vec;

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> l >> r;
		vec.clear();
		ll ptr = 2 * n - 2, sum = 0;
		for (ll i = 1; i <= n; i ++){
			if (l <= sum + n + n - i - i){
				ptr = i;
				break;
			}
			sum += n + n - i - i;
		}
		ll gir = 0;
		ll L = l;
		gir = (l - sum + 1) / 2 + ptr;
		ll last = sum;
		//cout << ptr << sep << gir << endl;
		for (ll i = l; i <= r; i ++){
			if (i > n * (n - 1)){
				vec.push_back(1);
				break;
			}
			if ((i - last) % 2 == 1) vec.push_back(ptr);
			if ((i - last) % 2 == 0) vec.push_back(gir ++);
			if (gir > n){
				gir = ptr + 2;
				sum += n + n - ptr - ptr - 2;
				ptr ++;
				last = sum;
			}
		}
		for (int x : vec) cout << x << sep;
		cout << endl;
	}
	
	
	
	return 0;
}