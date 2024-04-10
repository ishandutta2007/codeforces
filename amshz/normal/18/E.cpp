# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair < pair <int, int> , int> ppi;
typedef pair < pair <int, int> , ll> ppll;
typedef pair <ll, ll> pll;
typedef string str;

# define endl		 '\n'
# define sep		 ' '
# define F 			 first
# define S 			 second
# define pb			 push_back
# define fast_io 	 ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll md = 1e9+7;

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return (a*b)/gcd(a, b);}
ll pw(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pw(a*a, b/2)+md)%md;
	else return (a*pw(a*a, b/2)+md)%md;
}

const int xn = 5e2+10;
const int xm = 676+10;

string a[xn], abc = "abcdefghijklmnopqrstuvwxyz", c[xm];
int b[xn][xm];
pii dp[xn][xm];

string fn1(int p, int g){
	string ans = "";
	for (int i=0; i<g; i++) ans += c[p][i%2];
	return ans;
}

int main(){
	fast_io;
	
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> a[i];
	
	for (int i=0; i<26; i++){
		for (int j=0; j<26; j++){
			c[i*26+j] += abc[i];
			c[i*26+j] += abc[j];
			//cout << c[i+26+j] << endl;
		}
	}
	
	for (int i=0; i<n; i++){
		for (int j=0; j<676; j++){
			int s = 0;
			for (int k=0; k<m; k+=2){
				if (k == m-1) continue;
				if (a[i][k] != c[j][0]) s++;
				if (a[i][k+1] != c[j][1]) s++;
			}
			if (m%2 && a[i][m-1] != c[j][0]) s++;
			b[i][j] = s;
		}
	}
	
	for (int i=0; i<676; i++) dp[0][i].F = b[0][i];
	
	for (int i=1; i<n; i++){
		for (int j=0; j<676; j++){
			int mn = 1e9+10, dx = -1;
			for (int k=0; k<676; k++){
				if (c[j][0] == c[k][0] || c[j][1] == c[k][1] || c[k][0] == c[k][1]) continue;
				
				int s = b[i][j] + dp[i-1][k].F;
				if (s < mn){
					dx = k;
					mn = s;
				}
			}
			dp[i][j].F = mn;
			dp[i][j].S = dx;
		}
	}
	//cout << 45 << endl;

	vector <string> ans;
	int dx = -1, mn = 1e9+10;
	for (int i=0; i<676; i++){
		if (dp[n-1][i].F < mn && c[i][0] != c[i][1]) mn = dp[n-1][i].F, dx = i;
	}
	ans.pb(fn1(dx, m));
	
	cout << mn << endl;
	
	int d = n-1;
	while (d > 0){
		ans.pb(fn1(dp[d][dx].S, m));
		dx = dp[d][dx].S;
		d--;
	}
	
	for (int i=n-1; i>=0; i--) cout << ans[i] << endl;
	
	
	return 0;
}

/*
8
23 2 7 5 15 8 4 10
*/