# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair < pair <int, int> , int> ppi;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 1e5+10;
const int xm = 1e6+10;
const int xk = 1e4+10;
const int SQ = 320;
const int sq = 6e2+10;
const ll inf = 1e18+10;


int n, q, x, y, t;
bool f[3][xn], flag[xn];


int fn1(int r, int c){
	int ans = 0;
	if (f[3-r][c-1]) ans++;
	if (f[3-r][c]) ans++;
	if (f[3-r][c+1]) ans++;
	if (!f[r][c]) ans = -ans;
	return ans;
}
 
int main(){
	fast_io;
	
	cin >> n >> q;
	while (q--){
		cin >> x >> y;
		f[x][y] = 1-f[x][y];
		t += fn1(x, y);
		//cout << t << endl;
		if (t == 0){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
	
	return 0;
}