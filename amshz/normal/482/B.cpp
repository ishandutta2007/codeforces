# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const ll MD = md * 100;
const int xn = 1e5 + 10;
const int xlg = 33;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

string base2(ll x){
	string ans = "";
	while (x){
		if (x % 2) ans += '1';
		else ans += '0';
		x /= 2;
	}
	return ans;
}


int n, m;
int PS[xlg][xn], a[xlg][xn];
pair <pii, ll> Q[xn];
bool flag;


void Update(int l, int r, int ind){
	PS[ind][l] ++;
	PS[ind][r + 1] --;
}
void Get(int l, int r, int ind){
	int t = PS[ind][r] - PS[ind][l - 1];
	if (t == r - l + 1) flag = true;
}

ll Find(int ind){
	ll ans = 0;
	for (int i = 0; i < 31; i ++){
		if (a[i][ind]) ans += (1 << i);
	}
	return ans;
}


 
int main(){
	fast_io;
	
	
	cin >> n >> m;
	int l, r;
	ll x;
	for (int i = 0; i < m; i ++){
		cin >> l >> r >> x;
		Q[i] = {{l, r}, x};
		string bin = base2(x);
		for (int j = 0; j < bin.size(); j ++){
			if (bin[j] == '0') continue;
			Update(l, r, j);
		}
	}
	for (int i = 0; i < 31; i ++){
		for (int j = 1; j <= n; j ++) PS[i][j] += PS[i][j  - 1];
		for (int j = 1; j <= n; j ++) if (PS[i][j]) PS[i][j] = 1, a[i][j] = PS[i][j];
		for (int j = 1; j <= n; j ++) PS[i][j] += PS[i][j - 1];
	}
	
	for (int i = 0; i < m; i ++){
		int l = Q[i].F.F, r = Q[i].F.S;
		ll x = Q[i].S;
		string bin = base2(x);
		for (int j = 0; j < 31; j ++){
			if (j < bin.size() && bin[j] == '1') continue;
			Get(l, r, j);
			if (flag){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	
	for (int i = 1; i <= n; i ++) cout << Find(i) << sep;
	cout << endl;
	
	
	return 0;
}