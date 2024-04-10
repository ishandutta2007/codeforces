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

int a[xn];
pii p[xn];
int b[xn];

bool cmp(pii q, pii w){
	return q.S < w.S;
}


int main(){
	fast_io;
	//cout << pow(3, 14);
	int qq;
	cin >> qq;
	while (qq--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		int m;
		cin >> m;
		for (int i=0; i<m; i++) cin >> p[i].F >> p[i].S;
		
		sort(p, p+m, cmp);
		for (int i=0; i<n; i++) b[i] = 0;
		for (int i=0; i<m; i++) b[p[i].S-1] = max(b[p[i].S-1], p[i].F);
		for (int i=n-2; i>=0; i--) b[i] = max(b[i], b[i+1]);
		int ans = 0;
		int t = 0;
		//for (int i=0; i<n; i++) cout << b[i] << sep;
		//cout << endl;
		while (true){
			int mn = a[t];
			int k = 0;
			for (int i=t; i<n; i++){
				mn = max(mn, a[i]);
				if (i == n) break;
				//cout << b[i-t] << sep << mn << endl;
				if (b[i-t] < mn){
					//cout << k << endl;
					break;
				}
				k++;
			}
			if (k == 0){
				ans = -1;
				break;
			}
			t += k;
			ans++;
			if (t == n) break;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}