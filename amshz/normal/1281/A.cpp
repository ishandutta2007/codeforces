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
const int xk = 1e2+10;


int main(){
	fast_io;
	
	int qq;
	cin >> qq;
	while (qq--){
		string a;
		cin >> a;
		
		int n = a.size();
		
		if (a.size() >= 2 && a[n-1] == 'o' && a[n-2] == 'p'){
			cout << "FILIPINO" << endl;
			continue;
		}
		if (a.size() >= 4 && ((a[n-1] == 'u' && a[n-2] == 's' && a[n-3] == 'e' && a[n-4] == 'd') || (a[n-1] == 'u' && a[n-2] == 's' && a[n-3] == 'a' && a[n-4] == 'm'))){
			cout << "JAPANESE" << endl;
			continue;
		}
		if (n >= 5){
			if (a[n-1] == 'a' && a[n-2] == 'd' && a[n-3] == 'i' && a[n-4] == 'n' && a[n-5] == 'm'){
				cout << "KOREAN" << endl;
				continue;
			}
		}
	}
	
	return 0;
}