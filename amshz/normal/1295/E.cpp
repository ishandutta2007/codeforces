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

ll n, p[xn], Cost[xn], a[xn], Mn[xn], b[xn], ans = INF, lazy[xn], sum;

void update(int L, int R, ll x){
	for (int i = L; i <= R;){
		if (i % SQ == 0 && i + SQ - 1 <= R) lazy[i / SQ] += x, ans = min(ans, Mn[i / SQ] + lazy[i / SQ]), i += SQ;
		else{
			Mn[i / SQ] = INF;
			for (int j = i - i % SQ; j < i - i % SQ + SQ; j ++){
				if (j >= n) break;
				if (j >= L && j <= R) a[j] += x;
				Mn[i / SQ] = min(Mn[i / SQ], a[j]);
			}
			ans = min(ans, Mn[i / SQ] + lazy[i / SQ]);
			i = i - i % SQ + SQ;
		}
	}
}
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> p[i];
	for (int i = 1; i <= n; i ++) cin >> Cost[i];
	for (int i = 1; i <= n; i ++) b[p[i]] = i;
	for (int i = 0; i < xn; i ++) Mn[i] = a[i] = INF;
	ans = Cost[1];
	sum = Cost[b[1]];
	for (int i = 1; i < n; i ++){
		if (p[i] > 1) sum += Cost[i];
		else sum -= Cost[b[1]];
		a[i] = sum;
		Mn[i / SQ] = min(Mn[i / SQ], a[i]);
		ans = min(ans, a[i]);
	}
	for (int i = 2; i <= n; i ++){
		update(1, b[i] - 1, Cost[b[i]]);
		update(b[i], n - 1, - Cost[b[i]]);
	}
	cout << ans << endl;
	
	return 0;
}