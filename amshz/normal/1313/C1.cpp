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
const int xn = 1e3+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int n;
ll a[xn], ans, b[xn][xn], c[xn];



int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++){
		ll s = a[i], last = s;
		b[i][i] = a[i];
		for (int j = i - 1; j >= 0; j--){
			last = min(last, a[j]);
			s += last;
			b[i][j] = last;
		}
		last = a[i];
		for (int j = i + 1; j < n; j++){
			last = min(last, a[j]);
			s += last;
			b[i][j] = last;
		}
		ans = max(ans, s);
		c[i] = s;
	}
	
	for (int i = 0; i < n; i++){
		if (c[i] < ans) continue;
		for (int j = 0; j < n; j++) cout << b[i][j] << sep;
		cout << endl;
		return 0;
	}
	
	
	return 0;
}