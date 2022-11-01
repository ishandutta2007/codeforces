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
const int xn = 5e5 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
ll zarb(ll a, ll b){
	return (a * b + 10 * md) % md;
}
ll jaam(ll a, ll b){
	return (a + b + 10 * md) % md;
}


int n, m, ans;
string a;
bool f[xn], c[xn];
 
int main(){
	fast_io;
	
	cin >> n;
	m = n;
	while (m){
		if (m % 2) a += '1';
		else a += '0';
		m /= 2;
	}
	while (a.size() < 6) a += '0';
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); i ++) if (a[i] == '1') f[i + 1] = 1;
	c[1] = f[1];
	c[6] = f[2];
	c[4] = f[3];
	c[3] = f[4];
	c[5] = f[5];
	c[2] = f[6];
	for (int i = 1; i <= 6; i ++) if (c[i]) ans += pow(2, 6 - i);
	cout << ans << endl;
	
	return 0;
}