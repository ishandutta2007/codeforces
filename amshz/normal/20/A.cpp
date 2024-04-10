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
const int xn = 1e6+10;
const int xm = 5e5+10;
const int SQ = 320;
const int inf = 1e9+10;


string a, b;

 
int main(){
	fast_io;
	
	cin >> a;
	for (int i = 0; i < a.size(); i++) if (i == 0 || a[i] != '/' || a[i-1] != '/') b += a[i];
	for (int i = b.size()-1; i >= 0; i--){
		if (b[i] != '/'){
			for (int j = 0; j <= i; j++) cout << b[j];
			cout << endl;
			return 0;
		}
	}
	cout << b << endl;

		
	return 0;
}