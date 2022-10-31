# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e5 + 10;
const int xm = 1e5 + 10;
const int SQ = 320;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

ll n, m, k, x = 1, y = 1, ted = 1, Tot, l = 0, r = m + 1, u = 0, d = n + 1, cnt, go;
pii A[xn];
vector <int> adj[xn][2];
bool flag;

void find_Right(){
	int L = -1, R = adj[x][0].size(), Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (adj[x][0][Mid] <= y) L = Mid;
		else R = Mid;
	}
	int last = y;
	if (R < adj[x][0].size()) y = adj[x][0][R];
	else y = m + 1;
	y = min(y, r);
	y --;
	u = x;
	ted += y - last;
	if (y == last) flag = true;
}
void find_Left(){
	int L = -1, R = adj[x][0].size(), Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (adj[x][0][Mid] < y) L = Mid;
		else R = Mid;
	}
	int last = y;
	if (L > -1) y = adj[x][0][L];
	else y = 0;
	y = max(y, l);
	y ++;
	d = x;
	ted += last - y;
	if (y == last) flag = true;
}
void find_Down(){
	int L = -1, R = adj[y][1].size(), Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (adj[y][1][Mid] <= x) L = Mid;
		else R = Mid;
	}
	int last = x;
	if (R < adj[y][1].size()) x = adj[y][1][R];
	else x = n + 1;
	x = min(x, d);
	x --;
	r = y;
	ted += x - last;
	if (x == last) flag = true;
}
void find_Up(){
	int L = -1, R = adj[y][1].size(), Mid;
	while (R - L > 1){
		Mid = (L + R) / 2;
		if (adj[y][1][Mid] < x) L = Mid;
		else R = Mid;
	}
	int last = x;
	if (L > -1) x = adj[y][1][L];
	else x = 0;
	x = max(x, u);
	x ++;
	l = y;
	ted += last - x;
	if (x == last) flag = true;
}

int main(){
	//fast_io;
	
	cin >> n >> m >> k;
	r = m + 1;
	d = n + 1;
	for (int i = 0; i < k; i ++) cin >> A[i].F >> A[i].S;
	for (int i = 0; i < k; i ++){
		if (A[i].F == 1 && A[i].S == 2) go = 1;
		adj[A[i].F][0].push_back(A[i].S);
		adj[A[i].S][1].push_back(A[i].F);
	}
	if (m == 1) go = 1;
	for (int i = 0; i <= 1e5; i ++) sort(adj[i][0].begin(), adj[i][0].end()), sort(adj[i][1].begin(), adj[i][1].end());
	Tot = n * m - k;
	
	
	while (true){
		if (cnt || !go)find_Right();
		if (flag) break;
		find_Down();
		if (flag) break;
		find_Left();
		if (flag) break;
		find_Up();
		if (flag) break;
		cnt ++;
	}
	if (ted == Tot) cout << "Yes" << endl;
	else cout << "No" << endl;
		
	return 0;
}