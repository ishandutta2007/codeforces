# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e5+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

bool check(pii a1, pii a2, pii a3, pii a4){
	return (a1.F - a2.F == a4.F - a3.F && a1.S - a2.S == a4.S - a3.S);
}
int n;
pii x[xn];



int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i].F >> x[i].S;
	
	if (n%2){
		cout << "NO" << endl;
		return 0;
	}
	
	for (int i = 0; i < n/2 - 1; i++){
		int j = i + n / 2;
		if (!check(x[i], x[i+1], x[j], x[j+1])){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
	
	
	return 0;
}