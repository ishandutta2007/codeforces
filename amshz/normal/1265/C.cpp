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
const int xn = 4e5+10;
const int xk = 320;

int c[xn], a[xn];

int main(){
	fast_io;
	
	int q;
	cin >> q;
	
	while (q--){
		int n;
		cin >> n;
		
		for (int i=0; i<n; i++) cin >> a[i];
		
		//memset(b, 0, b + n);
		vector <int> b;
		
		
		int t = 1;
		for (int i=1; i<n; i++){
			if (a[i] != a[i-1]){
				b.pb(t);
				t = 1;
			}
			else{
				t++;
			}
		}
		if (t > 0) b.pb(t);
		int m = b.size();
		//cout << b[0] << endl;
		c[0] = b[0];
		for (int i=1; i<b.size(); i++) c[i] = c[i-1] + b[i];
		//for (int i=0; i<b.size(); i++) cout << b[i] << sep;
		//cout << endl;
		
		int mx = 0, s = 0, g = 0, bb = 0;
		
		int p1 = 0, p2 = 0, p3 = 0;
		bool fl1 = 0;
		
		int dx = -1;
		for (int i=1; i<m; i++){
			if (c[i]-c[0] > c[0]){
				dx = -1;
				for (int j=i+1; j<m; j++){
					if (c[j]-c[i] > c[0] && c[j] <= c[m-1]/2) dx = j;
				}
				p2 = i, p3 = dx;
				if (dx == -1){
					cout << "0 0 0" << endl;
					fl1 = true;
				}
				break;
			}
			if (fl1) break;
		}
		if (fl1) continue;
		if (dx == -1){
			cout << "0 0 0" << endl;
			continue;
		}
		//cout << p1 << sep << p2 << sep << p3 << endl;
		cout << c[0] << sep << c[p2]-c[0] << sep << c[p3]-c[p2] << endl;
		
	}
	
	
	return 0;
}