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

ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 5e3+10;
const int xk = 5e3+10;

ll dp[xn][2], ps[xn][2], ans;
int n, k, a, b, l, r;


int main(){
	fast_io;
	
	cin >> n >> a >> b >> k;
	
	dp[a][0] = 1;
	
	for (int i=a; i<=n; i++) ps[i][0] = 1;
	
	for (int i=1; i<=k; i++){
		for (int j=1; j<=n; j++){
			if (j == b){
				ps[j][i%2] = ps[j-1][i%2];
				dp[j][i%2] = 0;
				continue;
			}
			
			if (j > b) r = n, l = (j+b)/2;
			else r = (j+b+1)/2-1, l = 0; 
			
			dp[j][i%2] = (ps[r][(i+1)%2] - ps[l][(i+1)%2] - dp[j][!(i%2)] + md) % md;
			ps[j][i%2] = (dp[j][i%2] + ps[j-1][i%2] + md) % md;
			
		}
	}
	
	cout << ps[n][k%2] << endl;
	
	return 0;
}