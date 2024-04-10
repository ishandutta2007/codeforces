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
 
int n, t;
string a, b;
 
 
int main(){
	fast_io;
	
	cin >> a;
	n = a.size();
	
	for (int i = a.size()-1; i >= 0; i--){
		if (a[i] == '0') t++;
		else t--;
		
		if (a[i] == '0'){
			b = '0' + b;
			continue;
		}
		
		if (t >= 0) b = '1' + b;
		else t++, b = '0' + b;
		
	}
	
	cout << b << endl;
	
	return 0;
}