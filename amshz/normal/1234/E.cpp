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
const int xm = 2e5+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;
 
ll n, a[xn], m, PS[xn], ans[xn];
 
 
int main(){
	fast_io;
	
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i];
	
	for (int i = 1; i < m; i++){
		ll j = a[i], k = a[i + 1];
		if (j > k) swap(j, k);
		if (j == k) continue;
		PS[1] += k - j, PS[j] -= k - j;
		ans[j] += k - 1;
		PS[j + 1] += k - j - 1, PS[k] -= k - j - 1;
		ans[k] += j;
		PS[k + 1] += k - j, PS[n + 1] -= k - j;
	}
	for (int i = 1; i <= n; i++) PS[i] += PS[i - 1], cout << ans[i] + PS[i] << sep;
	cout << endl;
	
	return 0;
}