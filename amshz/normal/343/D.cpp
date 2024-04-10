# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9+7;
const int xn = 5e5 + 10;
const int xm = 550;
const int SQ = 750;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n, Mx[xn], Max[xn], Start[xn], R[xn], S, qq, Time = 1, a[xn], b[xn];
bool Mark[xn];
vector <int> adj[xn];


void DFS(int v){
	Mark[v] = true;
	Start[v] = S ++;
	R[v] = Start[v];
	for (int u : adj[v]){
		if (Mark[u]) continue;
		DFS(u);
		R[v] = R[u];
	}
}


void Update1(int v){
	for (int i = Start[v]; i <= R[v];){
		if (i % SQ == 0 && i + SQ - 1 <= R[v]){
			Mx[i / SQ] = Time ++;
			i += SQ;
		}
		else{
			Max[i] = Time ++;
			i ++;
		}
	}
}
void Update2(int v){
	v = Start[v];
	a[v] = Time;
	b[v / SQ] = Time;
	Time ++;
}


void Get(int v){
	int mx = 0;
	for (int i = Start[v]; i <= R[v];){
		if (i % SQ == 0 && i + SQ - 1 <= R[v]){
			mx = max(mx, b[i / SQ]);
			i += SQ;
		}
		else{
			mx = max(mx, a[i]);
			i ++;
		}
	}
	v = Start[v];
	//cout << Max[v] << " : ";
	cout << (mx < (max(Mx[v / SQ], Max[v]))) << endl;
	return;
}

 
 
int main(){
	fast_io;
	
	cin >> n;
	for (int i = 0; i < n - 1; i ++){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	
	DFS(1);
	
	cin >> qq;
	while (qq --){
		int t, v;
		cin >> t >> v;
		if (t == 1) Update1(v);
		if (t == 2) Update2(v);
		if (t == 3) Get(v);
	}
	
	
	
	return 0;
}