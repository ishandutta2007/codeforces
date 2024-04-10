# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;
 
# define endl         '\n'
# define sep         ' '
# define F              first
# define S              second
# define pb             push_back
# define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 2e3+10;
const int xm = 5e4+10;

int n, m, b[xn];
string a[xn];
 
int main(){
    fast_io;
    
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    
    for (int i=0; i<m; i++){
    	for (int j=0; j<n; j++) if (a[j][i] == '1') b[i]++;
	}
	
	for (int i=0; i<n; i++){
		bool fl1 = true;
		for (int j=0; j<m; j++){
			if (a[i][j] == '1'){
				if (b[j] == 1) fl1 = false;
			}
			else{
				if (b[j] == 0) fl1 = false;
			}
		}
		if (fl1){
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
    
    return 0;
}