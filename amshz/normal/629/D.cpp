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
const int xm = 5e5+10;
const int SQ = 500;
const int inf = 1e9+10;

int n;
ld a[xn], dp[xn], f[xn];
ld P = 3.14159265358979323846264;
vector <pair <ld, int> > b[xn];

ld get(int l, int r, ld x){
	ld mx = 0;
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r){
			int lb = -1, rb = SQ, mid;
			while (rb-lb > 1){
				mid = (lb+rb)/2;
				if (b[i/SQ][mid].F < x) lb = mid;
				else rb = mid;
			}
			if (lb != -1) mx = max(mx, f[i+lb]);
			i += SQ;
		}
		else{
			if (a[i] < x) mx = max(mx, dp[i]);
			i++;
		}
	}
	return mx;
}
void update(int ind){
	f[ind*SQ] = dp[b[ind][0].S];
	for (int i = ind*SQ+1; i <= ind*SQ+SQ-1; i++){
		f[i] = max(dp[b[ind][i%SQ].S], f[i-1]);
	}
}

 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		ld x, y;
		cin >> x >> y;
		a[i] = x*x*y;
		b[i/SQ].pb({a[i], i});
	}
	for (int i = 0; i < 10000; i++) sort(b[i].begin(), b[i].end());
	
	dp[0] = a[0];
	
	for (int i = 1; i < n; i++){
		dp[i] = a[i] + get(0, i-1, a[i]);
		if (i%SQ == SQ-1) update(i/SQ);
	}
	ld mx = 0;
	for (int i = 0; i < n; i++) mx = max(mx, dp[i]);
	mx *= P;
	
	cout << setprecision(15) << mx << endl;
	
	return 0;
}