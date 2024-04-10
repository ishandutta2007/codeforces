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
const int xn = 3e5+10;
const int xm = 1e2+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int qq, n, a[xn];
bool f[xn][2];



int main(){
	fast_io;
	
	
	cin >> qq;
	while (qq--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		f[0][0] = true;
		for (int i = 1; i <= n; i++){
			if (a[i] >= i-1) f[i][0] = f[i-1][0];
			else f[i][0] = false;
		}
		f[n+1][1] = true;
		for (int i = n; i >= 1; i--){
			if (a[i] >= n - i) f[i][1] = f[i+1][1];
			else f[i][1] = false;
		}
		bool ans = false;
		for (int i = 1; i <= n; i++){
			if (f[i][0] && f[i][1]) ans = true;
		}
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	
	return 0;
}