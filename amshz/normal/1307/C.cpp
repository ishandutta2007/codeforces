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
 
const ll md = 998244353;
const int xn = 2e5+10;
const int xm = 5e1+10;
const int SQ = 200;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll lcm(ll a, ll b){
	return a * b / __gcd(a, b);
}

string a, abc = "abcdefghijklmnopqrstuvwxyz";
ll ans, cnt[xn][30][2];



int main(){
	fast_io;
	
	cin >> a;
	int n = a.size();
	
	for (int i = 0; i < 26; i++){
		int x = 0;
		for (int j = 0; j < a.size(); j++){
			x += (a[j] == (abc[i]));
			cnt[j][i][0] = x;
		}
		x = 0;
		for (int j = n - 1; j >= 0; j--){
			x += (a[j] == abc[i]);
			cnt[j][i][1] = x;
		}
	}
	
	for (int i = 0; i < 26; i++){
		ll t = 0;
		for (int j = 0; j < n; j++) t += (a[j] == abc[i]);
		ans = max(ans, t);
	}
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 26; j++){
			ll t = 0;
			for (int k = 0; k < n; k++){
				if (a[k] == abc[i]) t += cnt[k + 1][j][1];
			}
			ans = max(ans, t);
		}
	}
	cout << ans << endl;
	
	
	return 0;
}