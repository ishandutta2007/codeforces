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
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
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

int qq, n, a[xn], cnt[xn], last, ans, ted, k, mx;
bool flag;

int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		for (int i = 1; i <= n; i ++) cnt[i] = 0;
		for (int i = 1; i <= n; i ++) cnt[a[i]] ++;
		last = 0;
		for (int i = 1; i <= n; i ++){
			if (cnt[i] < 2) break;
			last = i;
		}
		if (!last){
			cout << 0 << endl;
			continue;
		}
		flag = false;
		for (int i = 1; i <= n - last; i ++){
			if (i <= last && cnt[i] != 2) flag = true;
			if (i > last && cnt[i] != 1) flag = true;
		}
		if (flag){
			cout << 0 << endl;
			continue;
		}
		ans = 0, ted = 0, k = 0, mx = 0;
		for (int i = 1; i <= n; i ++) cnt[i] = 0;
		for (int i = 1; i <= n; i ++){
			if (cnt[a[i]]) continue;
			ted ++;
			mx = max(mx, a[i]);
			cnt[a[i]] ++;
			if (ted == i && (i == last || i == n - last) && mx == i) ans ++, k = i;
		}
		cout << ans << endl;
		if (ans == 2){
			cout << last << sep << n - last << endl;
			cout << n - last << sep << last << endl;
		}
		else if (ans == 1){
			if (k == last){
				cout << last << sep << n - last << endl;
			}
			else cout << n - last << sep << last << endl;
		}
	}
	
	return 0;
}