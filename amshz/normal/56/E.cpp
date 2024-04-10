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
const int SQ = 1000;
 
ppi a[xn];
int n, res[xn], c[xn], b[xn], dp[xn];


int get(int l, int r){
	int mx = l;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			if (c[b[i/SQ]] > c[mx]) mx = b[i/SQ];
			i += SQ;
		}
		else{
			if (c[i] > c[mx]) mx = i;
			i++;
		}
	}
	return mx;
}

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].F.F >> a[i].F.S, a[i].S = i;
	
	sort(a, a+n);
	
	for (int i = 0; i < n; i++){
		int l = i, r = n;
		while (r-l > 1){
			int mid = (l+r)/2;
			if (a[mid].F.F < a[i].F.F + a[i].F.S) l = mid;
			else r = mid;
		}
		c[i] = l;
	}
	
	for (int i = 0; i < n; i++) {
		if (i%SQ == 0 || c[i] > c[b[i/SQ]]) b[i/SQ] = i;
	}
	
	for (int i = n-1; i > -1; i--){
		dp[i] = c[i];
		int d = get(i, c[i]);
		dp[i] = dp[d];
		res[a[i].S] = dp[i] - i + 1;
	}
	for (int i = 0; i < n; i++) cout << res[i] << sep;
	cout << endl;
	
	return 0;
}