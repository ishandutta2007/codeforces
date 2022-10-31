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
 
const ll md = 1e9+7;
const int xn = 2e3+10;
const int xm = 30+10;
const int SQ = 200;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

ll C[xn][xn], n;


int main(){
	fast_io;
	
	cin >> n;
	for (int i = 1; i <= 2 * n; i++){
		for (int j = 0; j <= i; j++){
			ll T = 0;
			if (j > 0){
				C[i][j] += C[i - 1][j - 1];
				C[i][j] %= md;
				T++;
			}
			if (j < i){
				C[i][j] += C[i - 1][j + 1];
				C[i][j] %= md;
				T++;
			}
			if (i % 2) C[i][j]++, C[i][j] %= md;
		}
	}
	
	cout << C[2 * n][0] << endl;
	
	
	return 0;
}