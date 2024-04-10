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
 

string a, b, c, d;

 
 
 
int main(){
	fast_io;
	
	
	cin >> a >> b;
	
	bool flag = false;
	for (int i = 0; i < a.size(); i ++){
		if (a[i] == '0' && !flag) continue;
		flag = true;
		c += a[i];
	}
	
	flag = false;
	for (int i = 0; i < b.size(); i ++){
		if (b[i] == '0' && !flag) continue;
		flag = true;
		d += b[i];
	}
	
	a = c;
	b = d;
	
	if (a.size() < b.size()){
		cout << '<' << endl;
		return 0;
	}
	if (a.size() > b.size()){
		cout << '>' << endl;
		return 0;
	}
	for (int i = 0; i < a.size(); i ++){
		if (a[i] == b[i]) continue;
		if (a[i] < b[i]){
			cout << '<' << endl;
			return 0;
		}
		cout << '>' << endl;
		return 0;
	}
	
	cout << '=' << endl;
	
	return 0;
}