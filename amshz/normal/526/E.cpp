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
const int xn = 1e6+10;
const int xm = 1e6+10;
const int inf = 1e9+10;

ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


ll n, q, a[xn], par[xn], b, c[xn];

 
int main(){
	fast_io;
	
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	while (q--){
		cin >> b;
		ll sm = a[0];
		for (int i = 1; i < n; i++){
			if (sm + a[i] > b) par[0] = i - 1, c[0] = sm;
			sm += a[i];
			if (sm > b) break;
		}
		if (sm <= b){
			cout << 1 << endl;
			continue;
		}
		for (int i = 1; i < n; i++){
			sm = c[i-1] - a[i-1];
			par[i] = par[i-1], c[i] = sm;
			for (int k = par[i-1]+1; k <= n + i; k++){
				int d = k % n;
				sm += a[d];
				if (sm <= b) par[i] = d, c[i] = sm;
				else break;
			}
		}
		int ind = 0, mn = par[0] + 1;
		for (int i = 1; i < n; i++){
			int d = (par[i] - i + 1 + n) % n;
			if (d < mn){
				mn = d;
				ind = i;
			}
		}
		int ans = n;
		for (int i = ind; i <= ind + mn; i++){
			int d = i % n;
			int cnt = 0, t = 0;
			while (t < n){
				int x = (par[d] - d + 1 + n) % n;
				t += x;
				d = (par[d] + 1) % n;
				cnt++;
			}
			ans = min(ans, cnt);
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
/*
6 1
2 4 2 1 3 2
4
*/