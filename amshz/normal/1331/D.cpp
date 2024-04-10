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


string a;
 
int main(){
	fast_io;
	
	cin >> a;
	cout << (a[6] - '0') % 2 << endl;
	
	return 0;
}