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

const int xn = 2e3+10;
const int xm = 1e2+10;

int ans[xn][xn];
bool mark[xn][xn];

int main(){
	fast_io;
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int n, m;
	cin >> n >> m;
	
	queue <pii> q;
	
	int x, y;
	int k;
	cin >> k;
	for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) ans[i][j] = 1e9;
	for (int i=0; i<k; i++) cin >> x >> y, q.push({x, y}), ans[x][y] = 0;
	while (q.size()){
		int x = q.front().F, y = q.front().S;
		mark[x][y] = true;
		q.pop();
		if (x > 1 and !mark[x-1][y]) ans[x-1][y] = min(ans[x-1][y], ans[x][y]+1), q.push({x-1, y}), mark[x-1][y] = true;
		if (x < n and !mark[x+1][y]) ans[x+1][y] = min(ans[x+1][y], ans[x][y]+1), q.push({x+1, y}), mark[x+1][y] = true;
		if (y > 1 and !mark[x][y-1]) ans[x][y-1] = min(ans[x][y-1], ans[x][y]+1), q.push({x, y-1}), mark[x][y-1] = true;
		if (y < m and !mark[x][y+1]) ans[x][y+1] = min(ans[x][y+1], ans[x][y]+1), q.push({x, y+1}), mark[x][y+1] = true;
	}
	int mx = 0;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) mx = max(mx, ans[i][j]);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			if (ans[i][j] == mx){
				cout << i << sep << j << endl;
				return 0;
			}
		}
	}
	return 0;
}