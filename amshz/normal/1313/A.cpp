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
const int xn = 1e6+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}


int qq;



int main(){
	fast_io;
	
	
	cin >> qq;
	while (qq--){
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		if (a) ans ++, a --;
		if (b) ans ++, b --;
		if (c) ans ++, c --;
		
		if (c > b) swap(b, c);
		if (b > a) swap(a, b);
		if (c > b) swap(b, c);
		
		if (a && b) ans ++, a --, b --;
		if (a && c) ans ++, a --, c --;
		if (b && c) ans ++, b --, c --;
		
		if (a && b && c) ans ++;
		
		cout << ans << endl;
	}
	
	
	return 0;
}