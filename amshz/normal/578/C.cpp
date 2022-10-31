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

string bin(ll n){
	string ans = "";
	while (n > 0){
		if (n%2 == 0) ans = '0'+ans;
		else ans = '1'+ans;
		n /= 2;
	}
	return ans;
}
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 2e5+10;
const int xm = 1e2+10;

ld a[xn], dp[xn];
int n;

ld check(ld x){
	ld mx = -1e9;
	dp[0] = a[0]-x;
	mx = max(mx, abs(dp[0]));
	for (int i=1; i<n; i++) dp[i] = max(dp[i-1]+a[i]-x, a[i]-x), mx = max(mx, abs(dp[i]));
	
	for (int i=1; i<n; i++) dp[i] = min(dp[i-1]+a[i]-x, a[i]-x), mx = max(mx, abs(dp[i]));
	
	return mx;
}


int main(){
	fast_io;
	
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	
	ld l = -1e4-10, r = 1e4+10, m1, m2;
	ll td = 150;
	
	while (td--){
		m1 = l+(r-l)/3;
		m2 = r-(r-l)/3;
		
	 	if (check(m1) < check(m2)) r = m2;
	 	else l = m1;
	 	//cout << l << sep << r << endl;
	}
	cout << setprecision(7) << fixed << check(l) << endl;
	//cout << check(l) << endl;
	
	return 0;
}