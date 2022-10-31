# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 2e5+1;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;
 
int n, qq, a[xn], cnt[xn], c[xn], ans;
vector <pii> baze;
pii b[xn];
bool mark[xn];
 
 
int main(){
	fast_io;
	
	cin >> n >> qq;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i <= 2e5; i++) b[i].F = inf, b[i].S = -1;
	
	for (int i = 0; i < n; i++) b[a[i]].F = min(b[a[i]].F, i), b[a[i]].S = max(b[a[i]].S, i);
	for (int i = 1; i <= 2e5; i++){
		if (b[i].S == -1) continue;
		baze.pb(b[i]);
	}
	sort(baze.begin(), baze.end());
	for (int i = 0; i < baze.size(); i++){
		int l = baze[i].F, r = baze[i].S;
		if (i == 0) c[i] = -1;
		else c[i] = c[i - 1];
		c[i] = max(c[i], r);
	}
	
	for (int i = 0; i < n; i++){
		if (i == n-1){
			mark[i] = true;
			continue;
		}
		int l = 0, r = baze.size(), mid;
		while (r - l > 1){
			mid = (l + r) / 2;
			if (baze[mid].F <= i) l = mid;
			else r = mid;
		}
		if (c[l] < i + 1) mark[i] = true;
	}
	int L = 0, mx = 0;
	for (int i = 0; i < n; i++){
		L++;
		cnt[a[i]]++;
		mx = max(mx, cnt[a[i]]);
		if (mark[i]){
			ans += L - mx;
			memset(cnt, 0, xn);
			mx = 0;
			L = 0;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}