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

int n, part[xn], mx[xn], num[xn], mn = inf;
bool p[xn];

bool cmp(int i, int j){
	return mx[i] < mx[j];
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) for (int j = i + i; j <= n; j += i) mx[j] = max(mx[j], i);
	for (int i = 1; i <= n; i ++) part[i] = inf;
	for (int i = 1; i <= n; i ++) num[i] = i;
	sort(num + 1, num + n + 1, cmp);
	for (int i = 1; i <= n; i ++){
		int L = 0, R = n + 1, Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (mx[num[Mid]] <= i) L = Mid;
			else R = Mid;
		}
		part[L] = min(part[L], i);
	}
	for (int i = n; i >= 1; i --){
		mn = min(mn, part[i]);
		part[i] = mn;
	}
	for (int i = 2; i <= n; i ++) cout << part[i] << sep;
	cout << endl;
	
	return 0;
}