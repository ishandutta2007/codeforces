# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e5+10;
const int xm = 5e5+10;
const int SQ = 500;
const int inf = 1e9+10;

ld A, B, C, a, b, d;


 
int main(){
	fast_io;
	
	cin >> A >> B >> C;
	cout << fixed << setprecision(10);
	
	d = B*B - 4*A*C;
	
	if (A == 0 && B == 0 && C == 0){
		cout << -1 << endl;
		return 0;
	}
	
	if (A == 0){
		if (B == 0){
			cout << 0 << endl;
			return 0;
		}
		cout << 1 << endl << -(C / B) << endl;
		return 0;
	}
	a = (-B + sqrt(d)) / (2*A);
	b = (-B - sqrt(d)) / (2*A);
	
	if (a > b) swap(a, b);
	
	if (d < 0){
		cout << 0 << endl;
		return 0;
	}
	if (d == 0){
		cout << 1 << endl << a << endl;
		return 0;
	}
	cout << 2 << endl << a << endl << b << endl;
		
	return 0;
}