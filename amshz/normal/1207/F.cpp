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
const int xn = 5e5+10;
const int xm = 5e2+10;
const int SQ = 1000;
 
int a[xn], b[xm][xm], q;

 
int main(){
	fast_io;
	
	cin >> q;
	while (q--){
		int x, y, z;
		cin >> x >> y >> z;
		if (x == 1){
			a[y] += z;
			for (int i = 1; i <= 5e2; i++) b[i][y%i] += z;
		}
		else{
			if (y > 5e2){
				int ans = 0;
				for (int i = z; i <= 5e5; i+=y) ans += a[i];
				cout << ans << endl;
			}
			else{
				cout << b[y][z] << endl;
			}
		}
	}
	
	return 0;
}