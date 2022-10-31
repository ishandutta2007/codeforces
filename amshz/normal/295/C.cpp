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

const int xn = 5e1+10;
const int xm = 1e2+10;

int ans[xn][xn][2];
ll t[xn][xn][2];
ll ent[xn][xn];

int main(){
	fast_io;
	
	int n, k;
	cin >> n >> k;
	int g, x, y;
	x = 0, y = 0;
	for (int i=0; i<n; i++){
		cin >> g;
		if (g == 50) x++;
		else y++;
	}
	ent[0][0] = 1;
	for (int i=1; i<=50; i++){
		for (int j=0; j<=50; j++){
			ent[i][j] = ent[i-1][j-1] + ent[i-1][j] + md;
			ent[i][j] %= md;
		}
	}
	
	for (int i=0; i<=50; i++) for (int j=0; j<=50; j++) for (int p=0; p<2; p++) ans[i][j][p] = -1;
	
	queue <pair <pii, bool> > q;
	ans[x][y][0] = 0, t[x][y][0] = 1;
	q.push({{x, y}, 0});
	ll yk = 1;
	
	while (q.size()){
		int v = q.front().F.F, u = q.front().F.S;
		bool f = q.front().S;
		q.pop();
		
		for (int i=0; i<=v; i++){
			for (int j=0; j<=u; j++){
				if (!(i == 0 && j == 0) && (i*50+j*100 <= k) && (ans[x-v+i][y-u+j][1-f] == ans[v][u][f]+1)) t[x-v+i][y-u+j][1-f] += max(yk, ent[v][i])*max(yk, ent[u][j])*t[v][u][f]+md, t[x-v+i][y-u+j][1-f] %= md;
				if ((i == 0 && j == 0) || (i*50+j*100 > k) || (ans[x-v+i][y-u+j][1-f] != -1)) continue;
				q.push({{x-v+i, y-u+j}, 1-f});
				ans[x-v+i][y-u+j][1-f] = ans[v][u][f]+1;
				t[x-v+i][y-u+j][1-f] = max(yk, ent[v][i])*max(yk, ent[u][j])*t[v][u][f]+md;
				t[x-v+i][y-u+j][1-f] %= md;
			}
		}
	}
	
	cout << ans[x][y][1] << endl;
	if (ans[x][y][1] == -1) cout << 0 << endl;
	else cout << t[x][y][1] << endl;
	
	return 0;
}