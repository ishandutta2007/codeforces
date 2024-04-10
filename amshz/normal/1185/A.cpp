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

int a[3];


int main(){
	fast_io;
	
	int d;
	for (int i=0; i<3; i++) cin >> a[i];
	cin >> d;
	sort(a, a+3);
	int ans = 0;
	if (a[1]-a[0] < d){
		//if (a[1]-1 < d) a[0] = d, a[1] = d+1, ans += (a[0]-d)+(d-a[1]+1);
	 	ans += d-(a[1]-a[0]);
	}
	if (a[2]-a[1] < d) ans += d-(a[2]-a[1]);
	cout << ans << endl;
	
	return 0;
}