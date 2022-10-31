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

const int xn = 7e1+10;
const int xm = 1e2+10;

map <ppi, ppi> mp;
map <ppi, pii> ans;
map <ppi, int> m;
vector <pii> vec;
char a[xn][xn];

ppi srt(ppi g){
	int sm = g.F.F + g.F.S + g.S;
	ppi ns;
	int mn = g.F.F;
	mn = min(mn, g.F.S);
	mn = min(mn, g.S);
	
	int mx = g.F.F;
	mx = max(mx, g.F.S);
	mx = max(mx, g.S);
	
	ns.F.F = mn, ns.S = mx, ns.F.S = sm - (mn + mx);
	return ns;
}


int main(){
	fast_io;
	
	int n;
	cin >> n;
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (int i=1; i<=n; i++){
		string g;
		cin >> g;
		for (int j=1; j<=n; j++) a[i][j] = g[j-1];
	}
	
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			for (int k=j+1; k<=n; k++) m[{{i, j}, k}] = -1;
			
	queue <ppi> q;
	q.push(srt({{s1, s2}, s3}));
	//ans[srt({{s1, s2}, s3})] = -1;
	//mp[srt({{s1, s2}, s3})] = -1;
	m[srt({{s1, s2}, s3})] = 0;
	
	while (q.size()){
		int v = q.front().F.F, u = q.front().F.S, s = q.front().S;
		q.pop();
		
		for (int i=1; i<=n; i++){
			if (i == v || i == u || i == s) continue;
			if (a[v][i] == a[u][s] && m[srt({{i, u}, s})] == -1) q.push(srt({{i, u}, s})), mp[srt({{i, u}, s})] = {{v, u}, s}, ans[srt({{i, u}, s})] = {v, i}, m[srt({{i, u}, s})] = m[{{v, u}, s}]+1;
		}
		
		for (int i=1; i<=n; i++){
			if (i == v || i == u || i == s) continue;
			if (a[u][i] == a[v][s] && m[srt({{i, v}, s})] == -1) q.push(srt({{i, v}, s})), mp[srt({{i, v}, s})] = {{v, u}, s}, ans[srt({{i, v}, s})] = {u, i}, m[srt({{i, v}, s})] = m[{{v, u}, s}]+1;
		}
		
		for (int i=1; i<=n; i++){
			if (i == v || i == u || i == s) continue;
			if (a[s][i] == a[u][v] && m[srt({{i, u}, v})] == -1) q.push(srt({{i, u}, v})), mp[srt({{i, u}, v})] = {{v, u}, s}, ans[srt({{i, u}, v})] = {s, i}, m[srt({{i, u}, v})] = m[{{v, u}, s}]+1; 
		}
	}
	if (m[{{1, 2}, 3}] == -1){
		cout << -1 << endl;
		return 0;
	}
	ppi d;
	d = {{1, 2}, 3};
	cout << m[{{1, 2}, 3}] << endl;
	while (m[srt(d)]  > 0){
		vec.pb(ans[srt(d)]);
		d = srt(mp[srt(d)]);
	}
	for (int i=vec.size()-1; i>=0; i--) cout << vec[i].F << sep << vec[i].S << endl;
	return 0;
}