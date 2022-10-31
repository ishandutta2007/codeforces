# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e5+10;
const int xk = 320;

int a[xn];
bool f[xn];

int main(){
	
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=1; i<=n; i++) f[i] = false;
		f[1] = true;
		
		int dx;
		for (int i=0; i<n; i++) if (a[i] == 1) dx = i;
		
		int mx = 0, l = dx, r = dx;
		
		while (r-l < n-1){
			int mn = 1e9;
			
			if (r < n-1) mn = min(mn, a[r+1]);
			if (l > 0) mn = min(mn, a[l-1]);
			
			if (r < n-1 && a[r+1] == mn){
				r += 1;
				mx = max(mx, mn);
			}
			else{
				l -= 1;
				mx = max(mx, mn);
			}
			
			if (mx == r-l+1) f[mx] = true;
		}
		
		for (int i=1; i<=n; i++) cout << f[i];
		cout << endl;
	}
	
	
	return 0;
}