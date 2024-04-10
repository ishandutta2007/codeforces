# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 3e3 + 10;
const int xm = 2e5 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, m, ans;
vector <pair <int, pii> > adj[xn];
vector <int> vec;
bool Mark[xn];

void DFS(int v, int L, int R){
	Mark[v] = true;
	for (pair <int, pii> u : adj[v]){
		if (!Mark[u.A] && u.B.A <= L && u.B.B >= R) DFS(u.A, L, R);
	}
}

bool check(int L, int R){
	memset(Mark, false, sizeof Mark);
	DFS(1, L, R);
	return Mark[n];
}

void Solve(int l){
	int L = l - 1, R = 1e6 + 1, Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (check(l, Mid)) L = Mid;
		else R = Mid;
	}
	ans = max(ans, L - l + 1);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 0; i < m; i ++){
		int v, u, L, R;
		cin >> v >> u >> L >> R;
		adj[v].push_back({u, {L, R}});
		adj[u].push_back({v, {L, R}});
		vec.push_back(L);
	}
	for (int x : vec) Solve(x);
	
	if (ans == 0) cout << "Nice work, Dima!" << endl;
	else cout << ans << endl;
	
	return 0;
}