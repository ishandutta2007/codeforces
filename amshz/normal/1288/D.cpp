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
const int xn = 3e5+10;
const int xm = 5e5+10;
const int SQ = 700;
const ll inf = 1e18+10;


int a[xn][8], n, m;
int f[300], ff[300];
bool fl[xn];
pii ans;

void bin(int s){
	int ss = s;
	for (int i = 0; i < 10; i++) fl[i] = 0;
	int t = 0;
	while (s){
		if (s%2) fl[t] = 1;
		t++;
		s /= 2;
	}
	int mx = -1, dx = -1;
	for (int i = 0; i < n; i++){
		int mn = -1;
		for (int j = 0; j < m; j++){
			if (!fl[j]) continue;
			if (mn == -1) mn = a[i][j];
			mn = min(mn, a[i][j]);
		}
		if (mx == -1 || mx < mn) dx = i+1;
		mx = max(mx, mn);
	}
	f[ss] = dx;
	ff[ss] = mx;
}

bool check(int x){
	for (int i = 1; i < pow(2, m)-1; i++){
		if (ff[i] >= x && ff[int(pow(2, m)-i-1)] >= x){
			ans = {f[i], f[int(pow(2, m)-i-1)]};
			return true;
		}
	}
	int k = pow(2, m)-1;
	if (ff[k] >= x){
		ans = {f[k], f[k]};
		return true;
	}
	
	return false;
}
 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int i = 0; i < pow(2, m); i++) bin(i);
	
	
	int l, r, mid;
	
	l = 0, r = 1e9+10;
	
	while (r-l > 1){
		mid = (l+r)/2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	if (l == 0){
		cout << 1 << sep << 1 << endl;
		return 0;
	}
	cout << ans.F << sep << ans.S << endl;
		
	return 0;
}