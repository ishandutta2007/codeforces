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
const int xn = 1e2 + 10;
const int xm = 2e1 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int qq, ptr, cnt[xn];
ll m, ans, fact[xn], part[xn], ted;

int main(){
	InTheNameOfGod;
	
	fact[0] = 1LL;
	for (ll i = 1; i <= 20; i ++) fact[i] = (fact[i - 1] * i);
	
	cin >> qq;
	while (qq --){
		cin >> m;
		ptr = 2, ans = 0;
		memset(cnt, 0, sizeof cnt);
		memset(part, 0, sizeof part);
		while (m){
			part[m % ptr] ++;
			cnt[m % ptr] ++;
			m /= ptr;
			ptr ++;
		}
		ptr --;
		for (ll i = 1; i < ptr; i ++) part[i] += part[i - 1];
		for (ll i = 1; i < ptr; i ++){
			for (int j = i; j < ptr; j ++) part[j] --;
			ll s = cnt[i];
			for (ll j = 2; j < ptr; j ++) s *= part[j - 1] - (j - 2);
			for (ll j = 0; j < ptr; j ++) s /= fact[cnt[j]];
			ans += s;
			for (int j = i; j < ptr; j ++) part[j] ++;
		}
		cout << ans - 1 << endl;
	}
	
	return 0;
}