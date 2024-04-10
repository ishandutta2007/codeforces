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
const int xm = 2e5+2;
const int xk = 1e5+2;
const int SQ = 320;
const int SQ2 = 4090;
const int SQ3 = 75;
const int inf = 1e9+10;
 

ll n, k, a[xn], inv[xn][2], b[xn], c[xn], tot, ans, d[xn], e[xn];
unordered_map <ll, ll> mp;

void Compress(){
	vector <ll> vec;
	for (int i = 0; i < n; i++) vec.pb(a[i]);
	sort(vec.begin(), vec.end());
	ll s = 1;
	for (int i = 0; i < n; i++){
		if (i == 0 || vec[i] != vec[i-1]) mp[vec[i]] = s++;
	}
	for (int i = 0; i < n; i++) a[i] = mp[a[i]];
}

void Build(){
	for (int i = 0; i <= n; i++) b[i] = c[i] = 0;
}

void update(int l, int r){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r) b[i/SQ]++, i += SQ;
		else c[i]++, i++;
	}
}
void update2(int l, int r, int x){
	for (int i = l; i <= r;){
		if (i%SQ == 0 && i+SQ-1 <= r) d[i/SQ] += x, i += SQ;
		else e[i] += x, i++;
	}
}
 
 
int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	Compress();
	Build();

	for (int i = 0; i < n; i++){
		update(1, a[i]-1);
		inv[i][0] = c[a[i]] + b[a[i]/SQ];
		tot += inv[i][0];
	}
	
	for (int i = 1; i < n; i++) inv[i][0] += inv[i-1][0];
	Build();
	for (int i = n-1; i >= 0; i--){
		update(a[i]+1, n+1);
		inv[i][1] = c[a[i]] + b[a[i]/SQ];
	}
	
	for (int i = n-1; i >= 0; i--) inv[i][1] += inv[i+1][1];
	Build();
	
	int l = 0, r = 1;
	update(1, a[0]-1);
	ll invers = tot;
	
	for (int i = r; i < n; i++) update2(a[i]+1, n+1, 1);
	
	while (l < n-1 && r < n){
		while (invers > k || r <= l){
			r++;
			if (r == n) break;
			update2(a[r-1]+1, n+1, -1);
			invers -= inv[r-1][1] - inv[r][1];
			invers -= b[a[r-1]/SQ] + c[a[r-1]];
		}
		ans += n - r;
		invers += inv[l+1][0] - inv[l][0];
		update(1, a[l+1]-1);
		l++;
		invers += d[a[l]/SQ] + e[a[l]];
	}
	cout << ans << endl;
	
	return 0;
}
/*
7 3
1 7 6 4 9 5 3
*/