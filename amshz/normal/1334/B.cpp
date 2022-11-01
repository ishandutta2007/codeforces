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
const int xn = 1e5 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, num[xn], x, qq;

bool check(int t){
	ll sum = 0;
	for (int i = 1; i <= t; ++ i) sum += num[i];
	if (sum / t >= x) return true;
	return false;
}

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> x;
		for (int i = 1; i <= n; ++ i) cin >> num[i];
		sort(num + 1, num + n + 1);
		reverse(num + 1, num + n + 1);
		int L = 0, R = n + 1;
		while (R - L > 1){
			int Mid = (L + R) / 2;
			if (check(Mid)) L = Mid;
			else R = Mid;
		}
		cout << L << endl;
	}
	
	return 0;
}