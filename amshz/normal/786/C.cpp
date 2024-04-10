# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e5 + 10;
const int xm = 1e3 + 10;
const int SQ = 400;
const int sq = 1e3 + 10;
const ll inf = 1e18+ 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, a[xn], ans[xn], cnt[xn], last;

void check(int k){
	int t = 0, las = 0;
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i ++){
		if (!cnt[a[i]]) t ++;
		cnt[a[i]] ++;
		if (t == k + 1){
			t = 1;
			ans[k] ++;
			for (int j = las; j < i; j ++) cnt[a[j]] --;
			las = i;
		}
	}
	ans[k] ++;
}
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int i = 1; i <= SQ; i ++) check(i);
	last = n + 1;
	for (int i = 1; i < SQ; i ++){
		int L = SQ, R = last, Mid;
		while (R - L > 1){
			Mid = (L + R) / 2;
			if (!ans[Mid]) check(Mid);
			if (ans[Mid] > i) L = Mid;
			else R = Mid;
		}
		for (int j = last - 1; j >= R; j --) ans[j] = ans[R];
		last = R;
	}
	for (int i = 1; i <= n; i ++) cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}