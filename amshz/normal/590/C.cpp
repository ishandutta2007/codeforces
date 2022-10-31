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

ll ans[xn][xn], s[xn][xn];
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
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) ans[i][j] = 1e9;
	
	deque <pii> q;
	
	bool fl1 = false;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == '1') fl1 = true, q.push_front({i, j}), ans[i][j] = 0;
			if (fl1) break;
		}
		if (fl1) break;
	}
	
	while (q.size()){
		int x = q.front().F, y = q.front().S;
		q.pop_front();
		
		if (x > 0 and a[x-1][y] != '#' and ans[x-1][y] == 1e9){
			if (a[x-1][y] == '.') q.push_back({x-1, y}), ans[x-1][y] = ans[x][y]+1;
			else ans[x-1][y] = ans[x][y], q.push_front({x-1, y});
		}
		if (x < n-1 and a[x+1][y] != '#' and ans[x+1][y] == 1e9){
			if (a[x+1][y] == '.') q.push_back({x+1, y}), ans[x+1][y] = ans[x][y]+1;
			else ans[x+1][y] = ans[x][y], q.push_front({x+1, y});
		}
		if (y > 0 and a[x][y-1] != '#' and ans[x][y-1] == 1e9){
			if (a[x][y-1] == '.') q.push_back({x, y-1}), ans[x][y-1] = ans[x][y]+1;
			else q.push_front({x, y-1}), ans[x][y-1] = ans[x][y];
		}
		if (y < m-1 and a[x][y+1] != '#' and ans[x][y+1] == 1e9){
			if (a[x][y+1] == '.') q.push_back({x, y+1}), ans[x][y+1] = ans[x][y]+1;
			else q.push_front({x, y+1}), ans[x][y+1] = ans[x][y];
		}
	}
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) s[i][j] += ans[i][j];
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) ans[i][j] = 1e9;
	while (q.size()) q.pop_front();
	
	fl1 = false;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == '2') fl1 = true, q.push_front({i, j}), ans[i][j] = 0;
			if (fl1) break;
		}
		if (fl1) break;
	}
	
	while (q.size()){
		int x = q.front().F, y = q.front().S;
		q.pop_front();
		
		if (x > 0 and a[x-1][y] != '#' and ans[x-1][y] == 1e9){
			if (a[x-1][y] == '.') q.push_back({x-1, y}), ans[x-1][y] = ans[x][y]+1;
			else ans[x-1][y] = ans[x][y], q.push_front({x-1, y});
		}
		if (x < n-1 and a[x+1][y] != '#' and ans[x+1][y] == 1e9){
			if (a[x+1][y] == '.') q.push_back({x+1, y}), ans[x+1][y] = ans[x][y]+1;
			else ans[x+1][y] = ans[x][y], q.push_front({x+1, y});
		}
		if (y > 0 and a[x][y-1] != '#' and ans[x][y-1] == 1e9){
			if (a[x][y-1] == '.') q.push_back({x, y-1}), ans[x][y-1] = ans[x][y]+1;
			else q.push_front({x, y-1}), ans[x][y-1] = ans[x][y];
		}
		if (y < m-1 and a[x][y+1] != '#' and ans[x][y+1] == 1e9){
			if (a[x][y+1] == '.') q.push_back({x, y+1}), ans[x][y+1] = ans[x][y]+1;
			else q.push_front({x, y+1}), ans[x][y+1] = ans[x][y];
		}
	}
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) s[i][j] += ans[i][j];
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) ans[i][j] = 1e9;
	while (q.size()) q.pop_front();
	
	fl1 = false;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == '3') fl1 = true, q.push_front({i, j}), ans[i][j] = 0;
			if (fl1) break;
		}
		if (fl1) break;
	}
	
	while (q.size()){
		int x = q.front().F, y = q.front().S;
		q.pop_front();
		
		if (x > 0 and a[x-1][y] != '#' and ans[x-1][y] == 1e9){
			if (a[x-1][y] == '.') q.push_back({x-1, y}), ans[x-1][y] = ans[x][y]+1;
			else ans[x-1][y] = ans[x][y], q.push_front({x-1, y});
		}
		if (x < n-1 and a[x+1][y] != '#' and ans[x+1][y] == 1e9){
			if (a[x+1][y] == '.') q.push_back({x+1, y}), ans[x+1][y] = ans[x][y]+1;
			else ans[x+1][y] = ans[x][y], q.push_front({x+1, y});
		}
		if (y > 0 and a[x][y-1] != '#' and ans[x][y-1] == 1e9){
			if (a[x][y-1] == '.') q.push_back({x, y-1}), ans[x][y-1] = ans[x][y]+1;
			else q.push_front({x, y-1}), ans[x][y-1] = ans[x][y];
		}
		if (y < m-1 and a[x][y+1] != '#' and ans[x][y+1] == 1e9){
			if (a[x][y+1] == '.') q.push_back({x, y+1}), ans[x][y+1] = ans[x][y]+1;
			else q.push_front({x, y+1}), ans[x][y+1] = ans[x][y];
		}
	}
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) s[i][j] += ans[i][j];
	/*
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == '#'){
				cout << sep;
				continue;
			}
			cout << s[i][j];
		}
		cout << endl;
	}
	*/
	
	ll mn = 1e12;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == '#') continue;
			if (a[i][j] == '.') s[i][j] -= 2, mn = min(mn, s[i][j]);
			else s[i][j] -= 0, mn = min(mn, s[i][j]);
		}
	}
	if (mn >= 1e9-10) mn = -1;
	cout << mn << endl;
	return 0;
}