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
 
int qq;
int n, a[xn];
bool mark[xn];
 
 
int main(){
	fast_io;
	
	cin >> qq;
	while (qq --){
		memset(mark, false, sizeof mark);
		cin >> n;
		for (int i = 1; i <= n; i ++) cin >> a[i];
		a[0] = a[n], a[n + 1] = a[1];
		int t = 0;
		for (int i = 1; i <= n; i ++){
			if (a[i] != a[i - 1]) t ++;
		}
		if (t == 0){
			cout << 1 << endl;
			for (int i = 0; i < n; i ++) cout << 1 << sep;
			cout << endl;
			continue;
		}
		if (t % 2 == 0){
			cout << 2 << endl;
			int s = 1;
			for (int i = 1; i <= n; i ++){
				if (a[i] == a[i - 1]) cout << s << sep;
				else{
					s = 3 - s;
					cout << s << sep;
				}
			}
			cout << endl;
			continue;
		}
		if (t == n){
			cout << 3 << endl;
			cout << 3 << sep;
			for (int i = 2; i <= n; i ++){
				if (i % 2) cout << 1 << sep;
				else cout << 2 << sep;
			}
			cout << endl;
			continue;
		}
		cout << 2 << endl;
		for (int i = 1; i <= n; i ++){
			if (a[i] == a[i - 1]){
				mark[i] = true;
				break;
			}
		}
		int s = 1;
		for (int i = 1; i <= n; i ++){
			if (a[i] != a[i - 1] || mark[i]){
				s = 3 - s;
				cout << s << sep;
			}
			else cout << s << sep;
		}
		cout << endl;
	}
	
	return 0;
}