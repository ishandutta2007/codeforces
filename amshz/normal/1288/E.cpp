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
 
const ll md = 1e9+7;
const int xn = 6e5 + 10;
const int xm = 5e5;
const int SQ = 750;
const int NSF = 3e5;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 

int n, m, a[xn], Min[xn], Max[xn], b[xn], c[xn], ps[xn], d[xn];
bool flag[xn];
vector <int> adj[xn], Add[sq][2];
 

void Update(int l, int r){
	vector <int> vec;
	for (int i = l; i <= r;){
		if (i % SQ == 0 && i + SQ - 1 <= r) vec.push_back(i / SQ), i += SQ;
		else c[i] += (b[i] >= r), i ++;
	}
	if (!vec.size()) return;
	int A = vec[0];
	int B = vec.back();
	Add[A][0].push_back(r);
	Add[B + 1][1].push_back(r);
} 

 
 
int main(){
	fast_io;
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) Min[i] = i;
	for (int i = 0; i < n; i ++) a[i] = n - i;
	for (int i = n; i < n + m; i ++) cin >> a[i], Min[a[i]] = 1;
	
	for (int i = 0; i < n + m; i ++) adj[a[i]].push_back(i);
	
	for (int i = 1; i <= n; i ++){
		for (int j = 0; j < adj[i].size(); j ++){
			if (j + 1 < adj[i].size()) b[adj[i][j]] = adj[i][j + 1] - 1;
			else b[adj[i][j]] = n + m - 1;
 		}
	}
	
	for (int i = 1; i <= n; i ++){
		for (int j = 0; j < adj[i].size(); j ++){
			int l = 0;
			if (j) l = adj[i][j - 1] + 1;
			int r = adj[i][j];
			Update(l, r);
		}
	}
	
	for (int i = 0; i < n + m; i += SQ){
		memset(ps, 0, sizeof ps);
		for (int j : Add[i / SQ][0]) flag[j] = true;
		for (int j : Add[i / SQ][1]) flag[j] = false;
		for (int j = 0; j < n + m; j ++) ps[j] = (flag[j]);
		for (int j = 1; j < n + m; j ++) ps[j] += ps[j - 1];
		for (int j = i; j < min(n + m, i + SQ); j ++){
			c[j] += ps[b[j]];
		}
	}
	
	for (int i = 1; i <= n; i ++){
		for (int j = 0; j < adj[i].size(); j ++){
			int ind = adj[i][j];
			int x = c[ind];
			Max[i] = max(Max[i], x);
		}
	}
	
	for (int i = 1; i <= n; i ++) cout << Min[i] << sep << Max[i] << endl;
	
	
	return 0;
}