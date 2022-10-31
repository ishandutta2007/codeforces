
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

const int xn = 3e3+10;
const int xm = 1e2+10;

int a[xn], dis[xn][xn], ans, n, k;
bool f[xn], f2[xn], mark[xn][xn];

void update(int x, int y, int x2, int y2){
	dis[x][y] = dis[x2][y2]+1;
	return;
}



int main(){
	
	fast_io;
	
	cin >> n >> k;
	
	for (int i=0; i<n; i++) cin >> a[i];
	
	for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dis[i][j] = 1e9;
	
	if (a[n-1] > 0) f[n-1] = true;
	for (int i=n-2; i>=0; i--) if (f[i+1] || a[i] > 0) f[i] = true;
	
	if (a[n-1] == 100) f2[n-1] = true;
	for (int i=n-2; i>=0; i--) if (f2[i+1] || a[i] == 100) f2[i] = true;
	
	queue <pii> q;
	
	dis[0][0] = 0;
	mark[0][0] = true;
	q.push({0, 0});
	
	while (q.size()){
		int x = q.front().F, y = q.front().S;
		q.pop();
		
		if (dis[x][y] == k) continue;
		
		if (y == 0){
			if (x+2 <= n && f[x+1] && a[x]){
				if (!mark[x+2][y]){
				q.push({x+2, y}), mark[x+2][y] = true;
				update(x+2, y, x, y);}
				if (f2[x+1] && a[x] == 100) continue;
			}
			if (x+1 <= n && f[x+1] && a[x] < 100){
				if (!mark[x+1][y]){
				q.push({x+1, y}), mark[x+1][y] = true;
				update(x+1, y, x, y);}
				if (f2[x+1]) continue;
			}
			if (x+2 <= n && a[x]){
				if (!mark[x][1]){
				q.push({x, 1}), mark[x][1] = true;
				update(x, 1, x, 0);}
				if (a[x] == 100) continue;
			}
		}
		else{
			if (x+y+2 <= n && f[x+y+1] && a[x]){
				if (!mark[x+y+2][0]){
				q.push({x+y+2, 0}), mark[x+y+2][0] = true;
				update(x+y+2, 0, x, y);}
				if (f2[x+y+1] && a[x] == 100) continue;
			}
			if (f[x+y+1] && a[x] < 100){
				if (!mark[x+y+1][0]){
				q.push({x+y+1, 0}), mark[x+y+1][0] = true;
				update(x+y+1, 0, x, y);}
				if (f2[x+y+1]) continue;
			}
			if (x+y+2 <= n && a[x]){
				if (!mark[x][y+1]){
				q.push({x, y+1}), mark[x][y+1] = true;
				update(x, y+1, x, y);}
				if (a[x] == 100) continue;
			}
		}
	}
	
	for (int i=0; i<=n; i++){
		for (int j=0; j<=n; j++){
			if (j == 0)
				if (dis[i][j] <= k ) ans++;
			if (j > 0)
				if (dis[i][j] <= k) ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}