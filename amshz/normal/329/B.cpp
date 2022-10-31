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

int fn1(char a){
	return a-'0';
}
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a%b);}
ll lcm(ll a, ll b){ return a*b/gcd(a, b);}
ll pmd(ll a, ll b){
	if (b == 1) return (a+md)%md;
	if (b%2 == 0) return (pmd(a*a, b/2)+md)%md;
	else return (a*pmd(a*a, b/2)+md)%md;
}

const int xn = 1e3+10;
const int xm = 1e2+10;

int ans[xn][xn];
char a[xn][xn];
bool mark[xn][xn];

int main(){
	fast_io;
	
	int n, m;
	cin >> n >> m;
	
	for (int i=0; i<n; i++){
		string g;
		cin >> g;
		for (int j=0; j<m; j++) a[i][j] = g[j];
	}
	
	queue <pii> q;
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) ans[i][j] = 1e9;
	
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j] == 'E') q.push({i, j}), ans[i][j] = 0;
			
			
	while (q.size()){
		int x = q.front().F, y = q.front().S;
		q.pop();
		
		if (x > 0 and ans[x-1][y] == 1e9 and a[x-1][y] != 'T') ans[x-1][y] = ans[x][y]+1, q.push({x-1, y});
		if (x < n-1 and ans[x+1][y] == 1e9 and a[x+1][y] != 'T') ans[x+1][y] = ans[x][y]+1, q.push({x+1, y});
		if (y > 0 and ans[x][y-1] == 1e9 and a[x][y-1] != 'T') ans[x][y-1] = ans[x][y]+1, q.push({x, y-1});
		if (y < m-1 and ans[x][y+1] == 1e9 and a[x][y+1] != 'T') ans[x][y+1] = ans[x][y]+1, q.push({x, y+1});
	}
	
	int s = 0;
	int b = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j] == 'S') b = ans[i][j];
	
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (a[i][j] != 'T' and a[i][j] != 'S' and a[i][j] != 'E' and ans[i][j] <= b) s += fn1(a[i][j]); 
			
	cout << s << endl;
	return 0;
}