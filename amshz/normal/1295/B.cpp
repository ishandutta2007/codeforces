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
const int xn = 1e6+10;
const int xm = 3e5+10;
const int SQ = 1000;
const int sq = 1e3+10;
const int inf = 1e9+10;

ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int a[xn], qq, n, x;
string s;


 
int main(){
	fast_io;
	
	cin >> qq;
	while (qq--){
		cin >> n >> x;
		cin >> s;
		int t = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == '0') t++;
			else t--;
			a[i] = t;
			
			//cout << a[i] << sep;
		}
		bool fl1 = false;
		for (int i = 0; i < n; i++){
			if (a[i] == x && a[n-1] == 0){
				fl1 = true;
				break;
			}
		}
		if (fl1){
			cout << -1 << endl;
			continue;
		}
		if (a[n-1] == 0){
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		for (int i = 0; i < n; i++){
			if ((x-a[i])%a[n-1] == 0 && ((x-a[i] >= 0 && a[n-1] >= 0) || (x-a[i] <= 0 && a[n-1] < 0))) ans++;
		}
		if (x == 0) ans++;
		cout << ans << endl;
	}
	
	
	return 0;
}