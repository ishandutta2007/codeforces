# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xm = 1e2+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int qq, n;
string a;



int main(){
	fast_io;
	
	
	cin >> qq;
	while (qq--){
		cin >> n >> a;
		int sm = 0;
		int dx = -1;
		for (int i = n-1; i >= 0; i--){
			int g = a[i]-'0';
			if (g%2){
				dx = i;
				break;
			}
		}
		if (dx == -1){
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i <= dx; i++){
			sm += a[i]-'0';
		}
		if (sm%2 == 0){
			for (int i = 0; i <= dx; i++) cout << a[i];
			cout << endl;
			continue;
		}
		int ind = -1;
		for (int i = 0; i < dx; i++){
			int g = a[i]-'0';
			if (g%2){
				ind = i;
				break;
			}
		}
		if (ind == -1){
			cout << -1 << endl;
			continue;
		}
		bool fl1 = false;
		for (int i = 0; i <= dx; i++){
			if (a[i]-'0' > 0 && i != ind) fl1 = true;
			if (i != ind && fl1) cout << a[i];
		}
		cout << endl;
		
	}
	
	
	return 0;
}