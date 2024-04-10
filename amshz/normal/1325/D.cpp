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
const int xn = -1 + 10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 

ll x, y;


string base(ll a){
	string bin = "";
	while (a){
		if (a % 2) bin += '1';
		else bin += '0';
		a /= 2;
	}
	return bin;
}
 
 
 
int main(){
	fast_io;
	
	cin >> x >> y;
	
	if (x > y){
		cout << -1 << endl;
		return 0;
	}
	
	if (x % 2 != y % 2){
		cout << -1 << endl;
		return 0;
	}
	
	if (x == y){
		if (x == 0){
			cout << 0 << endl;
			return 0;
		}
		cout << 1 << endl << x << endl;
		return 0;
	}
	
	ll a = x;
	ll b = (y - a) / 2;
	ll c = b;
	
	string bin1 = base(a), bin2 = base(b);
	
	bool flag = true;
	for (int i = 0; i < min(int(bin1.size()), int(bin2.size())); i ++){
		if (bin1[i] == bin2[i] && bin1[i] == '1') flag = false;
	}
	
	if (flag){
		cout << 2 << endl << a + b << sep << c << endl;
		return 0;
	}
	
	cout << 3 << endl << a << sep << b << sep << c << endl;
	
	
	
	return 0;
}