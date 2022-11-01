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
 
const ll md = 1e9+7;
const int xn = 1e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n, a[xn], cnt[xn], pnt = 1;
ll ans = 1;


bool check(int l, int r){
	memset(cnt, 0, sizeof cnt);
	for (int i = pnt; i < n - pnt; i ++)
		if ((i < l || i > r) && n - i - 1 >= l && n - i - 1 <= r) cnt[a[i]] ++;
		
	for (int i = pnt; i < n - pnt; i ++){
		if (i >= l && i <= r ){
			cnt[a[i]] --;
			continue;
		}
		if ((n - i - 1 < l || n - i - 1 > r) && a[n - i - 1] != a[i]) return false;
	}
	for (int i = 1; i <= n; i ++)
		if (cnt[i] > 0) return false;
	return true;
}



int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i], cnt[a[i]] ++;
	
	int t = 0;
	for (int i = 1; i <= n; i ++) t += (cnt[i] % 2);
	if (t > 1){
		cout << 0 << endl;
		return 0;
	}
	
	for (int i = 0; i < n; i ++){
		if (a[i] != a[n - i - 1]) break;
		pnt ++;
	}
	
	ans *= ll(pnt);
	
	if (pnt == n + 1){
		cout << ll(n) * ll(n + 1) / 2LL << endl;
		return 0;
	}
	ll s = 1;
	
	pnt --;
	int l = pnt - 1, r = n - pnt - 1, mid;
	while (r - l > 1){
		mid = (l + r) / 2;
		if (check(pnt, mid)) r = mid;
		else l = mid;
	}
	s *= n - pnt - r;
	l = pnt, r = n - pnt;
	while (r - l > 1){
		mid = (l + r) / 2;
		if (check(mid, n - pnt - 1)) l = mid;
		else r = mid;
	}
	s += l - pnt + 1;
	//s --;
	ans *= s;
	ans --;
	ans += pnt * pnt;
	
	cout << ans << endl;
	
	
	return 0;
}