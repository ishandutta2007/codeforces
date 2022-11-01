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
 
const ll md = 1e9+7;
const int xn = 6e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int qq, n, a[xn];



int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		cin >> n;
		int s = 0;
		for (int i = 0; i < n; i ++) cin >> a[i], s += a[i] % 2;
		if (s == 0 || s == n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	return 0;
}